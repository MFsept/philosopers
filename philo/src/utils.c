/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:09:15 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/12 16:41:32 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*valid_input(char *s)
{
    int		len;
    int		i;
	int		start;
	
	i = 0;
	len = 0;
	start = 0;

    while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
        i++;
    if (s[i] == '+')
        i++;
    else if (s[i] == '-')
        return (printf("The number must be positive\n"), NULL);
    if (!(s[i] >= '0' && s[i] <= '9'))
        return (printf("Only digit characters are accepted\n"), NULL);
    start = i;
    while (s[i] >= '0' && s[i] <= '9')
    {
        len++;
        i++;
    }
    while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
        i++;
    if (s[i] != '\0')
        return (printf("Only digit characters are accepted\n"), NULL);
    if (len > 10)
        return (printf("The number is bigger than INT_MAX\n"), NULL);
    return (s + start);
}

long	ft_atol(char *s)
{
    long	result = 0;
    char	*nb = valid_input(s);

    if (!nb)
        return (0);
    while (*nb >= '0' && *nb <= '9')
    {
        result = result * 10 + (*nb - '0');
        if (result > INT_MAX)
            return (printf("The number is not an integer\n"), -1);
        nb++;
    }
    return (result);
}


int	ttk(t_philo *philo)
{
	int	time_to_think;
	int	temp;

	time_to_think = (philo->info->ttd);
	pthread_mutex_lock(&philo->meal_mutex);
	temp = ((get_time_ms() - philo->last_meal) + philo->info->tte);
	pthread_mutex_unlock(&philo->meal_mutex);
	if (temp >= time_to_think)
		time_to_think = 0;
	else
	{
		time_to_think -= temp;
		time_to_think /= 2;
		if (time_to_think > 500)
			time_to_think = 150;
	}
	return (time_to_think);
}
