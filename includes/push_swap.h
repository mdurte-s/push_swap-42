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
t_ctx		*get_ctx(t_ctx *init);
void		print_bench(t_ctx *ctx);
void		mesure_disorder(t_ctx *ctx);
void		update_bench_strategy(t_ctx *ctx);
void		sort(t_ctx *ctx);
int			get_media(t_list *stack, int total, int size);
int			get_less_media_distance(t_list *current, int media, int rev);
void		small_sort_b(t_ctx *ctx);
void		small_sort_a(t_ctx *ctx);
void		complex_a(t_ctx *ctx, int size, int is_a);
void		print_stacks(t_list *stack_a, t_list *stack_b);
double		disorder(t_list *stack_a);
void		sort_int_array(int **array, int size);
int			get_median(t_list *stack, int total, int *median);
int			get_distance(t_list *list, int val);
void		move_to_top(int distance, int total, int is_a);
int			comparable_distance(int d_a, int d_b, t_ctx *ctx);
int			get_index_bucket(int num);
int			get_bucket_distance(t_list *current, int bucket);
void		get_less_distance_rev(t_ctx *ctx, int *di_a, int *di_b);
void		medium(t_ctx *ctx);
int			get_fit_distance(t_list *list, int val, int rev);
void		move_rest_dual(int di_a, int di_b, int is_rr);
int			move_to_top_dual(int di_a, int di_b, t_ctx *ctx);
void		get_less_distance(t_ctx *ctx, int *di_a, int *di_b);
void		simple(t_ctx *ctx);
int			get_max(t_list *current);
int			get_min(t_list *current);
int			ft_sqrt(int nb);
void		push_list(t_list **from, t_list **to, int to_size);
void		push_a(void);
void		push_b(void);
void		rev_rotate_a(int rrr);
void		rev_rotate_b(int rrr);
void		rev_rotate_r(void);
void		rotate_a(int rr);
void		rotate_b(int rr);
void		rotate_r(void);
void		swap_a(int ss);
void		swap_b(int ss);
void		swap_s(void);
int			check_repeated(t_ctx *ctx, int nb);
int			argv_to_int(char *argv, int *nb);
size_t		count_strings(char const *s, char c);
void		free_array(char **array);
int			parser_argv(char **argv, t_ctx *ctx);
int			create_stack(char ***argv, t_ctx *ctx);
int			add_to_stack(char **argv, t_ctx *ctx);
int			parser_flags(char **av, int *f, t_ctx *ctx);
int			check_flag(char *str);
#endif
