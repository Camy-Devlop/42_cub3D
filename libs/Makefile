# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/21 02:44:58 by alephoen          #+#    #+#              #
#    Updated: 2025/12/21 03:08:36 by alephoen         ###   ########.fr        #
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

LIBFT_DIR := libft
GNL_DIR   := gnl

LIBFT := libs_so/LIBFT/libft.a
GNL   := libs_so/GNL/gnl.a

CC := cc
CFLAGS := -g3 -O0 -Werror -Wall -Wextra

.PHONY: all clean fclean re objs_dir build_libf build_gnl install

all: libso_dir build_libf build_gnl

libso_dir:
	@mkdir -p $(abspath libs_so)

build_libf:
	@echo "$(ROCKET_ICON) $(BOLD)Calling Makefile $(RESET)$(MAGENTA)libft$(NAME)$(RESET)..."
	@$(MAKE) -C $(LIBFT_DIR) $(NAME)

build_gnl:
	@echo "$(ROCKET_ICON) $(BOLD)Calling Makefile $(RESET)$(MAGENTA)GNL$(NAME)$(RESET)..."
	@$(MAKE) -C $(GNL_DIR) $(NAME)

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
