/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <pallyson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:51:59 by pallyson          #+#    #+#             */
/*   Updated: 2021/01/26 13:02:11 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static int	ft_smin(int a, int b)
{
    int smin;

    if (a > b)
        smin = b;
    else
        smin = a;
    return (smin);
}

static int	sp(t_print *list, char *s, int i, char c)
{
	if (c == '+')
	{
    	while (list->width > i)
    	{
			ft_putchar(list->zero, list);
			list->width--;
		}
		ft_putstr_fd(s, 1);
   		list->len += ft_strlen(s);
	}
	else
	{
		ft_putstr_fd(s, 1);
   		list->len += ft_strlen(s);
		while (list->width > i)
    	{
			ft_putchar(' ', list);
			list->width--;
		}
	}
    return (1);
}

static void  ft_nmin_perc(t_print *list, char *s, int i, int g)
{
    if (list->width <= g)
    {
		if (list->precision < i)
			while (list->precision-- > 0)
			{
				ft_putchar(*s, list);
				s++;
			}
		else
			ft_putstr(s, list);		
    }
    else
    {
        while (list->width-- > g)
			ft_putchar(' ', list);
		if (list->precision < i)
			while (list->precision-- > 0)
			{
				ft_putchar(*s, list);
				s++;
			}
		else
			ft_putstr(s, list);	
    }
}

static void	ft_min_perc(t_print *list, char *s, int i, int g)
{
    if (list->width <= g)
    {
        if (list->precision < i)
            while (list->precision-- > 0)
            {
                ft_putchar(*s, list);
                s++;
            }
        else
		    ft_putstr(s, list);
    }
    else
    {
		if (list->precision < i)
			while (list->precision-- > 0)
			{
				ft_putchar(*s, list);
				s++;
			}
		else
		    ft_putstr(s, list);
        while (list->width-- > g)
			ft_putchar(' ', list);	
    }
}

int			print_s(t_print *list, char *s)
{
    int i;

    if (!s)
        s = "(null)";
    i = ft_strlen(s);
    if (list->minus != '-')
    {
        if (list->width <= i && list->precision == -1)
            ft_putstr(s, list);
	    else if (list->precision == -1)
		    sp(list, s, i, '+');
        else
		    ft_nmin_perc(list, s, i, ft_smin(list->precision, i));
    }
	else
	{
		if (list->width <= i && list->precision == -1)
            ft_putstr(s, list);
		else if (list->precision == -1)
		    sp(list, s, i, '-');
		else
		    ft_min_perc(list, s, i, ft_smin(list->precision, i));
	}
    return (1);
}
