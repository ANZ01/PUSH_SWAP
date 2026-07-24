# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/16 00:00:00 by marvin            #+#    #+#              #
#    Updated: 2026/07/22 15:55:12 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS		= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I. -I./libft
LIBFT		= libft/libft.a

SRCS		= main.c \
			  error.c \
			  parse.c \
			  parse_utils.c \
			  normalize.c \
			  stack.c \
			  stack_utils.c \
			  disorder.c \
			  ops_swap.c \
			  ops_push.c \
			  ops_rotate.c \
			  ops_reverse.c \
			  sort_simple.c \
			  sort_utils.c \
			  sort_small.c \
			  sort_medium.c \
			  sort_complex.c \
			  adaptive.c \
			  bench.c

BONUS_SRCS	= checker.c \
			  checker_ops.c \
			  error.c \
			  parse.c \
			  parse_utils.c \
			  normalize.c \
			  stack.c \
			  stack_utils.c \
			  disorder.c \
			  ops_swap.c \
			  ops_push.c \
			  ops_rotate.c \
			  ops_reverse.c \
			  sort_simple.c \
			  sort_utils.c \
			  sort_small.c \
			  sort_medium.c \
			  sort_complex.c \
			  adaptive.c \
			  bench.c

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all:		$(LIBFT) $(NAME)

$(LIBFT):
			$(MAKE) -C libft

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lm -o $(NAME)

bonus:		$(LIBFT) $(BONUS_OBJS)
			$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -lm -o $(BONUS)

%.o:		%.c
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
			$(MAKE) -C libft clean
			rm -f $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(MAKE) -C libft fclean
			rm -f $(NAME) $(BONUS)

re:			fclean all

.PHONY:		all bonus clean fclean re