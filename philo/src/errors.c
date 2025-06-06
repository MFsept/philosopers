/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:52:06 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/06 13:19:28 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_args(t_info *info, int ac, char **av)
{
    if (ac < 5 || ac > 6)
    {
        printf("Wrong Arguments\n");
        printf("Expected : ./philo nb_philo ttdie tteat ttsleep (max_meals)\n");
        return (ERROR);
    }
    init_args(info, av);      
    return (SUCCESS);
}