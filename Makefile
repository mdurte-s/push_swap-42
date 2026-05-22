# --- Program  --------------------------------------------------------------- #

NAME		= push_swap
BONUS		= checker
# --- Flags ------------------------------------------------------------------ #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

# ---- Paths ----------------------------------------------------------------- #

INCDIR			= includes
LIBS_HELPER		= libs/helper.sh
SRCDIR			= srcs
OBJDIR			= objs

BONINC		= bonus/includes
BONSRC		= bonus/srcs
BONOBJ		= bonus/objs

# --- Sources ---------------------------------------------------------------- #

LIBS 			= $(shell $(LIBS_HELPER))
LIBS_OBJS		= $(shell $(LIBS_HELPER) objs)

SRCS 		= $(shell find $(SRCDIR) -name '*.c')
OBJS		= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

BONUS_SRCS	= $(shell find $(BONSRC) -name '*.c')
BONUS_OBJS	= $(BONUS_SRCS:$(BONOBJ)/%.c=$(BONOBJ)/%.o)

# --- Rules ------------------------------------------------------------------ #

define MAKE_LIB_OBJ
$(1): $(subst /objs/,/srcs/,$(1:.o=.c))
	$(LIBS_HELPER) make $(1)
endef

all:		$(NAME)

$(NAME): 	$(LIBS_OBJS) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

bonus:		$(BONUS)

$(BONUS):   $(LIBS_OBJS) $(BONUS_OBJS)
			$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBS) -o $(BONUS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

$(BONOBJ)/%.o: $(BONSRC)/%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -I $(BONSRC) -c $< -o $@

$(foreach obj,$(LIBS_OBJS),$(eval $(call MAKE_LIB_OBJ,$(obj))))

clean:
			$(RM) -r $(OBJDIR)
			$(RM) -r $(BONOBJ)
			$(shell $(RM) $(LIBS_OBJS) > /dev/null 2>&1)

fclean: 	clean
			$(RM) $(NAME)
			$(RM) $(BONUS)
			$(shell $(RM) $(LIBS) > /dev/null 2>&1)

re: 		fclean all

.PHONY:		all bonus clean fclean re