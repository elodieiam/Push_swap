/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:32:02 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/22 13:06:19 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_print_element(const char *s, va_list args);
int	ft_putaddr(unsigned long n);
int	ft_putchar_pf(char c);
int	ft_puthex(unsigned int n, const char c);
int	ft_putnbr_pf(int n);
int	ft_putstr_pf(char *s);
int	ft_putunbr(unsigned int n);

#endif