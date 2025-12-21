# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/21 03:14:03 by alephoen          #+#    #+#              #
#    Updated: 2025/12/21 03:25:11 by alephoen         ###   ########.fr        #
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
CFLAGS := -g3 -O0 -Werror -Wall -Wextra

LIBS_DIR := libs

CFILES := \
0_main.c \
1_cub3d.c

SRCS_PATH := srcs
OBJS_PATH := objs

SRCS := $(addprefix $(SRCS_PATH)/,$(CFILES) $(SHARED_CFILES))
OBJS := $(patsubst $(SRCS_PATH)/%.c,$(OBJS_PATH)/%.o,$(SRCS))

INCS_PATH 			:= incs
INCS_LIBFT 			:= libs/libs_so/LIBFT/incs
INCS_GNL 			:= libs/libs_so/GNL/incs
INCS := -I$(INCS_PATH) -I$(INCS_LIBFT) -I$(INCS_GNL)

LIBFT_PATH := libs/libs_so/LIBFT
LIBFT := $(LIBFT_PATH)/libft.a

GNL_PATH := libs/libs_so/GNL
GNL := $(GNL_PATH)/gnl.a

LIBS :=  $(GNL) $(LIBFT)

.PHONY: all clean fclean re rere objs_dir start_msg make_libs libs_install link_h_files gen_ctags

all: objs_dir start_msg linkfiles.conf create_linkfileswithconf.sh link_h_files gen_ctags make_libs libs_install $(NAME)

gnl:
	@$(MAKE) -C $(LIBS_DIR)/gnl re
	@$(MAKE) -C $(LIBS_DIR)/gnl install_incs

libft:
	@$(MAKE) -C $(LIBS_DIR)/libft re
	@$(MAKE) -C $(LIBS_DIR)/libft install_incs

make_libs:
	@$(MAKE) -C $(LIBS_DIR) all

libs_install:
	@$(MAKE) -C $(LIBS_DIR) install

objs_dir:
	@mkdir -p $(OBJS_PATH)

start_msg:
	@echo "$(ROCKET_ICON) $(BOLD)Starting build $(RESET) $(MAGENTA)$(NAME)$(RESET)..."

gen_ctags:
	@echo "$(ROCKET_ICON) $(BOLD)Generating $(RESET) $(MAGENTA)ctags$(RESET)..."
	@ctags -R \
		--languages=C \
		--kinds-C=+fpd \
		--fields=+nS \
		--extras=+q \
		--tag-relative=yes \
		-f tags .
	@cp ./tags ./.tags

linkfiles.conf:
#@echo "Generating linkfiles.conf..."
#@printf "%s\n" \
#"./libs/posix_parser/incs/posix_parser.h:./incs/posix_parser.h" \
#"./libs/ft_fdprintf/incs/ft_fdprintf.h:./libs/ft_read_line/incs/ft_fdprintf.h" \
#"./incs/signal_handler.h:./libs/ft_read_line/incs/signal_handler.h" \
#"./incs/minishell.h:./libs/ft_read_line/incs/minishell.h" \
#"./incs/mini_macros.h:./libs/posix_parser/incs/mini_macros.h" \
#"./incs/minishell.h:./libs/posix_parser/incs/minishell.h" \
#> linkfiles.conf

create_linkfileswithconf.sh:
#@echo "Generating linkfileswithconf.sh..."
#@printf "%s\n" \
#"#!/usr/bin/env bash" \
#"# Hard-code root directory here if desired, otherwise defaults to current directory" \
#'ROOTDIR="$${ROOTDIR:-$$(pwd)}"' \
#"linkfileswithconf() {" \
#"    absroot=\$$(realpath \"\$$ROOTDIR\")" \
#"    # Ensure linkfiles.conf exists in root" \
#"    if [[ ! -f \"\$$absroot/linkfiles.conf\" ]]; then" \
#"        echo \"Error: linkfiles.conf not found in \$$absroot\"" \
#"        return 1" \
#"    fi" \
#"    while IFS= read -r line; do" \
#"        [[ -z \"\$$line\" || \"\$$line\" != *:* ]] && continue" \
#"        IFS=: read -r parent symlink <<< \"\$$line\"" \
#"        abs_parent=\"\$$absroot/\$$parent\"" \
#"        abs_symlink=\"\$$absroot/\$$symlink\"" \
#"        if [[ -e \"\$$abs_parent\" ]]; then" \
#"            ln -sf \"\$$abs_parent\" \"\$$abs_symlink\"" \
#"            echo \"Restored symlink: \$$abs_symlink -> \$$abs_parent\"" \
#"        else" \
#"            echo \"Warning: parent target missing (\$$abs_parent), skipped \$$abs_symlink\"" \
#"        fi" \
#"    done < \"\$$absroot/linkfiles.conf\"" \
#"    echo \"Finished restoring symlinks from linkfiles.conf\"" \
#"}" \
#"linkfileswithconf" \
#> linkfileswithconf.sh

link_h_files:
#@echo "$(ROCKET_ICON) $(BOLD)Link Header Files $(RESET) $(MAGENTA)headers.h$(RESET)..."
#@chmod +x linkfileswithconf.sh
#@./linkfileswithconf.sh

$(NAME): $(OBJS) $(LIBS)
	@echo "$(LINK_ICON) $(BOLD)Linking$(RESET) $(GREEN)$(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(INCS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(SUCCESS_ICON) $(GREEN)Build successful:$(RESET) $(BOLD)$(NAME)$(RESET)"

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@echo "$(COMPILE_ICON) $(CYAN)Compiling$(RESET) $(YELLOW)$<$(RESET) → $(GREEN)$@$(RESET)"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@ || (echo "$(ERROR_ICON) $(RED)Compile failed: $<$(RESET)"; exit 1)

clean:
	@echo "$(CLEAN_ICON) $(BLUE)Cleaning object files Minishell...$(RESET)"
	@rm -f $(OBJS)
	@rm -f tags .tags
	@$(MAKE) -C $(LIBS_DIR) clean

fclean: clean
	@echo "$(CLEAN_ICON) $(BLUE)Removing executable:$(RESET) $(RED)$(NAME)$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBS_DIR) fclean

re: fclean all

rere:
	@$(MAKE) -C $(LIBS_DIR) re
	@$(MAKE) libs_install
	@$(MAKE) re

