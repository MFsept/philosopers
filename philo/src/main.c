/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 02:23:28 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/08 13:16:36 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info		info;
	pthread_t	threads[200];
    pthread_t monitor;
    int i;

	if (check_args(ac, av))
		return (1);
    info.start_time = get_time_ms();
	init_args(&info, av);
	init_info(&info);
	i = -1;
	while (++i < info.nb_philo)
		safe_handle_thread(&threads[i], philo_routine, &info.philo[i], CREATE);
    safe_handle_thread(&monitor, monitor_routine, &info, CREATE);
	i = -1;
	while (++i < info.nb_philo)
		safe_handle_thread(&threads[i], NULL, NULL, JOIN);
    safe_handle_thread(&monitor, NULL, NULL, JOIN);
    i = -1;
    while (++i < info.nb_philo)
        safe_handle_mutex(&info.fork[i], DESTROY);
    safe_handle_mutex(&info.print_mutex, DESTROY);
    return (0);
}
