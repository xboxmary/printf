/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:12:13 by pallyson          #+#    #+#             */
/*   Updated: 2020/11/12 12:26:09 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*a;
	char	*b;
	size_t	i;

	if (!dst && !src && dst == src)
		return (dst);
	a = (char *)dst;
	b = (char *)src;
	if (src < dst)
	{
		i = len;
		while (i-- > 0)
			a[i] = b[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			a[i] = b[i];
			i++;
		}
	}
	return (dst);
}
