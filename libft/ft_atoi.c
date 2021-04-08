/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:50:00 by pallyson          #+#    #+#             */
/*   Updated: 2020/11/12 18:19:51 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
			c == '\r' || c == '\v' || c == '\f');
}

static	int	ft_maxmin(long long int res, const char *str, int i, int m)
{
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + m * (str[i] - '0');
		if ((res == LONG_MAX / 10 && str[i + 1] > '7' && str[i + 1] <= '9')
				|| (res > LONG_MAX / 10
					&& str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (-1);
		if ((res == LONG_MIN / 10 && str[i + 1] > '8' && str[i + 1] <= '9')
				|| (res < LONG_MIN / 10
					&& str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (0);
		i++;
	}
	return (res);
}

int			ft_atoi(const char *str)
{
	long long int	res;
	int				i;
	int				m;

	res = 0;
	i = 0;
	m = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = -1;
		i++;
	}
	res = ft_maxmin(res, str, i, m);
	return (res);
}
