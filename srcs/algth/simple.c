/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:50:42 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/21 12:27:49 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Returns the distante to the "perfect" position for the node with the
specified value. */
int	get_distance_inter_top_a(t_list *current, int val)
{
	int	i;

	i = 0;
	while (current)
	{
		if ((!current->prev || (current->prev && val < current->prev->content))
			&& current->content < val)
			return (i);
		i++;
		current = current->next;
	}
	return (0);
}

/* SIMPLE ALGORITHM:
1 > gets the distance to min value of the stack_a, moves it to the top of
stack_a and pushes it to stack_b;
2 > gets the distance to max value of the stack_b, moves it to the top of
stack_a and pushes it to stack_b;
3 > sorts the number in stack_b:
	> gets the perfect position for the top value of stack_a in stack_b;
	> moves the perfect position of stack_b to top;
	> pushes the top value of stack_a to stack_b;
4 > gets the distance to max value of the stack_b, moves it to the top of
stack_b and pushes all stack_b to stack_a; */
void	simple(t_ctx *ctx, int min, int max)
{
	move_to_top(get_distance(ctx->stack_a, min), ctx->total_a, rotate_a,
		rev_rotate_a);
	push_b(0);
	move_to_top(get_distance(ctx->stack_a, max), ctx->total_a, rotate_a,
		rev_rotate_a);
	push_b(0);
	while (ctx->total_a > 0)
	{
		move_to_top(get_distance_inter_top_a(ctx->stack_b,
				ctx->stack_a->content), ctx->total_b, rotate_b, rev_rotate_b);
		push_b(0);
	}
	move_to_top(get_distance(ctx->stack_b, max), ctx->total_b, rotate_b,
		rev_rotate_b);
	while (ctx->total_b > 0)
		push_a(0);
}
