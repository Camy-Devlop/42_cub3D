# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/13 15:20:21 by alephoen          #+#    #+#              #
#    Updated: 2025/12/22 23:05:58 by isadbaib         ###   ########.fr        #
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

NAME := cub3D

CC := cc
CFLAGS := -g3 -O0 -Werror -Wall -Wextra -Wno-error=unused-function

FSAN   := -fsanitize=address,undefined

LIBS_DIR := libs

CFILES := cub3D.c \
		  check/ft_is_file.c

SRCS_PATH := srcs
OBJS_PATH := objs

SRCS := $(addprefix $(SRCS_PATH)/,$(CFILES) $(SHARED_CFILES))
OBJS := $(patsubst $(SRCS_PATH)/%.c,$(OBJS_PATH)/%.o,$(SRCS))

INCS_PATH 			:= incs
INCS_LIBFT 			:= libs/libft/incs
INCS_GNL 			:= libs/libft/gnl/incs
INCS := -I$(INCS_PATH) -I$(INCS_LIBFT) -I$(INCS_GNL)

LIBFT_PATH := libs/libft
LIBFT := $(LIBFT_PATH)/libft.a

LIBS := $(LIBFT)


all: objs_dir objs_dir_sous start_msg libft $(OBJS) $(NAME)

libft:
	@$(MAKE) -C $(LIBS_DIR)/libft all

objs_dir:
	@mkdir -p $(OBJS_PATH)

objs_dir_sous:
	@mkdir -p $(OBJS_PATH)/check

start_msg:
	@echo "$(ROCKET_ICON) $(BOLD)Starting build $(RESET) $(MAGENTA)$(NAME)$(RESET)..."

$(NAME): $(OBJS) $(LIBS)
	@echo "$(LINK_ICON) $(BOLD)Linking$(RESET) $(GREEN)$(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(INCS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(SUCCESS_ICON) $(GREEN)Build successful:$(RESET) $(BOLD)$(NAME)$(RESET)"

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@echo "ce qui a de dans srcs =$(SRCS)"
	@echo "$(COMPILE_ICON) $(CYAN)Compiling$(RESET) $(YELLOW)$<$(RESET) → $(GREEN)$@$(RESET)"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@ || (echo "$(ERROR_ICON) $(RED)Compile failed: $<$(RESET)"; exit 1)

clean:
	@echo "$(CLEAN_ICON) $(BLUE)Cleaning object files Cub3D...$(RESET)"
	@rm -f $(OBJS) $(OBJS_PATH)/*.o
	@$(MAKE) -C $(LIBS_DIR)/libft clean

fclean: clean
	@echo "$(CLEAN_ICON) $(BLUE)Removing executable:$(RESET) $(RED)$(NAME)$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBS_DIR)/libft fclean


re: fclean all

rere:
	@$(MAKE) re

fsn: CFLAGS += $(FSAN)
fsn: fclean $(NAME)
.PHONY: all bonus clean fclean re rere objs_dir start_msg make_libs libs_install fsn
