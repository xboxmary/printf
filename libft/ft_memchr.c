/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:28:49 by pallyson          #+#    #+#             */
/*   Updated: 2020/11/12 13:30:17 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *a;
	unsigned char b;

	a = (unsigned char *)s;
	b = (unsigned char)c;
	while (n--)
	{
		if (*a == (unsigned char)c)
			return ((void *)a);
		a++;
	}
	return (NULL);
}
