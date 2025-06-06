/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 02:23:24 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/06 12:55:35 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#define ERROR 1
#define SUCCESS 0
#define TRUE 1
#define FALSE 0
#define INT_MAX 2147483647

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>

typedef struct S_info
{
    int nb_philo;
    int philo[200];
    int fork[200];
    int rank;
    int ttdie;
    int tteat;
    int ttsleep;
    int philo_state;
    int nb_meals;
    int max_meals; //last param and -1 if not precise
    int time_since_eat;
    int time;
    int id_fork;
    t_mutex *right_fork;
    t_mutex *left_fork;
    int start;
    int end;
}   t_info;

typedef struct s_mutex
{
    pthread_mutex_t fork;
    int print_safe;
    
}   t_mutex; 


//ERRORS
int check_args(t_info *info, int ac, char **av);

//UTILS
long	ft_atol(const char *s);

//INIT_ARGS
void    init_full(t_info *info, char **av);
void    init_not_last(t_info *info, char **av);
#endif

//start process -> philo pair usleep1000
//start eating -> philo pair usleep500
//start thinking -> philo pair usleep100
//choisir pair ou impair juste pour empehcer que les threads qui suit rattrape le process en cours eteviter les deadlock