# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/21 02:44:58 by alephoen          #+#    #+#              #
#    Updated: 2025/12/21 04:42:29 by alephoen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN	:= \033[0;32m
RED		:= \033[0;31m
YELLOW	:= \033[0;33m
BLUE	:= \033[0;34m
CYAN	:= \033[0;36m
MAGENTA := \033[0;35m
BOLD	:= \033[1m
RESET	:= \033[0m

# Icons
ROCKET_ICON		:= 🚀
COMPILE_ICON	:= 🛠️
LINK_ICON		:= 📦
CLEAN_ICON		:= 🧹
SUCCESS_ICON	:= ✅
ERROR_ICON		:= ❌

LIBS_DIR := libs
LIBFT_DIR := libft
GNL_DIR   := gnl

LIBFT := libs_so/LIBFT/libft.a
GNL   := libs_so/GNL/gnl.a

CC := cc
CFLAGS := -g3 -O0 -Werror -Wall -Wextra

.PHONY: all clean fclean re objs_dir build_libf build_gnl build_mlx install

all: libso_dir build_libf build_gnl build_mlx

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
# MINILIBX_DIR	:= $(LIBS_DIR)/minilibx/minilibx-linux/
	MINILIBX_DIR	:= $(abspath minilibx/minilibx-linux)
	#MINILIBX		:= $(MINILIBX_DIR)libmlx.a
	MINILIBXCC		:= -I$(MINILIBX_DIR) -L $(MINILIBX_DIR) -lmlx
	MINI_LBX_LIBS	:= -lXext -lX11 -lm
else ifeq ($(UNAME_S),Darwin)
# MINILIBX_DIR	:= $(LIBS_DIR)/minilibx/minilibx_macos/
	MINILIBX_DIR	:= $(abspath minilibx/minilibx_macos)
	#MINILIBX		:= $(MINILIBX_DIR)libmlx.a
	MINILIBXCC		:= -I$(MINILIBX_DIR) -L $(MINILIBX_DIR) -lmlx
	MINI_LBX_LIBS	:= -framework OpenGL -framework AppKit
endif

libso_dir:
	@mkdir -p $(abspath libs_so)

build_libf:
	@echo "$(ROCKET_ICON) $(BOLD)Calling Makefile $(RESET)$(MAGENTA)libft$(NAME)$(RESET)..."
	@$(MAKE) -C $(LIBFT_DIR) $(NAME)

build_gnl:
	@echo "$(ROCKET_ICON) $(BOLD)Calling Makefile $(RESET)$(MAGENTA)GNL$(NAME)$(RESET)..."
	@$(MAKE) -C $(GNL_DIR) $(NAME)

build_mlx:
	@echo "$(ROCKET_ICON) $(BOLD)Calling Makefile $(RESET)$(MAGENTA)MLX$(NAME)$(RESET)..."
	@$(MAKE) -C $(MINILIBX_DIR)
# @echo $(abspath minilibx/minilibx-linux)
# @$(MAKE) -C $(LIB_DIR)/$(abspath minilibx/minilibx-linux)

install:
	@$(MAKE) -C $(LIBFT_DIR) install_incs
	@$(MAKE) -C $(GNL_DIR) install_incs

echo_clean:
	@echo "$(CLEAN_ICON) $(BLUE)Cleaning object files for all libraries...$(RESET)"

clean: echo_clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean

fclean:
	@echo "$(CLEAN_ICON) $(BLUE)Cleaning Static Libraries.a:$(RESET) $(RED)$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean

re: fclean all
