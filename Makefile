# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 12:07:49 by taewonki          #+#    #+#              #
#    Updated: 2025/07/09 11:41:43 by taewonki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes -I$(FT_PRINTF_DIR) -I$(FT_LIBFT_DIR) -I$(GNL_DIR)
CFLAGS_BONUS = $(CFLAGS)

SRC_DIR = src
BONUS_DIR = bonus
FT_LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
GNL_DIR = get_next_line

FT_LIBFT_LIB = $(FT_LIBFT_DIR)/libft.a
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
GNL_LIB = $(GNL_DIR)/libgnl.a

NAME = push_swap
NAME_BONUS = checker

SRC = $(SRC_DIR)/check.c $(SRC_DIR)/free_exit.c \
		$(SRC_DIR)/greedy.c $(SRC_DIR)/init.c $(SRC_DIR)/list_func.c \
		$(SRC_DIR)/quick_sort.c \
		$(SRC_DIR)/rules.c $(SRC_DIR)/rules_util.c $(SRC_DIR)/rules1.c \
		$(SRC_DIR)/sort_algo.c $(SRC_DIR)/sort_stack.c $(SRC_DIR)/utils.c \
		$(SRC_DIR)/greedy1.c

SRC_MAIN = $(SRC_DIR)/push_swap.c
SRC_BONUS = $(BONUS_DIR)/checker_bonus.c \

OBJ = $(SRC:.c=.o)
MAIN_OBJ = $(SRC_MAIN:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(FT_LIBFT_LIB) $(FT_PRINTF_LIB) $(MAIN_OBJ) $(OBJ)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJ) $(FT_LIBFT_LIB) $(FT_PRINTF_LIB) -o $(NAME)

$(NAME_BONUS): $(FT_LIBFT_LIB) $(FT_PRINTF_LIB) $(GNL_LIB) $(OBJ) $(OBJ_BONUS)
	$(CC) $(CFLAGS_BONUS) $(OBJ) $(OBJ_BONUS) -L$(GNL_DIR) -lgnl -L$(FT_PRINTF_DIR) -lftprintf -L$(FT_LIBFT_DIR) -lft -o $(NAME_BONUS)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_OBJ): $(SRC_DIR)/push_swap.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS_BONUS) -c $< -o $@

$(FT_LIBFT_LIB):
	$(MAKE) -C $(FT_LIBFT_DIR)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(GNL_LIB):
	$(MAKE) -C $(GNL_DIR)

clean:
	rm -f $(OBJ)
	rm -f $(MAIN_OBJ)
	rm -f $(OBJ_BONUS)
	$(MAKE) clean -C $(FT_LIBFT_DIR)
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	$(MAKE) clean -C $(GNL_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	$(MAKE) fclean -C $(FT_LIBFT_DIR)
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	$(MAKE) fclean -C $(GNL_DIR)

re : fclean all bonus

.PHONY: all clean fclean re bonus
