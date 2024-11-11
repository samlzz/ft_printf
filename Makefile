# NAME = libftprintf.a
NAME = fttest

C_FILES =	flags.c				\
			ft_convert.c		\
			ft_convert_base.c	\
			ft_printf.c			\
			ft_realloc.c		\
			get_str_from_flag.c	\
			get_hex_from_flag.c	\
			main.c
BONUS_FILES =	

SRC_DIR = src/
OBJ_DIR = build/
INCL_DIR = libft

RM = rm -f
CC = gcc
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

ifneq ($(INCL_DIR),)
	CFLAGS += -I$(INCL_DIR)
endif

SRCS = $(addprefix $(SRC_DIR), $(C_FILES) $(BONUS_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))

# Déterminer la commande pour créer le fichier final
ifeq ($(suffix $(NAME)), .a)
	LINK_CMD = ar -rcs $(NAME) $(OBJS) $(LIBFT)
else
	LINK_CMD = $(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
endif

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(LINK_CMD)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
