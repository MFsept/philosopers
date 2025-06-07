/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:49:07 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/07 20:45:54 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_routine(void *arg)
{
    t_info *info = (t_info *)arg;
    int i;
    long    time_hungry;
    int philo_full;
    
    while(!info->end)
    {
        i = -1;
        philo_full = 0;
         while (++i < info->nb_philo)
        {
            time_hungry = get_time_ms() - info->philo[i].last_meal;
            if (time_hungry > info->ttd)
            {
                safe_printf(&info->philo[i], "died");
                info->end = TRUE;
                info->philo[i].is_dead = TRUE;
                return NULL;
            }
            if (info->max_meals > 0 && info->philo[i].nb_meals >= info->max_meals)
                philo_full++;
        }
        if (info->max_meals > 0 && philo_full == info->nb_philo)
        {
            info->end = TRUE;
            return (NULL);
        }
        else
            usleep(1000);
    }
    return(NULL);
}
