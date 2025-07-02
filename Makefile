# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 12:07:49 by taewonki          #+#    #+#              #
#    Updated: 2025/07/01 12:17:37 by taewonki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude

SRCDIR = src
INCDIR = include
FT_PRINTF_DIR = ft_printf

NAME = push_swap
SRC = $(SRCDIR)/check.c $(SRCDIR)/free_exit.c $(SRCDIR)/ft_split.c \
		$(SRCDIR)/init.c $(SRCDIR)/list_func.c $(SRCDIR)/push_swap.c \
		$(SRCDIR)/rules.c $(SRCDIR)/rules_util.c $(SRCDIR)/rules1.c \
		$(SRCDIR)/sort_algo.c $(SRCDIR)/utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ) -L$(FT_PRINTF_DIR) -lprintf -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(FT_PRINTF_DIR);

re : fclean all

.PHONY: all clean fclean re
