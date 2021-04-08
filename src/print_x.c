/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <pallyson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:56:51 by pallyson          #+#    #+#             */
/*   Updated: 2021/01/26 15:12:13 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int print_x(t_print *list, unsigned int x, char str)
{
	if (list->precision == 0 && x == 0 && list->width == 0)
        return (1);
    if (list->zero == '0')
        xzero(list, x, list->width, str);
    else if (list->minus != '-')
    {
	    xw(list, x);
		xzero(list, x, list->precision, str);
	}
    else if (list->precision > ft_numlen_x(x))
        xzero(list, x, list->precision, str);
    else if (list->zero != '0' && list->precision != 0)
          list->len += ft_x_to16(x, 1, str);
	else if (list->precision == 0)
        xzero(list, x, list->precision, str);
    if (list->minus == '-')
        xw(list, x);
    return (1);
}

int xzero(t_print *list, unsigned int x, int xw, char str)
{
    while (xw > ft_numlen_x(x))
    {
        ft_putchar('0', list);
        xw--;
    }
	if (list->precision == 0 && x == 0)
		return (1);
	else
   		list->len += ft_x_to16(x, 1, str);
    return (1);
}

int xw(t_print *list, unsigned int x)
{
    int xmax;

    if (list->precision > ft_numlen_x(x))
        xmax = list->precision;
    else
        xmax = ft_numlen_x(x);
    if (list->precision == 0 && x == 0)
        xmax = 0;
    while(list->width > xmax)
    {
        ft_putchar(' ', list);
        xmax++;
    }
    return (1);
}

int ft_x_to16(unsigned int x, int fd, char str)
{
    int		d;
    char 	p;
	int		i;

    i = 0;
    d = x % 16;
	if (str == 'x')
   		p = (d > 9) ? (d % 10 + 'a') : (d + '0');
	if (str == 'X')
		p = (d > 9) ? (d % 10 + 'A') : (d + '0');
	if (x / 16 > 0)
    	i += ft_x_to16(x / 16, fd, str);
	i += write(fd, &p, 1);
    return (i);
}
