# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 10:16:09 by mring             #+#    #+#              #
#    Updated: 2024/11/05 13:04:32 by mring            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CFLAGS		= -Wall -Wextra -Werror

SRC			= ft_printf ft_printf_print
SRCS		= $(addsuffix .c, $(SRC))

OBJ_DIR		= obj
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

# LIBFT_PATH	=	./libft
# LIBFT		=	$(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o: %.c
				@$(CC) ${CFLAGS} -c $< -o $@

all: ${NAME}

# bonus: all

${NAME}: 		$(OBJ_DIR) $(OBJS)
			@ar rcs ${NAME} ${OBJS}
			@echo "/// $(NAME) compiled ///"

# ${NAME}: 		$(LIBFT) $(OBJ_DIR) $(OBJS)
# 			@cp	$(LIBFT) $(NAME)
# 			@ar rcs ${NAME} ${OBJS}
# 			@echo "/// $(NAME) compiled ///"

# $(LIBFT):
#				@make -C $(LIBFT_PATH) all

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

clean:
				@rm -rf ${OBJ_DIR}
				@echo "/// cleanin printf ///"

fclean: 		clean
				@rm -f ${NAME}
				@echo "/// fcleanin printf ///"
# fclean: 		clean
# 				@make -C $(LIBFT_PATH) fclean
# 				@rm -f ${NAME}
# 				@echo "/// fcleanin printf ///"

re: 			fclean all

.PHONY:			all clean fclean re #libft