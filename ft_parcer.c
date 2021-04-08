/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <pallyson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:38:22 by pallyson          #+#    #+#             */
/*   Updated: 2021/01/26 14:20:56 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int	parcer(const char *str, t_print *list, va_list va)
{
	int i;
		
	i = 0;
    while(str[i] == '0' || str[i] == '-')
    {
        if (str[i] == '0')
		{
            list->zero = '0';
			i++;
		}
        if (str[i] == '-')
		{
            list->minus = '-';
			i++;
		}
	}
	i += ft_width(list, va, &str[i]);
	i += ft_precision(list, va, &str[i]);
	if (list->minus == '-' || list->precision >= 0)
		list->zero = ' ';
	i += processor(list, va, str[i]);
	return(i);
}

int ft_width(t_print *list, va_list va, const char *str)
{
	int i;

	i = 0;
	if(*str == '*' )
	{
		list->width = va_arg(va, int);
		if (list->width < 0)
		{
			list->width = list->width * (-1);
			list->minus = '-';
		}
		i++;
	}
	else if (ft_isdigit(str[i]))
	{
		list->width = ft_atoi(str);
		i = ft_numlen(list->width);
	}
	return (i);
}

int ft_precision(t_print *list, va_list va, const char *str)
{
    int i;

    i = 0;
    if(*str == '.')
    {
		list->precision = 0;
        i++;
        if(str[i] == '*')
        {
            list->precision = va_arg(va, int);
			if (list->precision < 0)
				list->precision = -1;
            i++;
        }
        else if (ft_isdigit(str[i]))
        {
			while (str[i] == '0')
				i++;
            list->precision = ft_atoi(&str[i]);
			if (list->precision != 0)
            	i += ft_numlen(list->precision);
        }
        else 
            list->precision = 0;
	}
    return (i);
}
