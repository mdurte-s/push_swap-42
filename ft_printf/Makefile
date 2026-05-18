# --- Program ---------------------------------------------------------------- #

NAME		= libftprintf.a

# --- Flags ------------------------------------------------------------------ #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# --- Paths ------------------------------------------------------------------ #

SRCDIR		= srcs
INCDIR		= includes
OBJDIR		= objs

# --- Sources ---------------------------------------------------------------- #

SRCS		= ${SRCDIR}/put_char_str_nbr_ptr.c	${SRCDIR}/strlen_printf.c\
			${SRCDIR}/conversion.c				${SRCDIR}/ft_printf.c

OBJS		= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# --- Rules ------------------------------------------------------------------ #

all:		$(NAME)

$(NAME):	$(OBJS)
			ar -rcs $@ $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) -r $(OBJDIR)

fclean: clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
