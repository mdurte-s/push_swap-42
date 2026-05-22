/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:38:35 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/22 09:55:24 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_x_bigger(t_list *start, int x, int size, int min)
{
	int		count;
	int		rmd;
	int		rmd2;
	t_list	*find;
	t_list	*current;

	rmd = size;
	current = start;
	while (rmd--)
	{
		if (current->content >= min)
		{
			rmd2 = rmd + 1;
			find = current->next;
			count = 0;
			while (find && --rmd2)
			{
				if (find->content > current->content)
					count++;
				find = find->next;
			}
			if (count == x)
				return (current->content);
			if (count > x)
				min = current->content;
		}
		current = current->next;
	}
	return (get_x_bigger(start, x - 1, size, min));
}

int	get_distance_inter_top(t_list *current, int val)
{
	int	i;

	i = 0;
	while (current)
	{
		if ((!current->prev || (current->prev && current->prev->content < val))
			&& val < current->content)
			return (i);
		i++;
		current = current->next;
	}
	return (0);
}
int	main(int argc, char **argv)
{
	t_ctx	ctx;
	int		min;
	int		max;

	// int		bottoms[5];
	init(&ctx);
	if (argc == 1)
		return (1);
	if (parser_argv(argc, argv, &ctx) == 0)
		return (ft_printf_fd(2, "Error\n"), ft_lstclear(&(ctx.stack_a)), 1);
	mesure_disorder(&ctx);
	// if (ctx.bench.disorder > 0)
	// {
	// 	min = get_min(ctx.stack_a);
	// 	max = get_max(ctx.stack_a);
	// 	simple(&ctx, min, max);
		// bottoms[3] = get_x_bigger(ctx.stack_a, 100, 500, min);
		// bottoms[2] = get_x_bigger(ctx.stack_a, 100, 400, min);
		// bottoms[1] = get_x_bigger(ctx.stack_a, 100, 300, min);
		// bottoms[0] = get_x_bigger(ctx.stack_a, 100, 200, min);
		// move_to_top(get_distance(ctx.stack_a, max), ctx.total_a, rotate_a,
		// 	rev_rotate_a);
		// push_b(0);
		// move_to_top(get_distance(ctx.stack_a, bottoms[3]), ctx.total_a,
		// 	rotate_a, rev_rotate_a);
		// push_b(0);
		// move_to_top(get_distance(ctx.stack_a, bottoms[2]), ctx.total_a,
		// 	rotate_a, rev_rotate_a);
		// push_b(0);
		// move_to_top(get_distance(ctx.stack_a, bottoms[1]), ctx.total_a,
		// 	rotate_a, rev_rotate_a);
		// push_b(0);
		// move_to_top(get_distance(ctx.stack_a, bottoms[0]), ctx.total_a,
		// 	rotate_a, rev_rotate_a);
		// push_b(0);
		// while (ctx.total_a > 0)
		// {
		// 	if (ctx.stack_a->content < bottoms[0])
		// 	{
		// 		move_to_top(get_distance(ctx.stack_b, bottoms[0]), ctx.total_b,
		// 			rotate_b, rev_rotate_b);
		// 	}
		// 	else if (ctx.stack_a->content < bottoms[1])
		// 	{
		// 		move_to_top(get_distance(ctx.stack_b, bottoms[1]), ctx.total_b,
		// 			rotate_b, rev_rotate_b);
		// 	}
		// 	else if (ctx.stack_a->content < bottoms[2])
		// 	{
		// 		move_to_top(get_distance(ctx.stack_b, bottoms[2]), ctx.total_b,
		// 			rotate_b, rev_rotate_b);
		// 	}
		// 	else if (ctx.stack_a->content < bottoms[3])
		// 	{
		// 		move_to_top(get_distance(ctx.stack_b, bottoms[3]), ctx.total_b,
		// 			rotate_b, rev_rotate_b);
		// 	}
		// 	else
		// 	{
		// 		move_to_top(get_distance(ctx.stack_b, max), ctx.total_b,
		// 			rotate_b, rev_rotate_b);
		// 	}
		// 	push_b(0);
		// }
		// move_to_top(get_distance(ctx.stack_b, max), ctx.total_b, rotate_b,
		// 	rev_rotate_b);
		// push_a(0);
		// move_to_top(get_distance(ctx.stack_b, min), ctx.total_b, rotate_b,
		// 	rev_rotate_b);
		// push_a(0);
		// while (ctx.total_b > 0)
		// {
		// 	move_to_top(get_distance_inter_top(ctx.stack_a,
		// 			ctx.stack_b->content), ctx.total_a, rotate_a, rev_rotate_a);
		// 	push_a(0);
		// }
		// move_to_top(get_distance(ctx.stack_a, min), ctx.total_a, rotate_a,
		// 	rev_rotate_a);
	}
	if (ctx.bench.is_bench == 1)
		print_bench(&ctx);
	print_stacks(ctx.stack_a, ctx.stack_b);
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
