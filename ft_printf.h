/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxrmax <maxrmax>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:23:55 by maxrmax           #+#    #+#             */
/*   Updated: 2025/11/07 15:40:16 by maxrmax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	parse_logic(char specifier, va_list args);
int	print_number_base(long number, int base, int upper, int ptr);
int	print_str(char *str);
int	print_char(char c);

#endif