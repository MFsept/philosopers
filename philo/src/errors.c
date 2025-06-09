/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:52:06 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/09 21:31:35 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_args(int ac, char **av)
{
    int i;
    int nb_arg;

    i = 1;
    if (ac < 5 || ac > 6)
    {
        printf("Wrong Arguments\n");
        printf("Expected : ./philo nb_philo ttdie tteat ttsleep (max_meals)\n");
        return (ERROR);
    }
    if (ac == 6)
        nb_arg = 5;
    else
        nb_arg = 4;
    while (i <= nb_arg)
    {
        if (!valid_input(av[i]))
            return (ERROR);
        i++;
    }
    return (SUCCESS);
}