/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:57:57 by pallyson          #+#    #+#             */
/*   Updated: 2020/11/13 17:20:58 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*a;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	a = (char*)malloc(sizeof(char) * i);
	if (a == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		a[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		a[i++] = s2[j++];
	a[i] = '\0';
	return (a);
}
