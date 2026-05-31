/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:37:26 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/28 22:38:29 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define RA_10 "ra\nra\nra\nra\nra\nra\nra\nra\nra\nra\n"
# define RB_10 "rb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\nrb\n"
# define RR_10 "rr\nrr\nrr\nrr\nrr\nrr\nrr\nrr\nrr\nrr\n"
# define RRA_10 "rra\nrra\nrra\nrra\nrra\nrra\nrra\nrra\nrra\nrra\n"
# define RRB_10 "rrb\nrrb\nrrb\nrrb\nrrb\nrrb\nrrb\nrrb\nrrb\nrrb\n"
# define RRR_10 "rrr\nrrr\nrrr\nrrr\nrrr\nrrr\nrrr\nrrr\nrrr\nrrr\n"

/* --- includes ------------------------------------------------------------- */

# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/libft/includes/libft.h"

/* --- struct --------------------------------------------------------------- */

typedef struct s_bench
{
	int		is_bench;
	double	disorder;
	int		total_ops;
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

typedef struct s_node
{
	int		nb;

}			t_node;

typedef struct s_stk
{
	ssize_t	len;
	ssize_t	capacity;
	ssize_t	start;
	ssize_t	empty_s;
	ssize_t	empty_e;
	t_node	*arr;
}			t_stk;

typedef struct s_ctx
{
	t_bench	bench;
	t_stk	a;
	t_stk	b;
	int		strategy;
	int		max;
	int		min;
	int		sqrt;
	int		div;
}			t_ctx;

/* --- functions ------------------------------------------------------------ */
/* autoheaders */
void		init(t_ctx *ctx);
t_ctx		*get_ctx(t_ctx *init);
void		print_bench(t_ctx *ctx);
void		mesure_disorder(t_ctx *ctx);
void		update_bench_strategy(t_ctx *ctx);
void		sort(t_ctx *ctx);
void		print_stacks(t_ctx *ctx);
void		clear(void);
int			check_dup(t_stk *stk, int nb);
int			add_stk(t_stk *stk, int nb);
ssize_t		_i(t_stk *stk, ssize_t index);
ssize_t		push_i(t_stk *stk);
void		pop(t_stk *stk);
int			get_avg(t_stk *stk, int total);
void		sort_three_b(t_ctx *ctx);
void		sort_three_a(t_ctx *ctx);
void		small_sort_b(t_ctx *ctx, int size);
void		small_sort_a(t_ctx *ctx, int size);
void		complex_b(t_ctx *ctx, int size);
void		complex_a(t_ctx *ctx, int size);
int			get_distance(t_stk *stk, int val);
void		move_to_top(int distance, int total, int is_a);
int			comparable_distance(int d_a, int d_b, t_ctx *ctx);
int			get_max(t_stk *stk, int size);
int			get_min(t_stk *stk, int size);
int			ft_sqrt(int nb);
int			get_fit_distance(t_stk *stk, int val, int is_medium);
int			move_to_top_dual(int di_a, int di_b, t_ctx *ctx);
void		get_less_distance(t_ctx *ctx, int *di_a, int *di_b);
void		simple(t_ctx *ctx);
int			get_index_bucket(int num);
int			get_bucket_distance(t_stk *stk, int bucket);
void		get_less_distance_rev(t_ctx *ctx, int *di_a, int *di_b);
void		medium(t_ctx *ctx);
int			argv_to_int(char *argv, int *nb);
size_t		count_strings(char const *s, char c);
void		free_array(char **array);
int			parser_argv(char **argv, t_ctx *ctx);
int			create_stack(char ***argv, t_ctx *ctx);
int			add_to_stack(char **argv, t_ctx *ctx);
int			parser_flags(char **av, int *f, t_ctx *ctx);
int			check_flag(char *str);
void		rotate_a(int amount);
void		rotate_b(int amount);
void		rotate_r(int amount);
void		push_from_to(t_stk *from, t_stk *to);
void		push_a(void);
void		push_b(void);
void		rev_rotate_a(int amount);
void		rev_rotate_b(int amount);
void		rev_rotate_r(int amount);
void		core_swap_a(int ss);
void		swap_a(void);
void		core_swap_b(int ss);
void		swap_b(void);
void		swap_s(void);
#endif
