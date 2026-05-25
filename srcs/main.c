/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:38:35 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/25 15:00:42 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sqrt(int nb)
{
	long long	count;
	long long	check;

	if (nb <= 0)
		return (0);
	check = 1;
	count = 1;
	while (check < nb)
	{
		count++;
		check = count * count;
	}
	if (check == nb)
		return (count);
	return (count - 1);
}

int	get_bucket_distance(t_list *start, int bucket, int divisor)
{
	int		i;
	t_list	*current;

	i = 0;
	current = start;
	while (current)
	{
		if (current->content / divisor == bucket)
			return (i);
		i++;
		current = current->next;
	}
	return (-1);
}

void	get_less_bucket_distance(t_ctx *ctx, int *di_a, int *di_b, int divisor)
{
	int		d_a;
	int		d_b;
	t_list	*current;

	*di_a = 0;
	*di_b = get_bucket_distance(ctx->stack_b, ctx->stack_a->content / divisor,
			divisor);
	d_a = 0;
	d_b = *di_b;
	current = ctx->stack_a->next;
	while (current)
	{
		d_a = get_distance(ctx->stack_a, current->content);
		d_b = get_bucket_distance(ctx->stack_b, current->content / divisor,
				divisor);
		if (fix_distance(d_a, ctx->total_a) + fix_distance(d_b,
				ctx->total_b) < fix_distance(*di_a, ctx->total_a)
			+ fix_distance(*di_b, ctx->total_b))
		{
			*di_a = d_a;
			*di_b = d_b;
		}
		current = current->next;
	}
}

int	get_fit_distance_rev(t_list *current, int val)
{
	int	i;

	i = 0;
	while (current)
	{
		if ((!current->prev || (current->prev && val > current->prev->content))
			&& current->content > val)
			return (i);
		i++;
		current = current->next;
	}
	return (0);
}

void	get_less_distance_rev(t_ctx *ctx, int *di_a, int *di_b)
{
	int		d_a;
	int		d_b;
	t_list	*current;

	*di_a = get_fit_distance_rev(ctx->stack_a, ctx->stack_b->content);
	*di_b = 0;
	d_a = *di_a;
	d_b = 0;
	current = ctx->stack_b->next;
	while (current)
	{
		d_a = get_fit_distance_rev(ctx->stack_a, current->content);
		d_b = get_distance(ctx->stack_b, current->content);
		if (fix_distance(d_a, ctx->total_a) + fix_distance(d_b,
				ctx->total_b) < fix_distance(*di_a, ctx->total_a)
			+ fix_distance(*di_b, ctx->total_b))
		{
			*di_a = d_a;
			*di_b = d_b;
		}
		current = current->next;
	}
}

void	medium(t_ctx *ctx, int min, int max, int divisor)
{
	int	di_a;
	int	di_b;
	int	i;

	// buckets = max / divisor;
	i = 0;
	while (ctx->total_a > 0)
	{
		di_a = get_bucket_distance(ctx->stack_a, i, divisor);
		if (di_a == -1)
		{
			i++;
			continue ;
		}
		move_to_top(di_a, ctx->total_a, rotate_a, rev_rotate_a);
		push_b(0);
	}
	// while (ctx->total_a > 0)
	// {
	// 	get_less_bucket_distance(ctx, &di_a, &di_b, divisor);
	// 	move_to_top_dual(di_a, di_b, ctx);
	// 	push_b(0);
	// }
	move_to_top(get_distance(ctx->stack_b, max), ctx->total_b, rotate_b,
		rev_rotate_b);
	push_a(0);
	move_to_top(get_distance(ctx->stack_b, min), ctx->total_b, rotate_b,
		rev_rotate_b);
	push_a(0);
	while (ctx->total_b > 0)
	{
		get_less_distance_rev(ctx, &di_a, &di_b);
		move_to_top_dual(di_a, di_b, ctx);
		push_a(0);
	}
	move_to_top(get_distance(ctx->stack_a, min), ctx->total_a, rotate_a,
		rev_rotate_a);
}

int	main(int argc, char **argv)
{
	t_ctx	ctx;
	//int		min;
	//int		max;
	//int		divisor;

	init(&ctx);
	if (argc == 1)
		return (1);
	if (parser_argv(++argv, &ctx) == 0)
		return (ft_printf_fd(2, "Error\n"), ft_lstclear(&(ctx.stack_a)), 1);
	mesure_disorder(&ctx);
	if (ctx.bench.disorder > 0)
	{
		//min = get_min(ctx.stack_a);
		//max = get_max(ctx.stack_a);
		//divisor = (max - min) / ft_sqrt(ctx.total_a);
		// if (!complex(&ctx))
		// 	return (0);
		// medium(&ctx, min, max, divisor);
		// simple(&ctx, min, max);
	}
	if (ctx.bench.is_bench == 1)
		print_bench(&ctx);
	// print_stacks(ctx.stack_a, ctx.stack_b);
	ft_lstclear(&ctx.stack_a);
	ft_lstclear(&ctx.stack_b);
	return (0);
}

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list	*new_a;
	t_list	*new_b;

	new_a = stack_a;
	new_b = stack_b;
	while (new_a || new_b)
	{
		if (new_a)
		{
			ft_printf_fd(2, "%d", new_a->content);
			new_a = new_a->next;
		}
		else
			ft_printf_fd(2, " ");
		ft_printf_fd(2, " | ");
		if (new_b)
		{
			ft_printf_fd(2, "%d", new_b->content);
			new_b = new_b->next;
		}
		ft_printf_fd(2, "\n");
	}
	ft_printf_fd(2, "_ | _\na | b\n\n");
}
