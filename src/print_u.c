/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <pallyson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:57:15 by pallyson          #+#    #+#             */
/*   Updated: 2021/01/26 15:10:27 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int print_u(t_print *list, unsigned int u)
{
	if (list->precision == 0 && u == 0 && list->width == 0)
        return (1);
    if (list->zero == '0')
        uzero(list, u, list->width);
    else if (list->minus != '-')
	{
		uw(list, u);
		uzero(list, u, list->precision);
	}
    else if (list->precision > ft_numlen_un(u))
        uzero(list, u, list->precision);
    else if (list->zero != '0' && list->precision != 0)
    {
        ft_putnbr_un(u, 1);
        list->len += ft_numlen_un(u);
    }
	else if (list->precision == 0)
        uzero(list, u, list->precision);
    if (list->minus == '-')
        uw(list, u);
    return (1);
}

int uzero(t_print *list, unsigned int u, int uwidth)
{
    while (uwidth > ft_numlen_un(u))
    {
        ft_putchar('0', list);
        uwidth--;
    }
	if (list->precision == 0 && u == 0)
		return (1);
	else
    	ft_putnbr_un(u, 1);
    list->len += ft_numlen_un(u);
    return (1);
}

int uw(t_print *list, unsigned int u)
{
    int umax;

    if (list->precision > ft_numlen_un(u))
        umax = list->precision;
    else
        umax = ft_numlen_un(u);
    if (list->precision == 0 && u == 0)
        umax = 0;
    while(list->width > umax)
    {
        ft_putchar(' ', list);
        umax++;
    }
    return (1);
}

int	ft_putnbr_un(unsigned int n, int fd)
{
	char	a;
	int		i;

	i = 0;
	a = n % 10 + '0';
	if (n / 10 > 0)
	i += ft_putnbr_un(n / 10, fd);
	i += write(fd, &a, 1);
	return (i);
}
