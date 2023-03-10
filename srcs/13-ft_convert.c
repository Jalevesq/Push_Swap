/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13-ft_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:10:39 by jalevesq          #+#    #+#             */
/*   Updated: 2023/03/10 11:47:21 by jalevesq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

static int	error_number(int *error)
{
	*error = 1;
	return (0);
}

// atoi modified to check int_min and int_max
long	ft_atoi(const char *str, int *error)
{
	long int	i;
	long int	res;
	long int	sign;

	sign = 1;
	res = 0;
	i = 0;
	if (!str)
		return (error_number(error));
	if (ft_is_sign(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		if (ft_isdigit(str[i++ + 1]) == 0)
			return (error_number(error));
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if (sign * res < INT_MIN || sign * res > INT_MAX)
			return (error_number(error));
	}
	if (str[i])
		return (error_number(error));
	return (res * sign);
}
