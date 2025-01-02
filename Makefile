# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 12:19:06 by sliziard          #+#    #+#              #
#    Updated: 2025/01/02 12:19:06 by sliziard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#* VARIABLES
NAME = libftprintf.a

#TODO: Folders name must end with '\'
SRC_DIR = src/
OBJ_DIR = build/
LIBFT = libft
INCL_DIR = $(LIBFT)

CC = cc
CFLAGS := -Wall -Wextra -Werror -g3
RM = rm -f
MD = mkdir -p
AR = ar rcs

C_FILES =	flags.c					\
			ft_convert.c			\
			ft_convert_base.c		\
			ft_printf.c				\
			ft_realloc.c			\
			get_str_from_flag.c		\
			get_str_from_flag2.c
		
#* Colors

ESC = \033[
DEF_COLOR = $(ESC)0;39m
GRAY = $(ESC)0;90m
RED = $(ESC)0;91m
GREEN = $(ESC)0;92m
YELLOW = $(ESC)0;93m
BLUE = $(ESC)0;94m
MAGENTA = $(ESC)0;95m
CYAN = $(ESC)0;96m
UNDERLINE = $(ESC)4m

COLOR_PRINT = @printf "$(1)$(2)$(DEF_COLOR)\n"


#* Automatic
LIBFT_GIT = git@github.com:samlzz/libft.git
LIBFT_OBJ_RULE = "\nobjects:\t\$$(OBJ_DIR) \$$(OBJS)\n\t@echo \$$(OBJS) > libft_obj.txt"
LIBFT_BONUS_OBJ_RULE = "\n\nbobjects:\tobjects \$$(BONUS_OBJ)\n\t@echo \$$(BONUS_OBJ) >> libft_obj.txt"

ifdef INCL_DIR
	CFLAGS += -I$(INCL_DIR)
endif

SRCS := $(addprefix $(SRC_DIR), $(C_FILES))
OBJS := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))
O_DIRS := $(sort $(dir $(OBJS)))

#? cmd for make final file
ifeq ($(suffix $(NAME)), .a)
	LINK_CMD = $(AR) $(NAME) $(OBJS) $(addprefix $(LIBFT)/, $(shell cat $(LIBFT)/libft_obj.txt))
	LIBFT_RULE = $(MAKE) objects
else
	LINK_CMD = $(CC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a -o $(NAME)
	LIBFT_RULE = $(MAKE)
endif

#* Rules

all:	lib $(NAME)

lib: $(LIBFT)
	@printf "$(GRAY)"
	@$(LIBFT_RULE) -C $(LIBFT)
	$(call COLOR_PRINT,$(GREEN),$(LIBFT)compiled !)

$(LIBFT):
	$(call COLOR_PRINT,$(MAGENTA),Retrieving libft sources...)
	@printf "$(GRAY)"
	@$(MD) $(LIBFT)
	git clone $(LIBFT_GIT) ./$(LIBFT)
	@printf "$(DEF_COLOR)"
	@$(RM) -r ./$(LIBFT)/.git
	@$(RM) ./$(LIBFT)/.gitignore
	@printf $(LIBFT_OBJ_RULE) >> $(LIBFT)/Makefile
	@printf $(LIBFT_BONUS_OBJ_RULE) >> $(LIBFT)/Makefile

relib: dellib all

dellib:
	$(call COLOR_PRINT,$(MAGENTA),$(LIBFT) cleaned !)
	@$(RM) -r $(LIBFT)

$(NAME): $(O_DIRS) $(OBJS)
	@printf "$(GRAY)"
	$(LINK_CMD)
	$(call COLOR_PRINT,$(GREEN)$(UNDERLINE),$(NAME) compiled !)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(call COLOR_PRINT,$(YELLOW),Compiling: $<)
	@$(CC) $(CFLAGS) -c $< -o $@

$(O_DIRS):
	@$(MD) $@

clean:
	@$(RM) $(OBJS)
	@$(RM) -r $(OBJ_DIR)
	@printf "$(GRAY)"
	$(MAKE) clean -C $(LIBFT)
	$(call COLOR_PRINT,$(BLUE),$(NAME) object files cleaned!)

fclean:		clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)/libft.a
	$(call COLOR_PRINT,$(CYAN),executables files cleaned!)

re:		fclean all
	$(call COLOR_PRINT,$(GREEN),Cleaned and rebuilt everything for $(NAME)!)

.PHONY:		all lib relib dellib clean fclean re run
