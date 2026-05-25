/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:38:35 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/25 15:06:40 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_ctx *ctx)
{
	ctx->min = get_min(ctx->stack_a);
	ctx->max = get_max(ctx->stack_a);
	ctx->sqrt = ft_sqrt(ctx->total_a);
	if ((ctx->sqrt / 4) > 0)
		ctx->div = (ctx->max - ctx->min) / (ctx->sqrt / 4);
	else
		ctx->div = ctx->max;
	if (ctx->strategy == 1 || ctx->strategy == 4 + 1)
		simple(ctx);
	else if (ctx->strategy == 2 || ctx->strategy == 4 + 2)
		medium(ctx);
	else
		medium(ctx);
}

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc == 1)
		return (1);
	init(&ctx);
	if (parser_argv(++argv, &ctx) == 0)
		return (ft_printf_fd(2, "Error\n"), ft_lstclear(&(ctx.stack_a)), 1);
	mesure_disorder(&ctx);
	if (ctx.bench.disorder > 0)
		sort(&ctx);
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
