# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 12:07:49 by taewonki          #+#    #+#              #
#    Updated: 2025/07/07 13:31:59 by taewonki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Werror -Wextra -Iinclude -Ift_printf

SRCDIR = src
INCDIR = include
FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

NAME = push_swap
SRC = $(SRCDIR)/check.c $(SRCDIR)/free_exit.c $(SRCDIR)/ft_split.c \
		$(SRCDIR)/greedy.c $(SRCDIR)/init.c $(SRCDIR)/list_func.c \
		$(SRCDIR)/push_swap.c $(SRCDIR)/quick_sort.c \
		$(SRCDIR)/rules.c $(SRCDIR)/rules_util.c $(SRCDIR)/rules1.c \
		$(SRCDIR)/sort_algo.c $(SRCDIR)/sort_stack.c $(SRCDIR)/utils.c \
		$(SRCDIR)/greedy1.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(FT_PRINTF_LIB) $(OBJ)
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(FT_PRINTF_DIR);

re : fclean all

.PHONY: all clean fclean re
