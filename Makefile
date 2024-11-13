# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 18:21:28 by sliziard          #+#    #+#              #
#    Updated: 2024/11/13 23:05:36 by sliziard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
#NAME = fttest

C_FILES =	flags.c					\
			ft_convert.c			\
			ft_convert_base.c		\
			ft_printf.c				\
			ft_realloc.c			\
			get_str_from_flag.c		\
			get_str_from_flag2.c	\
#			main.c
LIBFT_DIR = libft
LIBFT = libft.a
LIBS = 

#TODO: Folders name must end with '\'
LIB_DIR =
SRC_DIR = src/
OBJ_DIR = build/
INCL_DIR = $(LIBFT_DIR)


RM = rm -f
MD = mkdir -p
CC = cc
CFLAGS := -Wall -Wextra -Werror

ifdef LIB_DIR
	CFLAGS += -L$(LIB_DIR) $(addprefix -l, $(LIBS))
endif
ifdef INCL_DIR
	CFLAGS += -I$(INCL_DIR)
endif

SRCS = $(addprefix $(SRC_DIR), $(C_FILES) $(BONUS_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))

#? cmd for make final file
ifeq ($(suffix $(NAME)), .a)
	LINK_CMD = ar -rcs $(NAME) $(OBJS)
	ADD_LIBFT = $(addprefix $(LIBFT_DIR)/, $(shell cat $(LIBFT_DIR)/libft_obj.txt))
	LIBFT_RULE = $(MAKE) objects
else
	LINK_CMD = $(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT) -o $(NAME)
	ADD_LIBFT = 
	LIBFT_RULE = $(MAKE)
endif

all: lib $(NAME)

lib: $(LIBFT_DIR)
	$(LIBFT_RULE) -C $(LIBFT_DIR)

$(LIBFT_DIR):
	$(MD) $(LIBFT_DIR)
	cp -r ~/Documents/cercle0/$(LIBFT_DIR)/* ./$(LIBFT_DIR)
	$(RM) ./$(LIBFT_DIR)/.git
	printf "\nobjects:\t\$$(OBJ_DIR) \$$(OBJS)\n\techo \$$(OBJS) > libft_obj.txt" >> $(LIBFT_DIR)/Makefile

$(NAME): $(OBJ_DIR) $(OBJS)
	$(LINK_CMD) $(ADD_LIBFT)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	$(MD) $(OBJ_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

run: all
	./$(NAME) | cat -e

trp_test:
	git clone https://github.com/Tripouille/printfTester.git ign_printfTester || true
	cd ign_printfTester && make m

trp_test_clean: fclean
	$(RM) -r ign_printfTester
	clear

.PHONY: all clean fclean re
