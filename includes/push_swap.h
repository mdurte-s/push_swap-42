/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:37:26 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/19 19:05:30 by igomes-d         ###   ########.fr       */
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
// start-headers
int			create_stack(char **argv, int index, t_ctx *ctx);
int			argv_to_int(char *argv, int *nb);
size_t		count_strings(char const *s, char c);
void		free_array(char **array);
int			parser_argv(int argc, char **argv, t_ctx *ctx);
int			check_repeated(t_list *stack_a);
int			parser_split(int argc, char ***argv, int *index);
int			parser_flags(char **av, int *i, t_ctx *ctx);
int			get_distance_min_top(t_list *current);
int			get_distance_max_top(t_list *current);
void		move_to_top(int distance, int total, void (*r)(t_ctx *, int),
				void (*rr)(t_ctx *, int));
int			get_distance_inter_top(t_list *current, int val);
void		simple(t_ctx *ctx);
void		init(t_ctx *ctx);
void		print_bench(t_ctx *ctx);
void		mesure_disorder(t_ctx *ctx);
void		update_bench_strategy(t_ctx *ctx);
void		rev_rotate_a(t_ctx *init, int rrr);
void		rev_rotate_b(t_ctx *init, int rrr);
void		rev_rotate_r(t_ctx *init);
void		rotate_a(t_ctx *init, int rr);
void		rotate_b(t_ctx *init, int rr);
void		rotate_r(t_ctx *init);
void		push_list(t_list **from, t_list **to, int to_size);
void		push_a(t_ctx *init);
void		push_b(t_ctx *init);
void		swap_a(t_ctx *init, int ss);
void		swap_b(t_ctx *init, int ss);
void		swap_s(t_ctx *init);
void		print_stacks(t_list *stack_a, t_list *stack_b);

// end-headers

#endif
