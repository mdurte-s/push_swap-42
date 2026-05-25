/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:49:21 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/25 15:07:02 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Returns the distance (int) from the first current node to the node with the
value specified. */
int	get_distance(t_list *list, int val)
{
	int	i;

	i = 0;
	while (list)
	{
		if (list->content == val)
			return (i);
		i++;
		list = list->next;
	}
	return (0);
}

void	move_to_top(int distance, int total, int is_a)
{
	if (distance > total - distance)
	{
		distance = total - distance;
		if (is_a)
			while (distance--)
				rev_rotate_a(0);
		else
			while (distance--)
				rev_rotate_b(0);
	}
	else
	{
		if (is_a)
			while (distance--)
				rotate_a(0);
		else
			while (distance--)
				rotate_b(0);
	}
}

int	comparable_distance(int d_a, int d_b, t_ctx *ctx)
{
	if (d_a > ctx->total_a - d_a && d_b > ctx->total_b - d_b)
	{
		d_a = ctx->total_a - d_a;
		d_b = ctx->total_b - d_b;
		if (d_b > d_a)
			return (d_b);
		else
			return (d_a);
	}
	else if (d_a <= ctx->total_a - d_a && d_b <= ctx->total_b - d_b)
	{
		if (d_b > d_a)
			return (d_b);
		else
			return (d_a);
	}
	else if (d_a > ctx->total_a - d_a)
		return ((ctx->total_a - d_a) + d_b);
	else if (d_b > ctx->total_b - d_b)
		return ((ctx->total_b - d_b) + d_a);
	return (d_a + d_b);
}
