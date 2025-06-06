/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:52:06 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/06 11:56:22 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_args(int ac)
{
    if (ac < 5 && ac > 6)
    {
        printf("Wrong Arguments\n");
        printf("Expected : ./philo nb_philo ttdie tteat ttsleep (max_meals)\n");
        return (ERROR);
    }
    if (ac == 6)
        //setup max_meals
    else
        //max_meals = -1

    return (SUCCESS);
}