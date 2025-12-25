# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 17:47:48 by alephoen          #+#    #+#              #
#    Updated: 2025/12/25 18:05:43 by isadbaib         ###   ########.fr        #
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


LIBS_SO_PATH := $(abspath ../libs_so/LIBFT)
NAME:= $(LIBS_SO_PATH)/libft.a

CC := cc
CFLAGS := -g3 -O0 -Werror -Wall -Wextra

CFILES := \
ft_atoi.c \
ft_calloc.c \
ft_close_fd.c \
ft_free.c \
ft_free2dstr.c \
ft_getintlen.c \
ft_hex2int_fdf.c \
ft_int_round.c \
ft_isdigit.c \
ft_isalnum.c \
ft_itoa.c \
ft_memchr.c \
ft_memcpy.c \
ft_memset.c \
ft_min.c \
ft_split2_n.c \
ft_split_n.c \
ft_strdup.c \
ft_strdup2d.c \
ft_strndup.c \
ft_strchr.c \
ft_strjoin.c \
ft_strjoin3.c \
ft_strlen.c \
ft_strlen3.c \
ft_strlen_2.c \
ft_strncmp.c \
ft_strcmp.c \
ft_strtol.c \
ft_substr.c \
ft_split_2.c \
ft_substr_2.c \
ft_print_err_msg.c \
ft_fd_putstr.c \
ft_memjoin.c

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
	@echo "$(ROCKET_ICON) $(BOLD)Starting build $(RESET)$(MAGENTA)libft -> $(NAME)$(RESET)..."

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

# Rule to creat .o files for the Mandatory Part;
$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@echo "$(COMPILE_ICON) $(CYAN)Compiling$(RESET) $(YELLOW)$<$(RESET) → $(GREEN)$@$(RESET)"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@ || (echo "$(ERROR_ICON) $(RED)Compile failed: $<$(RESET)"; exit 1)

install_incs:
	cp -r incs/ $(LIBS_SO_PATH)/incs

clean:
	@echo "$(CLEAN_ICON) $(BLUE)Cleaning object files LIBFT...$(RESET)"
	@rm -f $(OBJS) $(OBJS_BONUS)
	@rm -rf $(LIBS_SO_PATH)

fclean: clean
	@echo "$(CLEAN_ICON) $(BLUE)Removing executable:$(RESET) $(RED)$(NAME)$(RESET)"
	@rm -f $(NAME)

re: fclean all
