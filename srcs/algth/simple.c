/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:50:42 by igomes-d          #+#    #+#             */
/*   Updated: 2026/06/01 16:15:06 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <fcntl.h>

int	get_min_index(t_stk *stk)
{
	int	left_i;
	int	right_i;
	int	mid_i;

	left_i = 0;
	right_i = stk->len - 1;
	while (left_i < right_i)
	{
		mid_i = left_i + (right_i - left_i) / 2;
		if (stk->arr[_i(stk, mid_i)].nb > stk->arr[_i(stk, right_i)].nb)
			left_i = mid_i + 1;
		else
			right_i = mid_i;
	}
	return (left_i);
}

int	get_fit_distance(t_stk *stk, int val, int min_offset)
{
	int	left;
	int	right;
	int	mid;
	int	curr_nb;
	int	real_mid;

	left = 0;
	right = stk->len - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		real_mid = (min_offset + mid) % stk->len;
		curr_nb = stk->arr[_i(stk, real_mid)].nb;
		if (stk->arr[_i(stk, real_mid - 1)].nb < val && val < curr_nb)
			return (real_mid);
		if (curr_nb > val)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return (-1);
}

int	move_to_top_dual(int d_a, int d_b, t_ctx *ctx)
{
	int	drev_a;
	int	drev_b;

	drev_a = ctx->a.len - d_a;
	drev_b = ctx->b.len - d_b;
	if (d_a > drev_a && d_b > drev_b)
	{
		if (drev_b > drev_a)
			(rev_rotate_r(drev_a), drev_b -= drev_a, drev_a = 0);
		else
			(rev_rotate_r(drev_b), drev_a -= drev_b, drev_b = 0);
		return (rev_rotate_a(drev_a), rev_rotate_b(drev_b), 0);
	}
	else if (d_a <= drev_a && d_b <= drev_b)
	{
		if (d_b > d_a)
			(rotate_r(d_a), d_b -= d_a, d_a = 0);
		else
			(rotate_r(d_b), d_a -= d_b, d_b = 0);
		return (rotate_a(d_a), rotate_b(d_b), 0);
	}
	move_to_top(d_a, ctx->a.len, 1);
	move_to_top(d_b, ctx->b.len, 0);
	return (0);
}

void	get_less_distance(t_ctx *ctx, int *di_a, int *di_b, int min_offset)
{
	int	d_a;
	int	d_b;

	*di_a = get_fit_distance(&ctx->a, ctx->b.arr[ctx->b.start].nb, min_offset);
	*di_b = 0;
	d_a = *di_a;
	d_b = *di_b;
	while (++d_b < ctx->b.len)
	{
		d_a = get_fit_distance(&ctx->a, ctx->b.arr[_i(&ctx->b, d_b)].nb,
				min_offset);
		if (comparable_distance(d_a, d_b, ctx) < comparable_distance(*di_a,
				*di_b, ctx))
		{
			*di_a = d_a;
			*di_b = d_b;
		}
	}
}

void	simple(t_ctx *ctx)
{
	int	nb;
	int	di_b;
	int	di_a;

	move_to_top(get_distance(&ctx->a, ctx->min), ctx->a.len, 1);
	rotate_a(1);
	nb = ctx->a.arr[ctx->a.start].nb;
	while (nb != ctx->min)
	{
		if (ctx->a.arr[_i(&ctx->a, -1)].nb > nb)
			push_b();
		else
			rotate_a(1);
		nb = ctx->a.arr[ctx->a.start].nb;
	}
	while (ctx->b.len > 0)
	{
		get_less_distance(ctx, &di_a, &di_b, get_min_index(&ctx->a));
		move_to_top_dual(di_a, di_b, ctx);
		push_a();
	}
	move_to_top(get_distance(&ctx->a, ctx->min), ctx->a.len, 1);
}
