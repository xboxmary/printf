/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:28:24 by pallyson          #+#    #+#             */
/*   Updated: 2020/11/18 15:59:14 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**mem_free(char **str, int c)
{
	int i;

	i = 0;
	while (i < c)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int		ft_countwords(char const *str, char c)
{
	int word;

	word = 0;
	if (ft_strlen(str) == 0)
		return (1);
	if (c == '\0')
		return (2);
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str != c && *str)
			word++;
		while (*str != c && *str)
			str++;
	}
	return (word + 1);
}

static int		ft_countsymbols(char const *str, char c)
{
	int len;
	int symb;

	len = 0;
	symb = 0;
	while (str[len] == c && str[len])
		len++;
	while (str[len] != c && str[len])
	{
		symb++;
		len++;
	}
	return (symb);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**b;

	if (!s)
		return (NULL);
	if (!(b = (char**)malloc(sizeof(char*) * ft_countwords(s, c))))
		return (NULL);
	j = 0;
	while (*s == c && c != '\0')
		s++;
	while (*s)
	{
		if (!(b[j] = (char*)malloc(sizeof(char) * (ft_countsymbols(s, c) + 1))))
			return (mem_free(b, j));
		i = ft_strlcpy(b[j], s, ft_countsymbols(s, c) + 1);
		b[j][ft_countsymbols(s, c)] = '\0';
		j++;
		s += ft_countsymbols(s, c);
		while (*s == c && c != '\0')
			s++;
	}
	b[j] = NULL;
	return (b);
}
