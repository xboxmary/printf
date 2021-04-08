/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_perc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <pallyson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:02:43 by pallyson          #+#    #+#             */
/*   Updated: 2021/01/24 18:33:14 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int    print_perc(t_print *list)
{
    if (list->minus == '-')
       percm(list);
	if (list->minus != '-' && list->zero != '0')
    {
        while (list->width > 1)
        {
			ft_putchar(' ', list);
			list->width--;
        }
		ft_putchar('%', list);
    }
    else if (list->minus != '-' && list->zero == '0')
    { 
        while (list->width > 1)
        {
            ft_putchar('0', list);
            list->width--;
        }
        ft_putchar('%', list);
    }
    return (1);
}

int percm(t_print *list)
{
	ft_putchar('%', list);
	while (list->width > 1)
	{
		ft_putchar(' ', list);
		list->width--;
    }
	return (1);
}