/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:48:12 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/21 10:42:10 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init(t_ctx *ctx)
{
	ft_bzero(ctx, sizeof(t_ctx));
	push_a(ctx);
	push_b(ctx);
	swap_a(ctx, 0);
	swap_b(ctx, 0);
	swap_s(ctx);
	rotate_a(ctx, 0);
	rotate_b(ctx, 0);
	rotate_r(ctx);
	rev_rotate_a(ctx, 0);
	rev_rotate_b(ctx, 0);
	rev_rotate_r(ctx);
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
	ft_printf_fd(2, "[bench] total_ops: %i\n", ctx->bench.total);
	ft_printf_fd(2, "[bench] sa: %i sb: %i ss: %i pa: %i pb: %i\n",
		ctx->bench.sa, ctx->bench.sb, ctx->bench.ss, ctx->bench.pa,
		ctx->bench.pb);
	ft_printf_fd(2, "[bench] ra: %i rb: %i rr: %i rra: %i rrb: %i rrr: %i\n",
		ctx->bench.ra, ctx->bench.rb, ctx->bench.rr, ctx->bench.rra,
		ctx->bench.rrb, ctx->bench.rrr);
}

void	mesure_disorder(t_ctx *ctx)
{
	int		mistakes;
	int		total_pairs;
	t_list	*stack_i;
	t_list	*stack_j;

	mistakes = 0;
	total_pairs = 0;
	stack_i = ctx->stack_a;
	while (stack_i->next)
	{
		stack_j = stack_i->next;
		while (stack_j)
		{
			if (stack_i->content >= stack_j->content)
				mistakes++;
			stack_j = (total_pairs++, stack_j->next);
		}
		stack_i = stack_i->next;
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
