/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:38:04 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/06 15:31:51 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void handle_mutex_error(int status, t_mutex code)
{
    if (status == 0)
        return ;
    if (status == EINVAL && (code == LOCK || code == UNLOCK))
        return(printf("Invalid mutex value\n"));
    else if (status == EINVAL && code == INIT)
        return(printf("Invalid attr value\n"));
    else if (status == EDEADLK)
        return(printf("A deadlock occur\n"));
    else if (status == EPERM)
        return(printf("There is no lock\n"));
    else if (status == EBUSY)
        return(printf("The mutex is already locked\n"));
    else
        printf("Unknown mutex error");
}

void	safe_handle_mutex(t_mutex_info *mtx, t_mutex code)
{
	if (code == INIT)
		handle_mutex_error(pthread_mutex_init(mtx, NULL), code);
	else if (code == LOCK)
		handle_mutex_error(pthread_mutex_lock(mtx), code);
	else if (code == UNLOCK)
		handle_mutex_error(pthread_mutex_unlock(mtx), code);
	else if (code == DESTROY)
		handle_mutex_error(pthread_mutex_destroy(mtx), code);
}