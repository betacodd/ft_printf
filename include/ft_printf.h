/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:05:58 by elevy             #+#    #+#             */
/*   Updated: 2022/12/24 14:27:51 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_flags(va_list ap, char c);
int	ft_majhexa(unsigned int arg);
int	ft_minhexa(unsigned int arg);
int	ft_putchar(int c);
int	ft_putnbr(int nb);
int	ft_putnbr_uns(unsigned int nb);
int	ft_putstr(char *str);
int	ft_voidhexa(unsigned long long addr);
int	arg_size(unsigned long arg);

#endif
