/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:42:28 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/07 12:48:27 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	safe_printf(t_philo *philo, const char *msg)
{
    safe_handle_mutex(&philo->info->print_mutex, LOCK);
    printf("Philo %d %s\n", philo->id, msg);
    safe_handle_mutex(&philo->info->print_mutex, UNLOCK);
}