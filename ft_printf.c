/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:46:04 by mring             #+#    #+#             */
/*   Updated: 2024/02/01 16:15:21 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str)
	{
		print_char((int)*str);
		count++;
		str++;
	}
	return (count);
}

int	print_digit(unsigned long long number, int base, int hex, int ptr)
{
	char	*symbols;
	int		count;

	count = 0;
	if (ptr == 1)
	{
		count += write(1, "0x", 2);
	}
	if (hex == 1)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (number < 0)
	{
		write(1, "-", 1);
		return (print_digit(-number, base, hex, 0) + 1);
	}
	else if (number < base)
		return (count += print_char(symbols[number]));
	else
	{
		count += print_digit(number / base, base, hex, 0);
		return (count + print_digit(number % base, base, hex, 0));
	}
}

int	print_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(args, int));
	else if (specifier == 's')
		count += print_str(va_arg(args, char *));
	else if (specifier == 'p')
		count += print_digit(va_arg(args, uintptr_t), 16, 0, 1);
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit(va_arg(args, int), 10, 0, 0);
	else if (specifier == 'u')
		count += print_digit(va_arg(args, unsigned int), 10, 0, 0);
	else if (specifier == 'x')
		count += print_digit(va_arg(args, unsigned int), 16, 0, 0);
	else if (specifier == 'X')
		count += print_digit(va_arg(args, unsigned int), 16, 1, 0);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		result;
	int		i;

	va_start(args, str);
	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == '%')
			result += print_format(str[i++ + 1], args);
		else
			result += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (result);
}

int	main(void)
{
	int value = 42;
	void *ptr = &value;

	ft_printf("ft_printf\n");
	ft_printf("char: %c\n", 'c');
	ft_printf("string: %s \n", "string");
	ft_printf("pointer address: %p\n", (void *)-14523);
	ft_printf("decimal: %d\n", -420);
	ft_printf("int: %i\n", -220);
	ft_printf("unsigned int: %u\n", 33333333);
	ft_printf("hex: %x\n", 30);
	ft_printf("HEX: %X\n", 31);
	ft_printf("%%: %%\n\n");

	printf("printf\n");
	printf("char: %c\n", 'c');
	printf("string: %s \n", "string");
	printf("pointer address: %p\n", (void *)-14523);
	printf("decimal: %d\n", -420);
	printf("int: %i\n", -220);
	printf("unsigned int: %u\n", 33333333);
	printf("hex: %x\n", 30);
	printf("HEX: %X\n", 31);
	printf("%%: %%\n\n");
}
