NAME := push_swap

BONUS_NAME := checker

CFLAGS := -Wall -Wextra -Werror -O2 -g

LIBFT := libft/libft.a

MAIN_FILES := push_swap \
		 stack \
		 utils \
		 op_push \
		 op_swap \
		 op_rotate \
		 op_reverse_rotate \
		 sort \
		 algo \
		 algo_utils \

BONUS_FILES := checker \
			   checker_utils \
			   stack \
			   utils \
			   op_push \
			   op_swap \
			   op_rotate \
			   op_reverse_rotate \

INCDIR := inc

SRCDIR := src

MAIN_SRC := $(MAIN_FILES:%=$(SRCDIR)/%.c)

BONUS_SRC := $(BONUS_FILES:%=$(SRCDIR)/%.c)

OBJDIR := obj

MAIN_OBJ := $(MAIN_FILES:%=$(OBJDIR)/%.o)

BONUS_OBJ := $(BONUS_FILES:%=$(OBJDIR)/%.o)

$(NAME): $(MAIN_OBJ) $(LIBFT)
	@cc $(CFLAGS) $(MAIN_OBJ) $(LIBFT) -o $@

$(BONUS_NAME): $(BONUS_OBJ) $(LIBFT)
	@cc $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $@

bonus: $(BONUS_NAME)

all: $(NAME) $(BONUS_NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@cc $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	@make -sC ./libft

clean:
	@make -s fclean -C ./libft
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
