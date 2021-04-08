/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:46:26 by pallyson          #+#    #+#             */
/*   Updated: 2020/11/12 18:38:11 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (num == 0)
		return (0);
	while (((unsigned char)s1[i] != '\0') &&
			((unsigned char)s2[j] != '\0') && num > 1 &&
			(unsigned char)s1[i] == (unsigned char)s2[j])
	{
		i++;
		j++;
		num--;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
