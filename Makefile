# --- Program  --------------------------------------------------------------- #

NAME		= push_swap
BONUS		= checker
# --- Flags ------------------------------------------------------------------ #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

# ---- Paths ----------------------------------------------------------------- #

INCDIR			= includes
SRCDIR			= srcs
OBJDIR			= objs

BONUSDIR		= bonus

# --- Sources ---------------------------------------------------------------- #

SRCS 		= 	$(SRCDIR)/op_rev_rotate.c \
				$(SRCDIR)/algth_adaptive.c \
				$(SRCDIR)/op_swap.c \
				$(SRCDIR)/ft_printf.c \
				$(SRCDIR)/algth_simple.c \
				$(SRCDIR)/parser_argv_helpers.c \
				$(SRCDIR)/op_push.c \
				$(SRCDIR)/ft_printf_utils.c \
				$(SRCDIR)/mini_libft.c \
				$(SRCDIR)/algth_medium.c \
				$(SRCDIR)/algth_complex.c \
				$(SRCDIR)/ft_split.c \
				$(SRCDIR)/ft_printf_helpers.c \
				$(SRCDIR)/main_helpers.c \
				$(SRCDIR)/parser_argv.c \
				$(SRCDIR)/stacks.c \
				$(SRCDIR)/op_rotate.c \
				$(SRCDIR)/algth_helpers.c \
				$(SRCDIR)/algth_complex_helpers.c \
				$(SRCDIR)/main.c
OBJS		= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

BONUS_SRCS	= 	$(BONUSDIR)/op_rev_rotate_bonus.c \
				$(BONUSDIR)/op_rotate_bonus.c \
				$(BONUSDIR)/checker_bonus.c \
				$(BONUSDIR)/op_push_bonus.c \
				$(BONUSDIR)/mini_libft_bonus.c \
				$(BONUSDIR)/op_swap_bonus.c \
				$(BONUSDIR)/init_bonus.c \
				$(BONUSDIR)/parser_argv_bonus.c
BONUS_OBJS	= $(BONUS_SRCS:%.c=%.o)

# --- Rules ------------------------------------------------------------------ #


all:		$(NAME)

$(NAME): 	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus:		$(BONUS)

$(BONUS):  	$(BONUS_OBJS)
			$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

$(BONUSDIR)/%.o: $(BONUSDIR)/%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -I $(BONUSDIR) -c $< -o $@

clean:
			$(RM) -r $(OBJDIR)
			$(RM) -r $(BONUS_OBJS)

fclean: 	clean
			$(RM) $(NAME)
			$(RM) $(BONUS)

re: 		fclean all

.PHONY:		all bonus clean fclean re