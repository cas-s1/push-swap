NAME := push_swap

CFLAGS := -Wall -Wextra -Werror -O2 -g

LIBFT := libft/libft.a

FILES := push_swap \
		 stack \
		 utils \
		 op_push \
		 op_swap \
		 op_rotate \
		 op_reverse_rotate \
		 sort \
		 algo \
		 algo_utils \

SRCDIR := src

SRC := $(FILES:%=$(SRCDIR)/%.c)

OBJDIR := obj

OBJ := $(FILES:%=$(OBJDIR)/%.o)

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
