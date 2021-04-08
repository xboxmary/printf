/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallyson <pallyson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:17:24 by pallyson          #+#    #+#             */
/*   Updated: 2021/01/26 15:13:00 by pallyson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_print
{
	char	minus;
	char 	zero;
	int		width;
	int		precision;
	char	type;
	int		len;
}				t_print;



int				ft_printf(const char *str, ...);
int				parcer(const char *str, t_print *list,va_list va);
int				ft_atoi(const char *str);
int				ft_isdigit(int ch);
void			ft_putchar(char c, t_print *list);
int 			ft_numlen(int number);
char			*ft_itoa(int n);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *str);
int 			ft_width(t_print *list, va_list va, const char *str);
int 			ft_precision(t_print *list, va_list va, const char *str);
int				processor(t_print  *list, va_list va, char str);
int	    		print_c(t_print *list, int c);
int 			print_d(t_print *list, int d);
int 			dzero(t_print *list, int d, int dp, int dk);
int 			dw(t_print *list, int d);
int				ft_putnbr_un(unsigned int n, int fd);
void			ft_putnbr(int d, t_print *list);
int 			print_u(t_print *list, unsigned int u);
int 			uzero(t_print *list, unsigned int u, int uw);
int 			uw(t_print *list, unsigned int u);
int 			ft_numlen_un(unsigned int number);
int				ft_numlen_x(unsigned int x);
int				ft_numlen_p(unsigned long int x);
int 			print_x(t_print *list, unsigned int x, char str);
int 			xzero(t_print *list, unsigned int x, int xw, char str);
int 			xw(t_print *list, unsigned int x);
int				xw_p(t_print *list, unsigned long int x, int f);
int 			ft_x_to16(unsigned int x, int fd, char str);
int 			print_p(t_print *list, unsigned long int p, char str);
int 			ft_p_to16(unsigned long int p, int fd, int i, char str);
int 			print_s(t_print *list, char *s);
int 			sminus(t_print *list, char *s);
int 			sw(t_print *list, char *s, int i);
int				swlarger (t_print *list, char *s, int i);
int    			print_perc(t_print *list);
int 			percm(t_print *list);
void			ft_putstr(char *s, t_print *list);

#endif
