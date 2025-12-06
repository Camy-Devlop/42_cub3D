# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/13 15:20:21 by alephoen          #+#    #+#              #
#    Updated: 2025/11/25 00:58:59 by alephoen         ###   ########.fr        #
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

NAME := minishell

CC := cc
CFLAGS := -g3 -O0 -Werror -Wall -Wextra -Wno-error=unused-function

FSAN   := -fsanitize=address,undefined

LIBS_DIR := libs
BUILTIN_DIR := built-in

# get_env.c should be added to the builting library latter!

CFILES := \
0_main.c \
1_0_minishell.c \
1_1_gate_fun.c \
2_init_t_shll.c \
3_0_history.c \
3_1_load_history.c \
4_check_built_in.c \
call_built_in_1.c \
call_built_in_2.c \
exec_decision.c \
signal_handler_child_1.c \
signal_handler_child_2.c \
ft_get_cmd_args.c \
ft_get_paths.c \
ft_is_cmd_accessible.c \
call_execve.c \
open_fds.c \
clean.c \
print_phoenix.c \
set_hd.c \
execme.c \
handle_cmd_pipe.c \
wait_for_children.c \
update_underscore_var.c \
exec_expansion.c

SRCS_PATH := srcs
OBJS_PATH := objs

SRCS := $(addprefix $(SRCS_PATH)/,$(CFILES) $(SHARED_CFILES))
OBJS := $(patsubst $(SRCS_PATH)/%.c,$(OBJS_PATH)/%.o,$(SRCS))

INCS_PATH 			:= incs
INCS_LIBFT 			:= libs/libs_so/LIBFT/incs
INCS_FT_FD_PRINTF 	:= libs/libs_so/ft_fdprintf/incs
INCS_RDLINE			:= libs/libs_so/ft_read_line/incs
INCS_GNL 			:= libs/libs_so/GNL/incs
INCS := -I$(INCS_PATH) -I$(INCS_LIBFT) -I$(INCS_RDLINE) -I$(INCS_GNL) -I$(INCS_FT_FD_PRINTF)

LIBFT_PATH := libs/libs_so/LIBFT
LIBFT := $(LIBFT_PATH)/libft.a

FT_FDPRINTF_PATH := libs/libs_so/ft_fdprintf
FT_FDPRINTF := $(FT_FDPRINTF_PATH)/ft_fdprintf.a

RDLINE_PATH := libs/libs_so/ft_read_line
RDLINE := $(RDLINE_PATH)/ft_read_line.a

GNL_PATH := libs/libs_so/GNL
GNL := $(GNL_PATH)/gnl.a

PARSER_PATH := libs/libs_so/posix_parser
PARSER := $(PARSER_PATH)/posix_parser.a

ENV_PATH := libs/libs_so/ft_env
FT_ENV := $(ENV_PATH)/ft_env.a

EXPORT_PATH := libs/libs_so/ft_export
FT_EXPORT := $(EXPORT_PATH)/ft_export.a

UNSET_PATH := libs/libs_so/ft_unset
FT_UNSET := $(UNSET_PATH)/ft_unset.a

PWD_PATH := libs/libs_so/ft_pwd
FT_PWD := $(PWD_PATH)/ft_pwd.a

CD_PATH := libs/libs_so/ft_cd
FT_CD := $(CD_PATH)/ft_cd.a

ECHO_PATH := libs/libs_so/ft_echo
FT_ECHO := $(ECHO_PATH)/ft_echo.a

LIBS :=  $(FT_FDPRINTF) $(GNL) $(RDLINE) $(PARSER) $(LIBFT)
BUILTIN := $(FT_ENV) $(FT_EXPORT) $(FT_UNSET) $(FT_PWD) $(FT_CD) $(FT_ECHO)

.PHONY: all bonus clean fclean re rere objs_dir start_msg make_libs libs_install built_in fsn

all: objs_dir start_msg make_libs make_built_in libs_install $(NAME)

rdline:
	@$(MAKE) -C $(LIBS_DIR)/ft_read_line re
	@$(MAKE) -C $(LIBS_DIR)/ft_read_line install_incs

gnl:
	@$(MAKE) -C $(LIBS_DIR)/gnl re
	@$(MAKE) -C $(LIBS_DIR)/gnl install_incs

libft:
	@$(MAKE) -C $(LIBS_DIR)/libft re
	@$(MAKE) -C $(LIBS_DIR)/libft install_incs

make_pars:
	@$(MAKE) -C $(LIBS_DIR)/posix_parser re
	@$(MAKE) -C $(LIBS_DIR)/posix_parser install_incs

make_libs:
	@$(MAKE) -C $(LIBS_DIR) all

libs_install:
	@$(MAKE) -C $(LIBS_DIR) install

make_built_in:
	@$(MAKE) -C $ $(BUILTIN_DIR) all

make_env:
	@$(MAKE) -C $ $(BUILTIN_DIR)/env re

make_exp:
	@$(MAKE) -C $ $(BUILTIN_DIR)/export re

make_uns:
	@$(MAKE) -C $ $(BUILTIN_DIR)/unset re

make_pwd:
	@$(MAKE) -C $ $(BUILTIN_DIR)/pwd re

make_cd:
	@$(MAKE) -C $ $(BUILTIN_DIR)/cd re

make_echo:
	@$(MAKE) -C $ $(BUILTIN_DIR)/echo re

objs_dir:
	@mkdir -p $(OBJS_PATH)

start_msg:
	@echo "$(ROCKET_ICON) $(BOLD)Starting build $(RESET) $(MAGENTA)$(NAME)$(RESET)..."

$(NAME): $(OBJS) $(LIBS) $(BUILTIN)
	@echo "$(LINK_ICON) $(BOLD)Linking$(RESET) $(GREEN)$(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(INCS) $(OBJS) $(BUILTIN) $(LIBS) -o $(NAME)
	@echo "$(SUCCESS_ICON) $(GREEN)Build successful:$(RESET) $(BOLD)$(NAME)$(RESET)"

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@echo "$(COMPILE_ICON) $(CYAN)Compiling$(RESET) $(YELLOW)$<$(RESET) → $(GREEN)$@$(RESET)"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@ || (echo "$(ERROR_ICON) $(RED)Compile failed: $<$(RESET)"; exit 1)

clean:
	@echo "$(CLEAN_ICON) $(BLUE)Cleaning object files Minishell...$(RESET)"
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBS_DIR) clean
	@$(MAKE) -C $(BUILTIN_DIR) clean

fclean: clean
	@echo "$(CLEAN_ICON) $(BLUE)Removing executable:$(RESET) $(RED)$(NAME)$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBS_DIR) fclean
	@$(MAKE) -C $(BUILTIN_DIR) fclean

re: fclean all

rere:
	@$(MAKE) -C $(LIBS_DIR) re
	@$(MAKE) libs_install
	@$(MAKE) re

fsn: CFLAGS += $(FSAN)
fsn: fclean $(NAME)
