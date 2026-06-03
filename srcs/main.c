/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:38:35 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/06/03 14:36:33 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_ctx *ctx)
{
	if (ctx->a.arr[_i(&ctx->a, 0)].nb > ctx->a.arr[_i(&ctx->a, 1)].nb)
		swap_a();
	if (ctx->a.arr[_i(&ctx->a, 1)].nb > ctx->a.arr[_i(&ctx->a, 2)].nb)
		rev_rotate_a(1);
	if (ctx->a.arr[_i(&ctx->a, 0)].nb > ctx->a.arr[_i(&ctx->a, 1)].nb)
		swap_a();
}

void	sort_under_five(t_ctx *ctx, int size)
{
	if (size >= 4)
	{
		move_to_top(find_distance(&ctx->a, ctx->min), ctx->a.len, 1);
		push_b();
	}
	if (size == 5)
	{
		move_to_top(find_distance(&ctx->a, ctx->max), ctx->a.len, 1);
		push_b();
	}
	sort_three(ctx);
	if (size >= 4)
		push_a();
	if (size == 5)
	{
		rotate_a(1);
		push_a();
	}
}

void	sort(t_ctx *ctx)
{
	if (ctx->a.len <= 2)
		if (ctx->a.arr[0].nb > ctx->a.arr[1].nb)
			return (swap_a());
	if (ctx->a.len <= 5)
		return (sort_under_five(ctx, ctx->a.len));
	ctx->sqrt = ft_sqrt(ctx->a.len);
	if ((ctx->sqrt / 4) > 0)
		ctx->div = ((ssize_t)ctx->max - (ssize_t)ctx->min) / ((ssize_t)ctx->sqrt
				/ 4);
	else
		ctx->div = ctx->max;
	if (ctx->strategy == 1)
		low_disorder_optimized_insertion_sort(ctx);
	else if (ctx->strategy == 2)
		bucket_sort(ctx);
	else if (ctx->strategy == 3)
		intro_sort(ctx);
	else
		disorder_based_sort(ctx);
}

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc == 1)
		return (1);
	init(&ctx);
	if (parser_argv(++argv, &ctx) == 0)
		return (ft_printf_fd(2, "Error\n"), clear(), 1);
	mesure_disorder(&ctx);
	if (ctx.bench.disorder > 0)
		sort(&ctx);
	if (ctx.bench.is_bench == 1)
		print_bench(&ctx);
	return (clear(), 0);
}
