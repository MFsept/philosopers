/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:09:15 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/10 14:49:02 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_is_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

static int	ft_is_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 9 && s[i] <= 13)
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

char	*valid_input(char *s)
{
	int		len;
	char	*valid_nb;
	int		i;

	i = 0;
	len = 0;
	while (ft_is_space(s))
		i++;
	if (s[i] == '+')
		i++;
	else if (*s == '-')
		return (printf("The number must be positive\n"), NULL);
	else if (!ft_is_digit(s))
		return (printf("Only digit characters are accepted\n"), NULL);
	valid_nb = s + i;
	while ((s[i] >= '0' && s[i++] <= '9'))
		len++;
	if (len > 10)
		return (printf("The number is bigger than INT_MAX\n"), NULL);
	return (valid_nb);
}

long	ft_atol(char *s)
{
	long	result;

	result = 0;
	if (!valid_input(s))
		return (0);
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - 48);
	if (result > INT_MAX)
		return (printf("The number is not an integer\n"), 0);
	return (result);
}

int	ttk(t_philo *philo)
{
	int	time_to_think;
	int	temp;

	time_to_think = (philo->info->ttd);
	temp = ((get_time_ms() - philo->last_meal) + philo->info->tte);
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
