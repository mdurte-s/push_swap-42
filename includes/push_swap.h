/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:37:26 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/18 17:40:58 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* --- includes ------------------------------------------------------------- */

# include "../ft_printf/includes/ft_printf.h"
# include "../libft/includes/libft.h"

/* --- struct --------------------------------------------------------------- */

typedef struct s_bench
{
	int		is_bench;
	int		disorder;
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
}			t_ctx;

/* --- functions ------------------------------------------------------------ */

void		swap_a(t_ctx *ctx, int ss);
void		swap_b(t_ctx *ctx, int ss);
void		swap_s( t_ctx *ctx);

void		push_a( t_ctx *ctx);
void		push_b( t_ctx *ctx);

void		rotate_a(t_ctx *ctx, int rr);
void		rotate_b(t_ctx *ctx, int rr);
void		rotate_r( t_ctx *ctx);

void		rev_rotate_a(t_ctx *ctx, int rrr);
void		rev_rotate_b(t_ctx *ctx, int rrr);
void		rev_rotate_r( t_ctx *ctx);

int			check_argv(int argc, char **argv, t_ctx *ctx);
int			check_flags(char **av, int *i, t_ctx *ctx);
int			check_is_split(int argc, char ***argv, int *index);
int			check_repeated(t_list *stack_a);

int			create_stack(char **argv, int index, t_ctx *ctx);
int			argv_to_int(char *argv, int *nb);
size_t		count_strings(char const *s, char c);

void		print_stacks(t_list *stack_a, t_list *stack_b);
void		print_bench(t_ctx *ctx);
void		free_array(char **array);

#endif
