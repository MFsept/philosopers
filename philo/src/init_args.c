/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:35:18 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/06 16:56:34 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(t_info *info, char **av)
{
	info->nb_philo = ft_atol(av[1]);
	info->ttd = ft_atol(av[2]) * 1e3;
	info->tte = ft_atol(av[3]) * 1e3;
	info->ttd = ft_atol(av[4]) * 1e3;
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
    init_philo(info);
}
void	init_philo(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->nb_philo)
	{
		info->philo->id = i + 1;
		info->philo->full = FALSE;
		info->philo->nb_meals = 0;
        info->philo[i].time_since_eat = 0;
        info->philo[i].info = info;
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