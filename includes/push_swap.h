/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:37:26 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/25 15:08:20 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* --- includes ------------------------------------------------------------- */

# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/libft/includes/libft.h"

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
	int		max;
	int		min;
	int		sqrt;
	int		div;
}			t_ctx;

/* --- functions ------------------------------------------------------------ */
/* autoheaders */

void		init(t_ctx *ctx);

int			parser_argv(char **argv, t_ctx *ctx);
int			parser_flags(char **av, int *index, t_ctx *ctx);
int			check_flag(char *str);
int			add_to_stack(char **argv, t_ctx *ctx);
int			check_repeated(t_ctx *ctx, int nb);
int			argv_to_int(char *argv, int *nb);
size_t		count_strings(char const *s, char c);
void		free_array(char **array);

void		mesure_disorder(t_ctx *ctx);
void		update_bench_strategy(t_ctx *ctx);
void		print_bench(t_ctx *ctx);

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

int			get_median(t_list *stack, int total, int *median);
int			get_max(t_list *current);
int			get_min(t_list *current);

int			get_distance(t_list *current, int val);
int			fix_distance(int distance, int total);
int			get_fit_distance(t_list *current, int val);
void		get_less_distance(t_ctx *ctx, int *di_a, int *di_b);
int			get_x_bigger(t_list *start, int x, int size, int min);
int			get_distance_inter_top(t_list *current, int val);

void		move_rest_dual(int di_a, int di_b, int is_rr);
void		move_to_top(int distance, int total, void (*r)(t_ctx *, int),
				void (*rr)(t_ctx *, int));
int			move_to_top_dual(int di_a, int di_b, t_ctx *ctx);

void		simple(t_ctx *ctx, int min, int max);
void		medium(t_ctx *ctx, int min, int max, int divisor);
int			complex(t_ctx *ctx);

void		print_stacks(t_list *stack_a, t_list *stack_b);

#endif
