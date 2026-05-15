# --- Program  --------------------------------------------------------------- #

NAME		= push_swap

# --- Flags ------------------------------------------------------------------ #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

# ---- Paths ----------------------------------------------------------------- #

INCDIR		= includes
SRCDIR		= srcs
OBJDIR		= objs
LIBDIR		= libft
LIBFT_A		= $(LIBDIR)/libft.a
PRIDIR		= ft_printf
PRINTF_A	= $(PRIDIR)/libftprintf.a

# --- Sources ---------------------------------------------------------------- #

SRCS		= $(SRCDIR)/swap.c \
			$(SRCDIR)/push.c \
			$(SRCDIR)/rotate.c \
			$(SRCDIR)/rev_rotate.c \
			$(SRCDIR)/check_args_flags_repeated.c \
			$(SRCDIR)/check_utils.c \
			$(SRCDIR)/main.c \

OBJS		= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# --- Rules ------------------------------------------------------------------ #

all:		$(NAME)

$(NAME): 	$(LIBFT_A) $(PRINTF_A) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(PRINTF_A) -o $(NAME)

$(LIBFT_A):
			$(MAKE) -C $(LIBDIR)

$(PRINTF_A):
			$(MAKE) -C $(PRIDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -I $(INCDIR) -I $(LIBDIR) -I $(PRIDIR) -c $< -o $@

clean:
			$(RM) -r $(OBJDIR)
			$(MAKE) -C $(LIBDIR) clean
			$(MAKE) -C $(PRIDIR) clean

fclean: 	clean
			$(RM) $(NAME)
			$(RM) $(LIBFT_A)
			$(RM) $(PRINTF_A)

re: 		fclean all

.PHONY:		all clean fclean re
