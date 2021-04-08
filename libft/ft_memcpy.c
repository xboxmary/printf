/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:31:34 by pallyson          #+#    #+#             */
/*   Updated: 2020/11/19 13:43:56 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *u;
	unsigned char *y;

	if (!src && !dst)
		return (NULL);
	u = (unsigned char *)dst;
	y = (unsigned char *)src;
	while (n > 0)
	{
		*u = *y;
		u++;
		y++;
		n--;
	}
	return (dst);
}
