# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 18:21:28 by sliziard          #+#    #+#              #
#    Updated: 2024/11/14 17:28:14 by sliziard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#* VARIABLES
NAME = libftprintf.a
#NAME = fttest

#TODO: Folders name must end with '\'
SRC_DIR = src/
OBJ_DIR = build/
LIBFT = libft
INCL_DIR = $(LIBFT)

CC = cc
CFLAGS := -Wall -Wextra -Werror
RM = rm -f
MD = mkdir -p
AR = ar rcs


C_FILES =	flags.c					\
			ft_convert.c			\
			ft_convert_base.c		\
			ft_printf.c				\
			ft_realloc.c			\
			get_str_from_flag.c		\
			get_str_from_flag2.c	\

#* Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
UNDERLINE = \033[4m

ifdef INCL_DIR
	CFLAGS += -I$(INCL_DIR)
endif

SRCS = $(addprefix $(SRC_DIR), $(C_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))

#? cmd for make final file
ifeq ($(suffix $(NAME)), .a)
	LINK_CMD = $(AR) $(NAME) $(OBJS)
	ADD_LIBFT = $(addprefix $(LIBFT)/, $(shell cat $(LIBFT)/libft_obj.txt))
	LIBFT_RULE = $(MAKE) objects
else
	LINK_CMD = $(CC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a -o $(NAME)
	ADD_LIBFT = 
	LIBFT_RULE = $(MAKE)
endif

all: lib $(NAME)

lib: $(LIBFT)
	@echo "$(GRAY)"
	@$(LIBFT_RULE) -C $(LIBFT)
	@echo "$(DEF_COLOR)"
	@echo "$(GREEN)$(LIBFT) compiled!$(DEF_COLOR)"

$(LIBFT):
	@echo "$(MAGENTA)Retrieving libft sources...$(GRAY)"
	@$(MD) $(LIBFT)
	cp -r ~/Documents/cercle0/$(LIBFT)/* ./$(LIBFT)
	@echo "$(DEF_COLOR)"
	@$(RM) ./$(LIBFT)/.git
	@printf "\nobjects:\t\$$(OBJ_DIR) \$$(OBJS)\n\t@echo \$$(OBJS) > libft_obj.txt" >> $(LIBFT)/Makefile

$(NAME): $(OBJ_DIR) $(OBJS)
	@echo "$(GRAY)"
	$(LINK_CMD) $(ADD_LIBFT)
	@echo "$(GREEN)$(UNDERLINE)$(NAME) compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@$(MD) $(OBJ_DIR)

clean:
	@echo "$(GRAY)"
	@$(MAKE) -C $(LIBFT) clean
	@echo "$(DEF_COLOR)"

	@$(RM) $(OBJS)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)/libft.a
	@echo "$(CYAN)executables files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for $(NAME)!$(DEF_COLOR)"

.PHONY: all clean fclean re
