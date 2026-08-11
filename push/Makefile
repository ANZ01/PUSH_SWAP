# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/11 02:17:05 by dmaurici          #+#    #+#              #
#    Updated: 2026/08/11 02:22:47 by dmaurici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I. -I./libft
LIBFT		= libft/libft.a

SRCS		= main.c \
			  error.c \
			  stack_alloc.c \
			  stack_core.c \
			  parse.c \
			  parse_utils.c \
			  rank_values.c \
			  measure_disorder.c \
			  op_swap.c \
			  op_push.c \
			  op_rotate.c \
			  op_reverse.c \
			  op_print.c \
			  sort_simple.c \
			  sort_helpers.c \
			  sort_small.c \
			  sort_medium.c \
			  sort_complex.c \
			  sort_adaptive.c \
			  bench_print.c

OBJS		= $(SRCS:.c=.o)

all:		$(LIBFT) $(NAME)

$(LIBFT):
			$(MAKE) -C libft

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lm -o $(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
			$(MAKE) -C libft clean
			rm -f $(OBJS)

fclean:		clean
			$(MAKE) -C libft fclean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
