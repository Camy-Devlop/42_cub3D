# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 17:47:48 by alephoen          #+#    #+#              #
#    Updated: 2025/12/08 20:02:21 by alephoen         ###   ########.fr        #
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

LIBS_SO_PATH := $(abspath ../libs_so/GNL)
NAME:= $(LIBS_SO_PATH)/gnl.a

CC := cc
CFLAGS := -g3 -O0 -Werror -Wall -Wextra

CFILES := \
1_get_next_line.c \
2_get_next_line_utils1.c \
3_get_next_line_utils2.c \

SRCS_PATH := srcs
OBJS_PATH := $(abspath objs)

SRCS := $(addprefix $(SRCS_PATH)/,$(CFILES) $(SHARED_CFILES))
OBJS := $(patsubst $(SRCS_PATH)/%.c,$(OBJS_PATH)/%.o,$(SRCS))

INCS_PATH := incs
INCS := -I$(INCS_PATH)

.PHONY: all bonus clean fclean re objs_dir echo_build

all: objs_dir libs_so_dir echo_build $(NAME)

objs_dir:
	@mkdir -p $(OBJS_PATH)

libs_so_dir:
	@mkdir -p $(LIBS_SO_PATH)

echo_build:
	@echo "$(ROCKET_ICON) $(BOLD)Starting build $(RESET) $(MAGENTA)GNL$(NAME)$(RESET)..."

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

# Rule to creat .o files for the Mandatory Part;
$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@echo "$(COMPILE_ICON) $(CYAN)Compiling$(RESET) $(YELLOW)$<$(RESET) → $(GREEN)$@$(RESET)"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@ || (echo "$(ERROR_ICON) $(RED)Compile failed: $<$(RESET)"; exit 1)

install_incs:
	cp -r incs/ $(LIBS_SO_PATH)/incs

clean:
	@echo "$(CLEAN_ICON) $(BLUE)Cleaning object files GNL...$(RESET)"
	@rm -f $(OBJS) $(OBJS_BONUS)
	@rm -rf $(LIBS_SO_PATH)

fclean: clean
	@echo "$(CLEAN_ICON) $(BLUE)Removing executable:$(RESET) $(RED)$(NAME)$(RESET)"
	@rm -f $(NAME)

re: fclean all
