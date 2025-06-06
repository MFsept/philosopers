/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 02:23:24 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/06 16:57:27 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ERROR 1
# define SUCCESS 0
# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647

# include <errno.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum s_thread
{
	CREATE,
	DETACH,
	JOIN
}					t_thread;

typedef enum s_mutex
{
	INIT,
	DESTROY,
	LOCK,
	UNLOCK
}					t_mutex;

typedef struct s_philo
{
	int				id;
	long			nb_meals;
	int				full;
	long			time_since_eat;
	t_mutex_info	*left_fork;
	t_mutex_info	*right_fork;
	struct s_info	*info;
}					t_philo;

typedef struct s_info
{
	long			nb_philo;
	long			ttd;
	long			tte;
	long			tts;
	long			max_meals;
	int				end;
	t_mutex_info	fork[200];
	t_philo			philo[200];
}					t_info;

typedef struct s_mutex_info
{
	pthread_mutex_t	fork;
	int				print_safe;

}					t_mutex_info;

// ERRORS
int					check_args(t_info *info, int ac, char **av);

// UTILS
long				ft_atol(const char *s);

// INIT_ARGS
void				init_args(t_info *info, char **av);
void				init_info(t_info *info);
void				init_philo(t_info *info);
void				init_forks(t_info *info, t_philo *philo, int i);

// handle_MUTEX
void				safe_handle_mutex(t_mutex_info *mtx, t_mutex code);

// HANDE_THREAD
void				safe_handle_thread(t_mutex_info *mtx, void *(*foo)(void *),
						void *data, t_thread code);
#endif

// start process -> philo pair usleep1000
// start eating -> philo pair usleep500
// start thinking -> philo pair usleep100
// choisir pair ou impair juste pour empehcer que les threads qui suit rattrape le process en cours eteviter les deadlock