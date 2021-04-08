/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:46:07 by pallyson          #+#    #+#             */
/*   Updated: 2020/11/13 14:55:25 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	strl;
	size_t	i;
	char	*u;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	strl = ft_strlen((char*)s);
	if (len >= (strl - start))
		u = (char*)malloc(sizeof(char) * (strl - start + 1));
	else
		u = (char*)malloc(sizeof(char) * (len + 1));
	if (!u)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		u[i] = s[start + i];
		i++;
	}
	u[i] = '\0';
	return (u);
}
