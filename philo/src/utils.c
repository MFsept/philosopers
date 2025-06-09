/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:09:15 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/09 21:46:23 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline int	ft_is_digit(char c)
{
	return (c >= 48 && c <= 57);
}

static inline int	ft_is_space(char c)
{
	return (c >= 9 && c <= 13);
}

char	*valid_input(char *s)
{
	int		len;
	char	*valid_nb;
	int		i;

	i = 0;
	len = 0;
	while (ft_is_space(s[i]))
		i++;
	if (s[i] == '+')
		i++;
	else if (*s == '-')
		return (printf("%s : The number must be positive\n", s), NULL);
	else if (!ft_is_digit(s[i]))
		return (printf("%s : Only digit characters are accepted\n", s), NULL);
	valid_nb = s + i;
	while (ft_is_digit(s[i++]))
		len++;
	if (len > 10)
		return (printf("%s : The number is bigger than INT_MAX\n", s), NULL);
	return (valid_nb);
}

long	ft_atol(char *s)
{
	long	result;

	result = 0;
	if (!valid_input(s))
		return (0);
	while (ft_is_digit(*s))
		result = result * 10 + (*s++ - 48);
	if (result > INT_MAX)
		return (printf("%s : The number is not an integer\n", s), 0);
	return (result);
}
