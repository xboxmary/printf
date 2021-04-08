/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:15:57 by pallyson          #+#    #+#             */
/*   Updated: 2020/11/19 13:44:42 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *u;
	unsigned char *y;
	unsigned char a;

	u = (unsigned char *)dst;
	y = (unsigned char *)src;
	a = (unsigned char)c;
	while (n > 0)
	{
		*u = *y;
		if (*u == a)
		{
			u++;
			return (u);
		}
		u++;
		y++;
		n--;
	}
	return (0);
}
