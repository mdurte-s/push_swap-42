/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 10:41:01 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/21 11:02:08 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/* --- includes ------------------------------------------------------------- */

# include "../ft_printf/includes/ft_printf.h"
# include "../libft/includes/libft.h"

/* --- get_next_line --------------------  ---------------------------------- */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include "../libft/includes/libft.h"
# include <fcntl.h>

char	*get_next_line(int fd);
char	*read_and_stash(int fd, char *stash);
char	*extract_line(char *stash);
char	*new_stash(char *stash);
char	*clean_data(char *data);

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

int		get_ops(t_ctx *ctx);
int		parser_ops(char *line);

void	init(t_ctx *ctx);
void	mesure_disorder(t_ctx *ctx);
int		create_stack(char **argv, int index, t_ctx *ctx);
int		check_repeated(t_list *stack_a);
int		argv_to_int(char *argv, int *nb);

void	push_a(t_ctx *init);
void	push_b(t_ctx *init);
void	push_list(t_list **from, t_list **to, int to_size);

void	rev_rotate_a(t_ctx *init, int rrr);
void	rev_rotate_b(t_ctx *init, int rrr);
void	rev_rotate_r(t_ctx *init);

void	rotate_a(t_ctx *init, int rr);
void	rotate_b(t_ctx *init, int rr);
void	rotate_r(t_ctx *init);

void	swap_a(t_ctx *init, int ss);
void	swap_b(t_ctx *init, int ss);
void	swap_s(t_ctx *init);

#endif
