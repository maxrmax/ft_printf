# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 12:40:14 by mring             #+#    #+#              #
#    Updated: 2024/02/01 14:13:09 by mring            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c

OBJECTS	= ${SRCS:.c=.o}

INCLUDES	= INCLUDES

CFLAGS	= -Wall -Wextra -Werror -I INCLUDES

LIBFT_DIR	= ./libft

LIBFT	= ${LIBFT_DIR}/libft.a

%.o: %.c $(HEADERS) $(LIBFT) Makefile
	$(CC) -c ${CFLAGS} -o $@ $<

${NAME}: ${OBJECTS} ${LIBFT}
	cp $(LIBFT) $(NAME)
	ar rc ${NAME} ${OBJECTS}
	ranlib ${NAME}

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

all: ${NAME}

clean:
	make -C $(LIBFT_DIR) clean
	rm -f ${OBJECTS}
	make clean -C $(LIBFT_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f ${NAME}

re: fclean all

libft: $(LIBFT)

.PHONY:		all clean fclean re
