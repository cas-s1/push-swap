NAME := push_swap

CFLAGS := -Wall -Wextra -Werror

LIBFT := libft/libft.a

FILES := push_swap \

SRCDIR := src

SRC := $(FILES:%=$(SRCDIR)/%.c)

OBJDIR := obj

OBJ := $(FILES:%=$(OBJDIR)/%.o)

NOPRINT = 1> /dev/null 2> /dev/null

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@cc $(CFLAGS) $(OBJ) $(LIBFT) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@cc $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	@make -sC ./libft

clean:
	@make -s fclean -C ./libft
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
