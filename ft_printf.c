/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxrmax <maxrmax>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:18:20 by maxrmax           #+#    #+#             */
/*   Updated: 2025/11/07 15:55:24 by maxrmax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[count])
	{
		if (print_char(str[count]) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	print_number_base(long number, int base, int upper, int ptr)
{
	char	*symbols;
	int		count;

	count = 0;
	if (number < 0 && base == 10)
	{
		count += write(1, "-", 1);
		return (count += print_number_base(-number, base, upper, 0), count);
	}
	if (ptr == 1 && base == 16)
	{
		count += write(1, "0x", 2);
		if (count == -1)
			return (-1);
	}
	if (upper == 1)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if ((unsigned long)number < (unsigned long)base)
		return (count += print_char(symbols[number]));
	count += print_number_base(number / base, base, upper, 0);
	if (count == -1)
		return (-1);
	return (count += print_number_base(number % base, base, upper, 0));
}

int	parse_logic(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(args, int));
	else if (specifier == 's')
		count += print_str(va_arg(args, char *));
	else if (specifier == 'p')
		count += print_number_base(va_arg(args, unsigned long), 16, 0, 1);
	else if (specifier == 'd' || specifier == 'i')
		count += print_number_base(va_arg(args, int), 10, 0, 0);
	else if (specifier == 'u')
		count += print_number_base(va_arg(args, unsigned int), 10, 0, 0);
	else if (specifier == 'x')
		count += print_number_base(va_arg(args, unsigned int), 16, 0, 0);
	else if (specifier == 'X')
		count += print_number_base(va_arg(args, unsigned int), 16, 1, 0);
	else if (specifier == '%')
		count += print_char(specifier);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
			count += parse_logic(*(str++ + 1), args);
		else
			count += print_char(*str);
		if (count == -1)
		{
			va_end(args);
			return (-1);
		}
		str++;
	}
	va_end(args);
	return (count);
}

// #include <limits.h>
// #include <stdio.h>

// int main(void)
// {
// 	int count = 0;
// 	char *str = "string";
// 	count = printf("WELL: %c, %s, %p, %d, %i, %u, %x, %X, %%\n", 'Z', str, &str, INT_MIN, INT_MAX, 100, 69, 69);
// 	printf("%d\n", count);
// 	count = ft_printf("WELL: %c, %s, %p, %d, %i, %u, %x, %X, %%\n", 'Z', str, &str, INT_MIN, INT_MAX, 100, 69, 69);
// 	printf("%d\n", count);
// }