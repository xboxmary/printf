/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:18:02 by pallyson          #+#    #+#             */
/*   Updated: 2020/10/31 19:50:45 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int b, size_t len)
{
	unsigned char *u;

	u = (unsigned char *)a;
	while (len > 0)
	{
		*u = b;
		u++;
		len--;
	}
	return (a);
}
