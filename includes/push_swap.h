/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:37:26 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/06/03 13:25:24 by igomes-d         ###   ########.fr       */
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

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

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
void		rev_rotate_a(int amount);
void		rev_rotate_b(int amount);
void		rev_rotate_r(int amount);
void		mesure_disorder(t_ctx *ctx);
void		update_bench_strategy(t_ctx *ctx);
void		disorder_based_sort(t_ctx *ctx);
void		core_swap_a(int ss);
void		swap_a(void);
void		core_swap_b(int ss);
void		swap_b(void);
void		swap_s(void);
void		conversion(char flag, va_list arg, int *c, int fd);
int			validate(char c);
int			ft_printf_fd(int fd, const char *str, ...);
int			binary_find_min_index(t_stk *stk);
int			binary_find_fit_distance(t_stk *stk, int val, int min_offset);
void		choose_cheapest_distance_fit_to_a(t_ctx *ctx, int *di_a, int *di_b,
				int min_offset);
void		binary_insertion_sort_a(t_ctx *ctx, int min_i);
void		low_disorder_optimized_insertion_sort(t_ctx *ctx);
int			argv_to_int(char *argv, int *nb);
size_t		count_strings(char const *s, char c);
void		free_array(char **array);
void		push_a(void);
void		push_b(void);
int			validate_dup_sign(char *str);
double		power_nb(int base, int exp);
void		put_frc_part(int frc_part, int precision, int *counter, int fd);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_bzero(void *s, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
int			ft_sqrt(int nb);
int			calc_bucket_index(int num);
int			find_nearby_bucket_distance(t_stk *stk, int bucket, int min,
				int max);
void		move_to_top_bucket(t_ctx *ctx, int distance, int bucket_rev);
void		bucket_sort(t_ctx *ctx);
void		partial_quick_sort_b(t_ctx *ctx, int size);
void		low_nums_partial_quick_sort_a(t_ctx *ctx, int size);
void		partial_quick_sort_a_b(t_ctx *ctx, int size);
void		intro_sort(t_ctx *ctx);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
void		put_char(int c, int *counter, int fd);
void		put_str(char *str, int *counter, int fd);
void		put_nbr(long int nb, char *base, int *counter, int fd);
void		put_ptr(void *ptr, int *c, int fd);
void		put_flt(double nb, char *base, int *counter, int fd);
void		init(t_ctx *ctx);
t_ctx		*get_ctx(t_ctx *init);
void		print_bench(t_ctx *ctx);
int			parser_argv(char **argv, t_ctx *ctx);
int			create_stack(char ***argv, t_ctx *ctx);
int			add_to_stack(char **argv, t_ctx *ctx, long long *min,
				long long *max);
int			parser_flags(char **av, int *f, t_ctx *ctx);
int			check_flag(char *str);
void		clear(void);
int			check_dup(t_stk *stk, int nb);
int			add_stk(t_stk *stk, int nb);
ssize_t		_i(t_stk *stk, ssize_t index);
void		rotate_stk(t_stk *stk, int amount);
void		rotate_a(int amount);
void		rotate_b(int amount);
void		rotate_r(int amount);
int			find_distance(t_stk *stk, int val);
void		move_to_top(int distance, int total, int is_a);
int			comparable_distance(int d_a, int d_b, t_ctx *ctx);
void		rotate_dual(int *d_a, int *d_b, void (*r)(int));
int			move_to_top_dual(int d_a, int d_b, t_ctx *ctx);
int			get_avg(t_stk *stk, int total);
void		sort_three_b(t_ctx *ctx);
void		sort_three_a(t_ctx *ctx);
void		small_sort_b(t_ctx *ctx, int size);
void		small_sort_a(t_ctx *ctx, int size);
void		sort_three(t_ctx *ctx);
void		sort_under_five(t_ctx *ctx, int size);
void		sort(t_ctx *ctx);
#endif
