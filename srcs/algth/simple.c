/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:50:42 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/31 15:53:34 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_fit_distance(t_stk *stk, int val, int is_medium)
{
	int	prev_nb;
	int	curr_nb;
	int	i;

	i = 0;
	while (is_medium == 0 && i < stk->len)
	{
		prev_nb = stk->arr[_i(stk, i - 1)].nb;
		curr_nb = stk->arr[_i(stk, i)].nb;
		if (curr_nb < val && val < prev_nb)
			return (i);
		i++;
	}
	while (is_medium == 1 && i < stk->len)
	{
		prev_nb = stk->arr[_i(stk, i - 1)].nb;
		curr_nb = stk->arr[_i(stk, i)].nb;
		if (prev_nb < val && val < curr_nb)
			return (i);
		i++;
	}
	return (0);
}

int	move_to_top_dual(int di_a, int di_b, t_ctx *ctx)
{
	if (di_a > ctx->a.len - di_a && di_b > ctx->b.len - di_b)
	{
		di_a = ctx->a.len - di_a;
		di_b = ctx->b.len - di_b;
		if (di_b > di_a)
			(rev_rotate_r(di_a), di_b -= di_a, di_a = 0);
		else
			(rev_rotate_r(di_b), di_a -= di_b, di_b = 0);
		return (rev_rotate_a(di_a), rev_rotate_b(di_b), 0);
	}
	else if (di_a <= ctx->a.len - di_a && di_b <= ctx->b.len - di_b)
	{
		if (di_b > di_a)
			(rotate_r(di_a), di_b = di_b - di_a, di_a = 0);
		else
			(rotate_r(di_b), di_a -= di_b, di_b = 0);
		return (rotate_a(di_a), rotate_b(di_b), 0);
	}
	move_to_top(di_a, ctx->a.len, 1);
	move_to_top(di_b, ctx->b.len, 0);
	return (0);
}

void	get_less_distance(t_ctx *ctx, int *di_a, int *di_b)
{
	int	d_a;
	int	d_b;

	*di_a = 0;
	*di_b = get_fit_distance(&ctx->b, ctx->a.arr[ctx->a.start].nb, 0);
	d_a = *di_a;
	d_b = *di_b;
	while (++d_a < ctx->a.len)
	{
		d_b = get_fit_distance(&ctx->b, ctx->a.arr[_i(&ctx->a, d_a)].nb, 0);
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
	int	di_a;
	int	di_b;

	move_to_top(get_distance(&ctx->a, ctx->min), ctx->a.len, 1);
	push_b();
	move_to_top(get_distance(&ctx->a, ctx->max), ctx->a.len, 1);
	push_b();
	while (ctx->a.len > 0)
	{
		get_less_distance(ctx, &di_a, &di_b);
		move_to_top_dual(di_a, di_b, ctx);
		push_b();
	}
	move_to_top(get_distance(&ctx->b, ctx->max), ctx->b.len, 0);
	while (ctx->b.len > 0)
		push_a();
}
