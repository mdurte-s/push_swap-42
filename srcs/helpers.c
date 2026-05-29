/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:48:12 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/28 23:01:04 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ctx	*get_ctx(t_ctx *init)
{
	static t_ctx	*ctx;

	if (init)
		return (ctx = init, init);
	return (ctx);
}

void	init(t_ctx *ctx)
{
	ft_bzero(ctx, sizeof(t_ctx));
	get_ctx(ctx);
}

void	print_bench(t_ctx *ctx)
{
	ft_printf_fd(2, "[bench] disorder: %f%\n", ctx->bench.disorder);
	if (ctx->strategy == 0 || ctx->strategy >= 4)
	{
		ft_printf_fd(2, "[bench] strategy: %s", "Adaptive / ");
		if (ctx->strategy == 4 + 1)
			ft_printf_fd(2, "O(n²)\n");
		if (ctx->strategy == 4 + 2)
			ft_printf_fd(2, "O(n√n)\n");
		if (ctx->strategy == 4 + 3)
			ft_printf_fd(2, "O(n log n)\n");
	}
	if (ctx->strategy == 1)
		ft_printf_fd(2, "[bench] strategy: %s\n", "Simple / O(n²)");
	if (ctx->strategy == 2)
		ft_printf_fd(2, "[bench] strategy: %s\n", "Medium / O(n√n)");
	if (ctx->strategy == 3)
		ft_printf_fd(2, "[bench] strategy: %s\n", "Complex / O(n log n)");
	ft_printf_fd(2, "[bench] total_ops: %i\n", ctx->bench.total_ops);
	ft_printf_fd(2, "[bench] sa: %i sb: %i ss: %i pa: %i pb: %i\n",
		ctx->bench.sa, ctx->bench.sb, ctx->bench.ss, ctx->bench.pa,
		ctx->bench.pb);
	ft_printf_fd(2, "[bench] ra: %i rb: %i rr: %i rra: %i rrb: %i rrr: %i\n",
		ctx->bench.ra, ctx->bench.rb, ctx->bench.rr, ctx->bench.rra,
		ctx->bench.rrb, ctx->bench.rrr);
}

void	mesure_disorder(t_ctx *ctx)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = -1;
	while (++i + 1 < ctx->a.len)
	{
		j = i;
		while (++j < ctx->a.len)
		{
			total_pairs++;
			if (ctx->a.arr[i].nb > ctx->a.arr[j].nb)
				mistakes++;
		}
	}
	if (total_pairs == 0)
		ctx->bench.disorder = 0;
	else
		ctx->bench.disorder = (double)100 * (double)mistakes
			/ (double)total_pairs;
	update_bench_strategy(ctx);
}

void	update_bench_strategy(t_ctx *ctx)
{
	if (ctx->strategy == 0 || ctx->strategy == 4)
	{
		if ((int)ctx->bench.disorder < 20)
			ctx->strategy = 1 + 4;
		else if ((int)ctx->bench.disorder < 50)
			ctx->strategy = 2 + 4;
		else
			ctx->strategy = 3 + 4;
	}
}
