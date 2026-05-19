/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:38:35 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/19 18:11:26 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	init(&ctx);
	if (argc == 1)
		return (1);
	if (parser_argv(argc, argv, &ctx) == 0)
		return (ft_printf_fd(2, "Error\n"), ft_lstclear(&(ctx.stack_a)), 1);
	mesure_disorder(&ctx);
	if (ctx.bench.disorder > 0)
	{
		simple(&ctx);
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
