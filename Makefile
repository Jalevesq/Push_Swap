# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 08:36:48 by jalevesq          #+#    #+#              #
#    Updated: 2023/03/09 17:31:20 by jalevesq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INC_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = 01-push_swap.c \
	02-fill_stack.c \
	03-sort_big.c \
	04-sort_little.c \
	05-optimisation.c \
	06-checker.c \
	07-end.c \
	08-utils.c \
	09-do_push.c \
	10-do_reverse_rotate.c \
	11-do_rotate.c \
	12-do_swap.c \
	13-ft_convert.c \

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.c=%.o})

LIBFT_PATH = libft
LIBFT_LIB = ${LIBFT_PATH}/libft.a
LIBFT_INC = ${LIBFT_PATH}/includes

GREEN	= \033[32;1m
CYAN	= \033[36;1m
RED		= \033[0;31m
BOLD	= \033[1m
RESET	= \033[0m
MAGENTA	=\033[0;95m

all: ${LIBFT_LIB} ${NAME}

${LIBFT_LIB}:
	@make -C ${LIBFT_PATH}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${@D}
	@${CC} ${CFLAGS} -I ${INC_DIR} -I ${LIBFT_INC} -c $< -o $@
	@echo "$(GREEN)Compiling: $<$(RESET)$(MAGENTA)              [OK]$(RESET)"

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} -o ${NAME}
	@echo "$(GREEN)Compilation successfully completed."

clean:
	@make clean -C ${LIBFT_PATH}
	@${RM} ${OBJS_DIR}
	@echo "$(RED)$(BOLD)Cleaning successfully completed."

fclean:	clean
	@make fclean -C ${LIBFT_PATH}
	@${RM} ${NAME}

re: fclean all
	@echo "$(CYAN)Recompilation completed"

.PHONY: all clean fclean re
