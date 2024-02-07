# printf
Program name:     libftprintf.a
Turn in files:     Makefile, *.h, */*.h, *.c, */*.c
Makefile:          NAME, all, clean, fclean, re
External functs.:  malloc, free, write, va_start, va_arg, va_copy, va_end
Libft is authorized
Description: Write a library that contains ft_printf(), a function that will mimic the original printf().
You have to recode the printf() function from libc.

The prototype of ft_printf() is:
int ft_printf(const char *, ...);

Here are the requirements:
- Don’t implement the buffer management of the original printf().
- Your function has to handle the following conversions: cspdiuxX%
- Your function will be compared against the original printf().
- You must use the command ar to create your library.
- Using the libtool command is forbidden.

You have to implement the following conversions:
- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign.

## What i did and what i tried to do.

I rewrote ft_printf from scratch without using libft. I thought it would be a good excercise.
I tried to build a single function to handle pduxX but had to split it into two functions in the end.
Either hexadecimals or decimals where working correctly at a time.
After i was almost done i put all functions post specifier into ft_printf_print.c.
Then i made the header file and adjusted the Makefile (copied and edited from libft).
Originally there was no write fail check and it worked just fine but i wanted to handle that case aswell.
Some error checks feel like double checks but i know it is the way i wrote it.

Will try to come back to this after i gained more experience.
