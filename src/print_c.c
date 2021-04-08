/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masha <masha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:00:51 by pallyson          #+#    #+#             */
/*   Updated: 2021/01/22 12:55:12 by masha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int    print_c(t_print *list, int c)
{
    if (list->minus == '-')
    {
        ft_putchar(c, list);
        while (list->width > 1)
        {
            ft_putchar(' ', list);
            list->width--;
        }
    }
     if (list->minus != '-')
    {
        
        while (list->width > 1)
        {
            ft_putchar(' ', list);
            list->width--;
        }
        ft_putchar(c, list);
    }
    return (1);
}