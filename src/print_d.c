/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <pallyson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:55:48 by pallyson          #+#    #+#             */
/*   Updated: 2021/01/26 14:43:25 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 # include "ft_printf.h"

int print_d(t_print *list, int d)
{
    if (list->precision == 0 && d == 0 && list->width == 0)
        return (1);
    if (list->zero == '0')
        dzero(list, d, list->width, 0);
    else if (list->minus != '-')
    {
        dw(list, d);
        dzero(list, d, list->precision, 1);
    }
    else if (list->precision > ft_numlen(d))
        dzero(list, d, list->precision, 1);
    else if (list->zero != '0' && list->precision != 0)
    {
		if (d < 0)
			list->len++;
        ft_putnbr(d, list);
    }
    else if (list->precision == 0)
        dzero(list, d, list->precision, 1);
    if (list->minus == '-')
        dw(list, d);
    return (1);
}

int dzero(t_print *list, int d, int dp, int dk)
{
    if (d < 0)
    {
        if (d != -2147483648)
        {
            d = d * -1;
            ft_putchar('-', list);
        if (dk == 0)
            dp--;
        }
        else
            list->len++;
    }
    while (dp > ft_numlen(d))
    {
        ft_putchar('0', list);
        dp--;
    }
    if (list->precision == 0 && d == 0)
        return (1);
    else
        ft_putnbr(d, list);
    return (1);
}

int dw(t_print *list, int d)
{
    int dmax;

    if (list->precision > ft_numlen(d))
        dmax = list->precision;
    else
        dmax = ft_numlen(d);
    if (list->precision == 0 && d == 0)
        dmax = 0;
    if (d < 0)
        dmax++;
    while(list->width > dmax)
    {
        ft_putchar(' ', list);
        dmax++;
    }
    return (1);
}
