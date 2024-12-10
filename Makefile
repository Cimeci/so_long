# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 13:40:46 by marvin            #+#    #+#              #
#    Updated: 2024/11/09 13:40:46 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


########################
#        Color         #
########################

RED    = \033[1;31m
GREEN  = \033[1;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
CYAN   = \033[1;36m
PURPLE = \033[1;35m
RESET  = \033[0m

########################
#      MiniLibX        #
########################

MLX_DIR := lib/minilibx

########################
#       Params         #
########################

NAME = so_long
BONUS = so_long_bonus

CC = cc
CFLAGS := -Wall -Wextra -Werror -g -Ilib/minilibx

########################
#        Files         #
########################

PRINTF_FILES = lib/ft_printf/ft_pointer.c\
				lib/ft_printf/ft_put.c\
				lib/ft_printf/ft_printf_handle.c\
				lib/ft_printf/ft_printf.c\

GNL_FILES = lib/gnl/get_next_line.c \
        	lib/gnl/get_next_line_utils.c \

LIBFT_FILES = lib/ft_itoa.c\

SRC = ft_build_map.c\
	ft_check_map.c\
	ft_flood_fill.c\
	ft_display.c\
	ft_move_player.c\
	ft_clean.c\
	main.c\

SRC_BONUS = bonus/ft_build_map_bonus.c\
	bonus/ft_check_map_bonus.c\
	bonus/ft_flood_fill_bonus.c\
	bonus/ft_display_bonus.c\
	bonus/ft_move_player_bonus.c\
	bonus/ft_clean_bonus.c\
	bonus/ft_print_bonus.c\
	bonus/main_bonus.c\

########################
#       Object         #
########################

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJ_LIB = $(GNL_FILES:.c=.o) $(PRINTF_FILES:.c=.o) $(LIBFT_FILES:.c=.o)

########################
#     Assignment       #
########################

$(NAME): $(OBJ) $(OBJ_LIB)
	@if [ ! -f $(MLX_DIR)/libmlx.a ]; then \
		make --no-print-directory -C $(MLX_DIR);\
	fi

	@export LD_LIBRARY_PATH=$(MLX_DIR):$$LD_LIBRARY_PATH

	@$(CC) $(OBJ) $(OBJ_LIB) -L$(MLX_DIR) -lmlx -lm -lX11 -lXext -o $(NAME)

	@echo "$(PURPLE)";
	@echo "  44444    44444       2222      22222   22   22    2222";
	@echo " 44   44  44   44       22      22   22  222  22   22  22";
	@echo " 4        44   44       22      22   22  2222 22  22";
	@echo "  44444   44   44       22      22   22  22 2222  22";
	@echo "      44  44   44       22   2  22   22  22  222  22  222";
	@echo " 44   44  44   44       22  22  22   22  22   22   22  22";
	@echo "  44444    44444       2222222   22222   22   22    22222";
	@echo "$(RESET)";

$(BONUS): $(OBJ_BONUS) $(OBJ_LIB)
	@if [ ! -f $(MLX_DIR)/libmlx.a ]; then \
		make --no-print-directory -C $(MLX_DIR); \
	fi
	@$(CC) $(OBJ_BONUS) $(OBJ_LIB) -L$(MLX_DIR) -lmlx -lm -lX11 -lXext -o $(NAME)

	@echo "$(CYAN)"
	@echo " ######    #####   ##   ##  ##   ##   #####"
	@echo "  ##  ##  ##   ##  ###  ##  ##   ##  ##   ##"
	@echo "  ##  ##  ##   ##  #### ##  ##   ##  #"
	@echo "  #####   ##   ##  ## ####  ##   ##   #####"
	@echo "  ##  ##  ##   ##  ##  ###  ##   ##       ##"
	@echo "  ##  ##  ##   ##  ##   ##  ##   ##  ##   ##"
	@echo " ######    #####   ##   ##   #####    #####"
	@echo "$(RESET)"

########################
#      Control         #
########################

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_LIB) $(OBJ_BONUS)
	@echo "$(YELLOW)clean$(RESET)";

fclean: clean
	@echo "$(RED)remove $(NAME)$(RESET)";
	@rm -f $(NAME)

re: fclean all
	@echo "$(NAME) restart"

bonus : $(BONUS)

.PHONY: all bonus clean fclean re
