/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:15:41 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/06 15:34:57 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	handle_thread_error(int status, t_mutex code)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		return (printf("Insufficient resources to create another thread\n"));
	else if (status == EPERM)
		return (printf("No permission\n"));
	else if (status == EINVAL && code == CREATE)
		return (printf("Invalid settings in attr\n"));
	else if (status == EINVAL && (code == JOIN || code == DETACH))
		return (printf("This thread is not a joinable thread\n"));
	else if (status == ESRCH)
		return (printf("No thread with the ID thread could be found\n"));
	else
		printf("Unknown thread error: %d\n", status);
}

void	safe_handle_thread(t_mutex_info *mtx, void *(*foo)(void *), void *data,
		t_thread code)
{
	if (code == CREATE)
		handle_thread_error(pthread_create(mtx, NULL, foo, data), code);
	else if (code == JOIN)
		handle_thread_error(pthread_join(mtx, NULL), code);
	else if (code == DETACH)
		handle_thread_error(pthread_detach(mtx), code);
	else
		printf("Unknown thread code\n");
}