# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 17:47:48 by alephoen          #+#    #+#              #
#    Updated: 2025/09/12 23:32:43 by alephoen         ###   ########.fr        #
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

NAME := fdf

CC := cc
CFLAGS := -g3 -O3 -Werror -Wall -Wextra

CFILES := \

CFILES_BONUS := \

SHARED_CFILES := \
clear_backg.c \
draw_lin.c \
draw_map.c \
_fdf.c \
get_map_data.c \
get_map_width.c \
get_map_width_utils.c \
inits_1.c \
inits_2.c \
key_actions_1.c \
key_actions_2.c \
keys_event_handler.c \
load_map.c \
load_pnts.c \
_main.c \
mouse_event_handler.c \
parse_map_pnts.c \
parse_map_size.c \
skip_number.c \
perspectives_1.c \
perspectives_2.c \
rotation_control.c \
rotate.c \
set_new_color_scheme.c \
setup_colors.c \
update_map.c \
wire_map.c \
draw_menu_1.c \
draw_menu_2.c

LIBFT_CFILES := \
ft_close_fd.c \
ft_strjoin.c \
ft_calloc.c \
ft_strchr.c \
ft_strlen_2.c \
ft_strlen3.c \
ft_split2_n.c \
ft_split_n.c \
ft_substr.c \
ft_strtol.c \
ft_itoa.c \
ft_hex2int_fdf.c \
ft_strncmp.c \
ft_strlen.c \
ft_int_round.c \
ft_free.c \
ft_free2dstr.c \
1_get_next_line.c \
2_get_next_line_utils1.c \
3_get_next_line_utils2.c

# SHARED_OBJS := $(OBJS_PATH)/

LIBS := libs/

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MINILIBX_DIR	:= $(LIBS)minilibx/minilibx-linux/
	#MINILIBX		:= $(MINILIBX_DIR)libmlx.a
	MINILIBXCC		:= -I$(MINILIBX_DIR) -L $(MINILIBX_DIR) -lmlx
	MINI_LBX_LIBS	:= -lXext -lX11 -lm
else ifeq ($(UNAME_S),Darwin)
	MINILIBX_DIR	:= $(LIBS)minilibx/minilibx_macos/
	#MINILIBX		:= $(MINILIBX_DIR)libmlx.a
	MINILIBXCC		:= -I$(MINILIBX_DIR) -L $(MINILIBX_DIR) -lmlx
	MINI_LBX_LIBS	:= -framework OpenGL -framework AppKit
endif

SRCS_PATH := srcs
OBJS_PATH := objs
OBJS_BONUS_PATH := objs_bonus

SRCS_PATH_BONUS := srcs_bonus

SRCS := $(addprefix $(SRCS_PATH)/,$(CFILES) $(LIBFT_CFILES) $(SHARED_CFILES))
OBJS := $(patsubst $(SRCS_PATH)/%.c,$(OBJS_PATH)/%.o,$(SRCS))

SRCS_SHARD := $(addprefix $(SRCS_PATH)/,$(LIBFT_CFILES) $(SHARED_CFILES))
OBJS_SHARD := $(patsubst $(SRCS_PATH)/%.c,$(OBJS_PATH)/%.o,$(SRCS_SHARD))

SRCS_BONUS := $(addprefix $(SRCS_PATH_BONUS)/,$(CFILES_BONUS))
OBJS_BONUS := $(patsubst $(SRCS_PATH_BONUS)/%.c,$(OBJS_BONUS_PATH)/%.o,$(SRCS_BONUS) $(OBJS_SHARD))

INCS_PATH := incs
INCS := -I$(INCS_PATH) -I$(MINILIBX_DIR)

INCS_BONUS_PATH := incs_bonus
INCS_BONUS := -I$(INCS_BONUS_PATH)

.PHONY: all mklibs libft mini_libx bonus clean fclean re objs_dir echo_build echo_build_bonus print-pwd

all: objs_dir mklibs echo_build $(OBJS_PATH) $(NAME)

bonus: objs_bonus_dir libft $(OBJS_BONUS_PATH) $(NAME_BONUS)

objs_dir:
	@mkdir -p $(OBJS_PATH)

objs_bonus_dir:
	@mkdir -p $(OBJS_BONUS_PATH)

# Build all libs
mklibs: libft mini_libx
	@echo ""

# Build libft.a
libft:
	@echo "\nBuilding libft"
	@$(MAKE) -C $(LIB_DIR)$(abspath $(LIBS)libft)

# Build MiniLibx
mini_libx :
	@echo "\nBuilding MiniLibx"
	@$(MAKE) -C $(LIB_DIR)$(abspath $(LIBS)minilibx/minilibx-linux)

echo_build:
	@echo "$(ROCKET_ICON) $(BOLD)Starting build for$(RESET) $(MAGENTA)$(NAME)$(RESET)..."

echo_build_bonus:
	@echo "$(ROCKET_ICON) $(BOLD)Starting build for$(RESET) $(MAGENTA)$(NAME_BONUS) (BONUS)$(RESET)..."

$(NAME): $(OBJS)
	@echo "$(LINK_ICON) $(BOLD)Linking$(RESET) $(GREEN)$(NAME)$(RESET)"
# @ls $(MINILIBX_DIR)
	@$(CC) $(CFLAGS) $(INCS) $(OBJS) $(MINILIBXCC) $(MINI_LBX_LIBS) -o $(NAME) -lm
	@echo "$(SUCCESS_ICON) $(GREEN)Build successful:$(RESET) $(BOLD)$(NAME)$(RESET)"

$(NAME_BONUS): echo_build_bonus $(OBJS_BONUS)
	@echo "$(LINK_ICON) $(BOLD)Linking Bonus$(RESET) $(GREEN)$(NAME_BONUS)$(RESET)"
	@$(CC) $(CFLAGS) $(INCS_BONUS) $(OBJS_BONUS) -o $(NAME_BONUS)
	@echo "$(SUCCESS_ICON) $(GREEN)Build successful:$(RESET) $(BOLD)$(NAME_BONUS)$(RESET)"

# Rule to creat .o files for the Mandatory Part;
$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@echo "$(COMPILE_ICON) $(CYAN)Compiling$(RESET) $(YELLOW)$<$(RESET) → $(GREEN)$@$(RESET)"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@ || (echo "$(ERROR_ICON) $(RED)Compile failed: $<$(RESET)"; exit 1)

# Rule to creat .o files for the Bonus Part;
$(OBJS_BONUS_PATH)/%.o: $(SRCS_PATH_BONUS)/%.c
	@echo "$(COMPILE_ICON) $(CYAN)Compiling Bonus$(RESET) $(YELLOW)$<$(RESET) → $(GREEN)$@$(RESET)"
	@$(CC) $(CFLAGS) $(INCS) $(INCS_BONUS) -c $< -o $@ || (echo "$(ERROR_ICON) $(RED)Compile failed: $<$(RESET)"; exit 1)

clean:
	@echo "$(CLEAN_ICON) $(BLUE)Cleaning object files...$(RESET)"
	@rm -f $(OBJS) $(OBJS_BONUS)
# @rm -rf $(LIB_DIR)$(abspath $(LIBS)minilibx/minilibx-linux/obj)

fclean: clean
	@echo "$(CLEAN_ICON) $(BLUE)Removing executable:$(RESET) $(RED)$(NAME)$(RESET)"
	@rm -f $(NAME)
# @echo "$(CLEAN_ICON) $(BLUE)Removing executable:$(RESET) $(RED)$(NAME_BONUS)$(RESET)"
# @rm -f $(NAME_BONUS)

re: fclean all
