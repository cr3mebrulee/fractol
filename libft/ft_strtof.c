/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:03:38 by taretiuk          #+#    #+#             */
/*   Updated: 2024/07/14 13:42:08 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	check_sign(const char **str, int *sign)
{
	if (**str == '-')
	{
		*sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
}

float	ft_strtof(const char *str)
{
	float	result;
	int		sign;
	float	decimal_multiplier;
	bool	decimal_found;

	result = 0.0f;
	sign = 1;
	decimal_multiplier = 0.1f;
	decimal_found = false;
	check_sign(&str, &sign);
	while (*str >= '0' && *str <= '9')
		result = result * 10.0f + (*(str++) - '0');
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			result = result + (*(str++) - '0') * decimal_multiplier;
			decimal_multiplier *= 0.1f;
		}
	}
	result = (float)sign * result;
	return (result);
}
