# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 17:47:48 by alephoen          #+#    #+#              #
#    Updated: 2025/12/12 22:59:27 by isadbaib         ###   ########.fr        #
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

CC := cc
CFLAGS := -g3 -O3 -Werror -Wall -Wextra

CFILES := \
ft_close_fd.c \
ft_strjoin.c \
ft_calloc.c \
ft_strchr.c \
ft_strlen_2.c \
ft_strlen3.c \
ft_split_n.c \
ft_split2_n.c \
ft_substr.c \
ft_strncmp.c \
ft_strlen.c \
ft_strtol.c \
ft_itoa.c \
ft_hex2int_fdf.c \
ft_int_round.c \
ft_free.c \
ft_free2dstr.c

GNL_CFILES := \
1_get_next_line.c \
2_get_next_line_utils1.c \
3_get_next_line_utils2.c \

CFILES_BONUS := \

SHARED_CFILES := \

#SHARED_OBJS := $(OBJS_PATH)/

SRCS_PATH := srcs
GNL_SRCS_PATH := gnl
OBJS_PATH := $(abspath ../../objs)

SRCS_PATH_BONUS := srcs_bonus

SRCS := $(addprefix $(SRCS_PATH)/,$(CFILES) $(SHARED_CFILES))
OBJS := $(patsubst $(SRCS_PATH)/%.c,$(OBJS_PATH)/%.o,$(SRCS))

GNL_SRCS := $(addprefix $(GNL_SRCS_PATH)/,$(GNL_CFILES))
GNL_OBJS := $(patsubst $(GNL_SRCS_PATH)/%.c,$(OBJS_PATH)/%.o,$(GNL_SRCS))

SRCS_SHARD := $(addprefix $(SRCS_PATH)/,$(SHARED_CFILES))
OBJS_SHARD := $(patsubst $(SRCS_PATH)/%.c,$(OBJS_PATH)/%.o,$(SRCS_SHARD))

SRCS_BONUS := $(addprefix $(SRCS_PATH_BONUS)/,$(CFILES_BONUS))
OBJS_BONUS := $(patsubst $(SRCS_PATH_BONUS)/%.c,$(OBJS_PATH)/%.o,$(SRCS_BONUS) $(OBJS_SHARD))

INCS_PATH := incs
INCS := -I$(INCS_PATH)

INCS_BONUS_PATH := incs_bonus
INCS_BONUS := -I$(INCS_BONUS_PATH)


all: objs_dir echo_build $(OBJS) $(GNL_OBJS)
# $(OBJS_PATH)

# bonus: objs_dir echo_build_bonus $(NAME_BONUS)

objs_dir:
	@mkdir -p $(OBJS_PATH)

echo_build:
	@echo "$(ROCKET_ICON) $(BOLD)Starting build $(RESET) $(MAGENTA)libft$(NAME)$(RESET)..."

# echo_build_bonus:
# 	@echo "$(ROCKET_ICON) $(BOLD)Starting build for$(RESET) $(MAGENTA)$(NAME_BONUS) (BONUS)$(RESET)..."

# $(NAME): echo_build $(OBJS)
# 	@echo "$(LINK_ICON) $(BOLD)Linking$(RESET) $(GREEN)$(NAME)$(RESET)"
# 	@$(CC) $(CFLAGS) $(INCS) $(OBJS) -o $(NAME)
# 	@echo "$(SUCCESS_ICON) $(GREEN)Build successful:$(RESET) $(BOLD)$(NAME)$(RESET)"

# $(NAME_BONUS): echo_build_bonus $(OBJS_BONUS)
# 	@echo "$(LINK_ICON) $(BOLD)Linking Bonus$(RESET) $(GREEN)$(NAME_BONUS)$(RESET)"
# 	@$(CC) $(CFLAGS) $(INCS_BONUS) $(OBJS_BONUS) -o $(NAME_BONUS)
# 	@echo "$(SUCCESS_ICON) $(GREEN)Build successful:$(RESET) $(BOLD)$(NAME_BONUS)$(RESET)"

# Rule to creat .o files for the Mandatory Part;
$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@echo "$(COMPILE_ICON) $(CYAN)Compiling$(RESET) $(YELLOW)$<$(RESET) → $(GREEN)$@$(RESET)"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@ || (echo "$(ERROR_ICON) $(RED)Compile failed: $<$(RESET)"; exit 1)

# Rule to creat .o files for the Mandatory Part;
$(OBJS_PATH)/%.o: $(GNL_SRCS_PATH)/%.c
	@echo "$(COMPILE_ICON) $(CYAN)Compiling$(RESET) $(YELLOW)$<$(RESET) → $(GREEN)$@$(RESET)"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@ || (echo "$(ERROR_ICON) $(RED)Compile failed: $<$(RESET)"; exit 1)

# Rule to creat .o files for the Bonus Part;
$(OBJS_PATH)/%.o: $(SRCS_PATH_BONUS)/%.c
	@echo "$(COMPILE_ICON) $(CYAN)Compiling Bonus$(RESET) $(YELLOW)$<$(RESET) → $(GREEN)$@$(RESET)"
	@$(CC) $(CFLAGS) $(INCS) $(INCS_BONUS) -c $< -o $@ || (echo "$(ERROR_ICON) $(RED)Compile failed: $<$(RESET)"; exit 1)

libs_a: $(OBJS_PATH)
	@ar rcs $@ $(OBJS_PATH)

clean:
	@echo "$(CLEAN_ICON) $(BLUE)Cleaning object files...$(RESET)"
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@echo "$(CLEAN_ICON) $(BLUE)Removing executable:$(RESET) $(RED)$(NAME)$(RESET)"
	@rm -f $(NAME)
	@echo "$(CLEAN_ICON) $(BLUE)Removing executable:$(RESET) $(RED)$(NAME_BONUS)$(RESET)"
	@rm -f $(NAME_BONUS)

re: fclean al
.PHONY: all bonus clean fclean re objs_dir echo_build echo_build_bonus

