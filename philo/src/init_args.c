/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:35:18 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/06 12:45:01 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_full(t_info *info, char **av)
{
    info->nb_philo = ft_atol(av[1]);
    info->ttdie = ft_atol(av[2]) * 1e3;
    info->tteat = ft_atol(av[3]) * 1e3;
    ifo->ttdie = ft_atol(av[4]) * 1e3;
}

void    init_not_last(t_info *info, char **av)
{
    
}