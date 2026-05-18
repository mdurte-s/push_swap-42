/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:38:35 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/18 19:04:19 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_ctx	ctx;
	int		i;
	int		min_i;
	int		min;
	int		is_rra;
	t_list	*current;

	ft_bzero(&ctx, sizeof(t_ctx));
	if (argc == 1)
		return (1);
	if (check_argv(argc, argv, &ctx) == 0)
		return (ft_printf_fd(2, "Error\n"), ft_lstclear(&(ctx.stack_a)), 1);
	while (ctx.total_a > 0)
	{
		i = 0;
		min_i = 0;
		current = ctx.stack_a;
		min = current->content;
		while (current)
		{
			if (current->content < min)
			{
				min_i = i;
				min = current->content;
			}
			i++;
			current = current->next;
		}
		if (min_i > ctx.total_a - min_i)
		{
			min_i = ctx.total_a - min_i;
			is_rra = 1;
		}
		else
			is_rra = 0;
		while (min_i--)
		{
			if (is_rra)
				rev_rotate_a(&ctx, 0);
			else
				rotate_a(&ctx, 0);
		}
		push_b(&ctx);
	}
	while (ctx.total_b > 0)
		push_a(&ctx);
	if (ctx.bench.is_bench == 1)
		print_bench(&ctx);
	//print_stacks(ctx.stack_a, ctx.stack_b);
	ft_lstclear(&ctx.stack_a);
	ft_lstclear(&ctx.stack_b);
	return (0);
}

void	print_bench(t_ctx *ctx)
{
	ft_printf_fd(2, "[bench] disorder: %i\n", ctx->bench.disorder);
	ft_printf_fd(2, "[bench] strategy: %i\n", ctx->strategy);
	ft_printf_fd(2, "[bench] total_ops: %i\n", ctx->bench.total);
	ft_printf_fd(2, "[bench] sa: %i sb: %i ss: %i pa: %i pb: %i\n",
		ctx->bench.sa, ctx->bench.sb, ctx->bench.ss, ctx->bench.pa,
		ctx->bench.pb);
	ft_printf_fd(2, "[bench] ra: %i rb: %i rr: %i rra: %i rrb: %i rrr: %i\n",
		ctx->bench.ra, ctx->bench.rb, ctx->bench.rr, ctx->bench.rra,
		ctx->bench.rrb, ctx->bench.rrr);
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
			ft_printf_fd(1, "%d", new_a->content);
			new_a = new_a->next;
		}
		else
			ft_printf_fd(1, " ");
		ft_printf_fd(1, " | ");
		if (new_b)
		{
			ft_printf_fd(1, "%d", new_b->content);
			new_b = new_b->next;
		}
		ft_printf_fd(1, "\n");
	}
	ft_printf_fd(1, "_ | _\na | b\n\n");
}

void	free_array(char **array)
{
	int	i;

	if ((size_t)array[0] == (size_t)1)
		return ;
	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}
