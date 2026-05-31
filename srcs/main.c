/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:38:35 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/31 15:49:03 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_ctx *ctx)
{
	if (ctx->a.len <= 2)
		if (ctx->a.arr[0].nb > ctx->a.arr[1].nb)
			return (swap_a());
	if (ctx->a.len <= 3)
	{
		if (ctx->a.arr[0].nb > ctx->a.arr[1].nb)
			swap_a();
		if (ctx->a.arr[1].nb > ctx->a.arr[2].nb)
			rev_rotate_a(1);
		if (ctx->a.arr[0].nb > ctx->a.arr[1].nb)
			swap_a();
		return ;
	}
	ctx->min = get_min(&ctx->a, ctx->a.len);
	ctx->max = get_max(&ctx->a, ctx->a.len);
	ctx->sqrt = ft_sqrt(ctx->a.len);
	if ((ctx->sqrt / 4) > 0)
		ctx->div = (ctx->max - ctx->min) / (ctx->sqrt / 4);
	else
		ctx->div = ctx->max;
	if (ctx->strategy == 1 || ctx->strategy == 4 + 1)
		simple(ctx);
	else if (ctx->strategy == 2 || ctx->strategy == 4 + 2)
		medium(ctx);
	else
		complex_a(ctx, ctx->a.len);
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
	// print_stacks(&ctx);
	/* ft_lstclear(&ctx.stack_a);
	ft_lstclear(&ctx.stack_b); */
	return (clear(), 0);
}

void	print_stacks(t_ctx *ctx)
{
	ssize_t	i;
	ssize_t	idx;

	i = -1;
	ft_printf_fd(2, "\n");
	while (++i < ctx->a.capacity)
	{
		if (i < ctx->a.len)
		{
			idx = _i(&ctx->a, i);
			ft_printf_fd(2, "%d", ctx->a.arr[idx].nb);
		}
		else
			ft_printf_fd(2, " ");
		ft_printf_fd(2, "  |  ");
		if (i < ctx->b.len)
		{
			idx = _i(&ctx->b, i);
			ft_printf_fd(2, "%d", ctx->b.arr[idx].nb);
		}
		ft_printf_fd(2, "\n");
	}
	ft_printf_fd(2, "__ | __\na  |  b\n\n");
}
