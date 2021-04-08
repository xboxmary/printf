/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <pallyson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:34:45 by pallyson          #+#    #+#             */
/*   Updated: 2021/01/24 17:09:26 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int    processor(t_print  *list, va_list va, char str)
{
    int i;

    i = 0;
    if (str == 'c')
        i = print_c(list, va_arg(va, int));
     if (str == 's')
        i = print_s(list, va_arg(va, char*));
     if (str == 'p')
        i = print_p(list, va_arg(va, unsigned long int), str);
    if (str == 'd' || str == 'i')
        i = print_d(list, va_arg(va, int));
    if (str == 'u')
        i = print_u(list, va_arg(va, unsigned int)); 
    if (str == 'x' || str == 'X')
        i = print_x(list, va_arg(va, unsigned int), str);
     if (str == '%')
        i = print_perc(list);
    return (i);
}