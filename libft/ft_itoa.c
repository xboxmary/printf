/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:16:29 by pallyson          #+#    #+#             */
/*   Updated: 2020/11/19 11:19:55 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	if_len(int n)
{
	int len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	if_minus(int n)
{
	int m;

	m = 1;
	if (n < 0)
		m = -1;
	return (m);
}

char		*ft_itoa(int n)
{
	int		m;
	int		len;
	char	*p;

	len = if_len(n);
	m = if_minus(n);
	if (m == -1)
		len++;
	if (!(p = ((char*)malloc(sizeof(char) * (len + 1)))))
		return (NULL);
	p[0] = '-';
	p[len] = '\0';
	if (n == 0)
	{
		p[1] = '\0';
		p[0] = '0';
		return (p);
	}
	while (n != 0)
	{
		p[len - 1] = ((n % 10) * m) + '0';
		n = n / 10;
		len--;
	}
	return (p);
}
