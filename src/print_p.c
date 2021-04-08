/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <pallyson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:22:07 by pallyson          #+#    #+#             */
/*   Updated: 2021/01/26 11:54:45 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static int	wzero_p(t_print *list, unsigned long int x, char str, int f)
{
	if (f == 0)
    	ft_putstr("0x", list);
    while (list->width > ft_numlen_x(x) + 2)
    {
        ft_putchar('0', list);
        list->width --;
    }
    list->len += ft_p_to16(x, 1, list->len, str);
    return (1);
}

static int	pzero_p(t_print *list, unsigned long int x, char str, int f)
{
	if (f == 0)
    	ft_putstr("0x", list);
    while (list->precision > ft_numlen_x(x))
    {
        ft_putchar('0', list);
        list->precision--;
    }
    list->len += ft_p_to16(x, 1, list->len, str);
    return (1);
}

int print_p(t_print *list, unsigned long int x, char str)
{
	int l;
	int	f;

	f = 0;
	l = 2;
    if (list->zero == '0')
        wzero_p(list, x, str, f);
    else if (list->width != 0 && list->minus != '-')
        f = xw_p(list, x, f);
    if (list->precision == 0 && x == 0 && list->width == 0)
	{
		ft_putstr("0x", list);
		return (1);
	}
    else if (list->precision > ft_numlen_x(x))
        pzero_p(list, x, str, f);
    else if (list->zero != '0' && list->precision != 0)
    {
		if (f == 0)
        {
			f = 1;
			ft_putstr("0x", list);
		}
        list->len += ft_p_to16(x, 1, l, str);
    }
    if (list->minus == '-')
        xw_p(list, x, f);
    return (1);
}


int xw_p(t_print *list, unsigned long int x, int f)
{
    int xmax;

	xmax = 2;
    if (list->precision > ft_numlen_p(x))
        xmax += list->precision;
    else
        xmax += ft_numlen_p(x);
    if (list->precision == 0 && x == 0)
        xmax = 2;
    while(list->width > xmax)
    {
        ft_putchar(' ', list);
        xmax++;
    }
	if (f == 0)
    	ft_putstr("0x", list);
    return (1);
}

int ft_p_to16(unsigned long int p, int fd, int i, char str)
{
    int d;
    char p1;

    i = 0;
    d = p % 16;
   	p1 = (d > 9) ? (d % 10 + 'a') : (d + '0');
	if (p / 16 > 0)
        i += ft_p_to16(p / 16, fd, i, str);
	i += write(fd, &p1, 1);
    return (i);
}
