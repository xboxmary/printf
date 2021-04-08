/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:19:11 by pallyson          #+#    #+#             */
/*   Updated: 2020/11/16 13:10:49 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	len = 0;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (s1[len] != '\0')
		len++;
    len--;
	while (s1[len] && ft_strchr(set, s1[len] && len >= 0))
		len--;
	str = ft_substr((char *)s1, 0, len + 1);
	return (str);
}
