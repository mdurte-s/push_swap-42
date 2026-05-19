/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:50:42 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/19 21:55:13 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_distance_inter_top_a(t_list *current, int val)
{
	int	i;

	i = 0;
	while (current)
	{
		if ((!current->prev || (current->prev && current->prev->content > val))
			&& val > current->content)
			return (i);
		i++;
		current = current->next;
	}
	return (0);
}

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
