/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algth_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:49:21 by igomes-d          #+#    #+#             */
/*   Updated: 2026/06/03 13:03:44 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_distance(t_stk *stk, int val)
{
	int	i;

	i = -1;
	while (++i < stk->len)
		if (stk->arr[_i(stk, i)].nb == val)
			return (i);
	return (0);
}

void	move_to_top(int distance, int total, int is_a)
{
	if (distance > total - distance)
	{
		if (is_a)
			rev_rotate_a(total - distance);
		else
			rev_rotate_b(total - distance);
	}
	else
	{
		if (is_a)
			rotate_a(distance);
		else
			rotate_b(distance);
	}
}

int	comparable_distance(int d_a, int d_b, t_ctx *ctx)
{
	int	drev_a;
	int	drev_b;

	drev_a = ctx->a.len - d_a;
	drev_b = ctx->b.len - d_b;
	if (d_a > drev_a && d_b > drev_b)
	{
		if (drev_b > drev_a)
			return (drev_b);
		else
			return (drev_a);
	}
	else if (d_a <= drev_a && d_b <= drev_b)
	{
		if (d_b > d_a)
			return (d_b);
		else
			return (d_a);
	}
	else if (d_a > drev_a)
		return (drev_a + d_b);
	else if (d_b > drev_b)
		return (drev_b + d_a);
	return (d_a + d_b);
}

void	rotate_dual(int *d_a, int *d_b, void (*r)(int))
{
	if (*d_b > *d_a)
	{
		r(*d_a);
		*d_b -= *d_a;
		*d_a = 0;
	}
	else
	{
		r(*d_b);
		*d_a -= *d_b;
		*d_b = 0;
	}
}

int	move_to_top_dual(int d_a, int d_b, t_ctx *ctx)
{
	int	drev_a;
	int	drev_b;

	drev_a = ctx->a.len - d_a;
	drev_b = ctx->b.len - d_b;
	if (d_a > drev_a && d_b > drev_b)
		return (rotate_dual(&drev_a, &drev_b, rev_rotate_r),
			rev_rotate_a(drev_a), rev_rotate_b(drev_b), 0);
	else if (d_a <= drev_a && d_b <= drev_b)
		return (rotate_dual(&d_a, &d_b, rotate_r), rotate_a(d_a), rotate_b(d_b),
			0);
	move_to_top(d_a, ctx->a.len, 1);
	move_to_top(d_b, ctx->b.len, 0);
	return (0);
}
