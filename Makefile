# --- Program  --------------------------------------------------------------- #

NAME		= push_swap
BONUS		= checker
# --- Flags ------------------------------------------------------------------ #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

# ---- Paths ----------------------------------------------------------------- #

INCDIR		= includes
SRCDIR		= srcs
OBJDIR		= objs

BONINC		= bonus_includes
BONSRC		= bonus_srcs
BONOBJ		= bonus_objs

LIBDIR		= libft
LIBFT_A		= $(LIBDIR)/libft.a
PRIDIR		= ft_printf
PRINTF_A	= $(PRIDIR)/libftprintf.a

# --- Sources ---------------------------------------------------------------- #

SRCS 		= $(shell find $(SRCDIR) -name '*.c')
OBJS		= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

BONUS_SRCS	= $(shell find $(BONSRC) -name '*.c')
BONUS_OBJS	= $(BONUS_SRCS:$(BONOBJ)/%.c=$(BONOBJ)/%.o)

# --- Rules ------------------------------------------------------------------ #

all:		$(NAME)

$(NAME): 	$(LIBFT_A) $(PRINTF_A) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(PRINTF_A) -o $(NAME)

bonus:		$(BONUS)

$(BONUS):	$(LIBFT_A) $(PRINTF_A) $(OBJS) $(BONUS_OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(PRINTF_A) -o $(NAME)
			$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_A) $(PRINTF_A) -o $(BONUS)

$(LIBFT_A):
			$(MAKE) -C $(LIBDIR)

$(PRINTF_A):
			$(MAKE) -C $(PRIDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -I $(INCDIR) -I $(LIBDIR) -I $(PRIDIR) -c $< -o $@

$(BONOBJ)/%.o: $(BONSRC)/%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -I $(BONSRC) -I $(LIBDIR) -I $(PRIDIR) -c $< -o $@

clean:
			$(RM) -r $(OBJDIR)
			$(RM) -r $(BONOBJ)
			$(MAKE) -C $(LIBDIR) clean
			$(MAKE) -C $(PRIDIR) clean

fclean: 	clean
			$(RM) $(NAME)
			$(RM) $(BONUS)
			$(RM) $(LIBFT_A)
			$(RM) $(PRINTF_A)

re: 		fclean all

.PHONY:		all bonus clean fclean re
