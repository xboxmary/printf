/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <pallyson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:40:12 by pallyson          #+#    #+#             */
/*   Updated: 2021/01/26 14:17:27 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

void	ft_putchar(char c, t_print *list)
{
	list->len += write(1, &c, 1);
}

void	ft_putstr(char *s, t_print *list)
{
	ft_putstr_fd(s, 1);
   	list->len += ft_strlen(s);
}

void	ft_putnbr(int d, t_print *list)
{
	ft_putnbr_fd(d, 1);
    list->len += ft_numlen(d);
}