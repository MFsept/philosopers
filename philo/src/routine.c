/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:21:46 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/07 23:11:32 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void smart_usleep(long duration, t_info *info)
{
    long start = get_time_ms();
    while (!info->end && (get_time_ms() - start < duration))
        usleep(duration * 1000);
}

static char *one_philo(t_philo *philo)
{
    safe_handle_mutex(philo->left_fork, LOCK);
    safe_printf(philo, "has taken a fork");
    usleep(philo->info->ttd);
    safe_handle_mutex(philo->left_fork, UNLOCK);
    return NULL;
}

void	*philo_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    if (philo->info->nb_philo == 1)
        return (one_philo(philo));
    while (!philo->info->end)
    {
        safe_handle_mutex(philo->left_fork, LOCK);
        safe_printf(philo, "has taken a fork");
        safe_handle_mutex(philo->right_fork, LOCK);
        safe_printf(philo, "has taken a fork");
        safe_printf(philo, "is eating");
        philo->last_meal = get_time_ms();
        philo->nb_meals++;
        if (philo->info->end && (get_time_ms() - philo->last_meal < philo->info->tte))
            break;
        smart_usleep(philo->info->tte, philo->info);
        safe_handle_mutex(philo->left_fork, UNLOCK);
        safe_handle_mutex(philo->right_fork, UNLOCK);
        safe_printf(philo, "is sleeping");
        if (philo->info->end && (get_time_ms() - philo->last_meal < philo->info->tts))
            break;
        smart_usleep(philo->info->tts, philo->info);
        safe_printf(philo, "is thinking");
    }
    return NULL;
}
