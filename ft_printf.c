
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <pallyson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:49:48 by pallyson          #+#    #+#             */
/*   Updated: 2021/01/08 15:50:34 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static void ft_init(t_print *list)
{
	list->minus = '0';
 	list->zero = ' ';
 	list->width = 0;
 	list->precision = -1;
 	list->type = '0';
}

static int	ft_read_str(t_print *list, va_list va, const char *str, int i)
{
	while (str[i] != '\0')
	{
		if(str[i] == '%')
		{
			ft_init(list);
			i++;
			i += parcer(&str[i], list, va);
		}
		else
		{
			list->len += write(1, &str[i], 1);
			i++;
		}
	}
	return (i);
}

int     ft_printf(const char *str, ...)
{
	va_list va;
	t_print  *list;
	int i;

	i = 0; 
 	if (!(list = (t_print*)malloc(sizeof(t_print))))
 		return (-1);
 	list->len = 0;
	va_start(va, str);
	i = ft_read_str(list, va, str, i);
	va_end(va);
	i = list->len;
	free(list);
	return (i);
}

