/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:35:18 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/07 15:34:57 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(t_info *info, char **av)
{
	info->nb_philo = ft_atol(av[1]);
	info->ttd = ft_atol(av[2]) * 1000;
	info->tte = ft_atol(av[3]) * 1000;
	info->tts = ft_atol(av[4]) * 1000;
	if (av[5])
		info->max_meals = ft_atol(av[5]);
	else
		info->max_meals = -1;
}

void	init_info(t_info *info)
{
	int	i;

	i = -1;
	info->end = FALSE;
	while (++i < info->nb_philo)
		safe_handle_mutex(&info->fork[i], INIT);
	safe_handle_mutex(&info->print_mutex, INIT); 
    init_philo(info);
}
void	init_philo(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->nb_philo)
	{
		info->philo[i].id = i + 1;
		info->philo[i].full = FALSE;
		info->philo[i].nb_meals = 0;
        info->philo[i].time_since_eat = 0;
        info->philo[i].info = info;
		info->philo[i].last_meal = info->start_time;
		init_forks(info, &info->philo[i], i);
	}
}

void	init_forks(t_info *info, t_philo *philo, int i)
{
	if (philo->id % 2)
	{
		philo->left_fork = &info->fork[i];
		philo->right_fork = &info->fork[(i + 1) % info->nb_philo];
	}
	else
	{
		philo->left_fork = &info->fork[(i + 1) % info->nb_philo];
		philo->right_fork = &info->fork[i];
	}
}