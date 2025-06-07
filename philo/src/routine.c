/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:21:46 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/07 15:37:05 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    while (!philo->info->end)
    {
        safe_handle_mutex(philo->left_fork, LOCK);
        safe_printf(philo, "has taken a fork");
        safe_handle_mutex(philo->right_fork, LOCK);
        safe_printf(philo, "has taken a fork");
        safe_printf(philo, "is eating");
        philo->last_meal = get_time_ms();
        philo->nb_meals++;
        usleep(philo->info->tte);

        safe_handle_mutex(philo->left_fork, UNLOCK);
        safe_handle_mutex(philo->right_fork, UNLOCK);

        safe_printf(philo, "is sleeping");
        usleep(philo->info->tts);

        safe_printf(philo, "is thinking");
    }
    return NULL;
}
