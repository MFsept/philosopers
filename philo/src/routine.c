/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:21:46 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/08 13:45:36 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	smart_usleep(long duration, t_info *info)
{
	long	start;
    int end;

	start = get_time_ms();
	while (1)
    {
        pthread_mutex_lock(&info->end_mutex);
        end = info->end;
        pthread_mutex_unlock(&info->end_mutex);
        if (end || (get_time_ms() - start >= duration))
            break;
        usleep(10);
    }
}

static char	*one_philo(t_philo *philo)
{
	safe_handle_mutex(philo->left_fork, LOCK);
	safe_printf(philo, "has taken a fork");
	usleep(philo->info->ttd);
	safe_handle_mutex(philo->left_fork, UNLOCK);
	return (NULL);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
    int end;

	philo = (t_philo *)arg;
	if (philo->info->nb_philo == 1)
		return (one_philo(philo));
	if (philo->id % 2 == 0)
		usleep(2000);
	 while (1)
    {
        pthread_mutex_lock(&philo->info->end_mutex);
        end = philo->info->end;
        pthread_mutex_unlock(&philo->info->end_mutex);
        if (end)
            break;
        
		safe_handle_mutex(philo->left_fork, LOCK);
		safe_printf(philo, "has taken a fork");
		safe_handle_mutex(philo->right_fork, LOCK);
		safe_printf(philo, "has taken a fork");
		safe_printf(philo, "is eating");
		pthread_mutex_lock(&philo->meal_mutex);
		philo->last_meal = get_time_ms();
		philo->nb_meals++;
		pthread_mutex_unlock(&philo->meal_mutex);
		if (philo->info->end && (get_time_ms()
				- philo->last_meal < philo->info->tte))
			break ;
		smart_usleep(philo->info->tte, philo->info);
		safe_handle_mutex(philo->left_fork, UNLOCK);
		safe_handle_mutex(philo->right_fork, UNLOCK);
		safe_printf(philo, "is sleeping");
		if (philo->info->end && (get_time_ms()
				- philo->last_meal < philo->info->tts))
			break ;
		smart_usleep(philo->info->tts, philo->info);
		safe_printf(philo, "is thinking");
	}
	return (NULL);
}
