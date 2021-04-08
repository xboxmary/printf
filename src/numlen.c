/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <pallyson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:28:20 by pallyson          #+#    #+#             */
/*   Updated: 2021/01/26 11:05:33 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int ft_numlen(int number) //функция, которая будет считать длину цифр в числе, нужно перескочить на конец цифр послеатоя
{
    int count;

	count = 0;
	if (number == 0)
		count = 1;
	while (number != 0)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

int ft_numlen_un(unsigned int number)
{
	int count;

	count = 0;
	if (number == 0)
		count = 1;
	while (number != 0)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

int	ft_numlen_x(unsigned int x)
{
	int		count;
    char	p;
	int		d;

	count = 0;
    d = x % 16;
   	p = (d > 9) ? (d % 10 + 'a') : (d + '0');
	x = x / 16;
	if (x > 0)
		count += ft_numlen_x(x);
	count++;
    return (count);
}

int	ft_numlen_p(unsigned long int x)
{
	int		count;
    char	p;
	int		d;

	count = 0;
    d = x % 16;
   	p = (d > 9) ? (d % 10 + 'a') : (d + '0');
	x = x / 16;
	if (x > 0)
		count += ft_numlen_x(x);
	count++;
    return (count);
}
