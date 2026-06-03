/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:48:12 by igomes-d          #+#    #+#             */
/*   Updated: 2026/06/03 13:01:31 by igomes-d         ###   ########.fr       */
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
