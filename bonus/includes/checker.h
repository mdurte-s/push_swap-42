/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 10:41:01 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/27 11:41:57 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/* --- includes ------------------------------------------------------------- */

# include "../../libs/ft_printf/includes/ft_printf.h"
# include "../../libs/libft/includes/libft.h"

/* --- get_next_line --------------------  ---------------------------------- */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <fcntl.h>

char		*get_next_line(int fd);
char		*read_and_stash(int fd, char *stash);
char		*extract_line(char *stash);
char		*new_stash(char *stash);
char		*clean_data(char *data);

/* --- struct --------------------------------------------------------------- */

typedef struct s_bench
{
	int		is_bench;
	double	disorder;
	int		total;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}			t_bench;

typedef struct s_ctx
{
	t_bench	bench;
	t_list	*stack_a;
	t_list	*stack_b;
	int		total_a;
	int		total_b;
	int		strategy;
	int		*bottoms;
}			t_ctx;

/* --- functions ------------------------------------------------------------ */

int			get_ops(t_ctx *ctx);
int			parser_ops(char *line);

t_ctx		*get_ctx(t_ctx *init);
void		init(t_ctx *ctx);

void		mesure_disorder(t_ctx *ctx);
int			create_stack(char ***argv, t_ctx *ctx);
int			add_to_stack(char **argv, t_ctx *ctx);
int			check_repeated(t_ctx *ctx, int nb);
int			argv_to_int(char *argv, int *nb);

size_t		count_strings(char const *s, char c);
void		free_array(char **array);

void		push_a(void);
void		push_b(void);
void		push_list(t_list **from, t_list **to, int to_size);

void		rev_rotate_a(int rrr);
void		rev_rotate_b(int rrr);
void		rev_rotate_r(void);

void		rotate_a(int rr);
void		rotate_b(int rr);
void		rotate_r(void);

void		swap_a(int ss);
void		swap_b(int ss);
void		swap_s(void);

#endif
