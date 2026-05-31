/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 12:34:30 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/31 15:51:13 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_index_bucket(int num)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	return ((num - ctx->min) / ctx->div);
}

int	get_bucket_distance(t_stk *stk, int bucket)
{
	int	i;

	i = 0;
	while (i < stk->len)
	{
		if (get_index_bucket(stk->arr[_i(stk, i)].nb) == bucket)
			return (i);
		i++;
	}
	return (-1);
}

void	get_less_distance_rev(t_ctx *ctx, int *di_a, int *di_b)
{
	int	d_a;
	int	d_b;

	*di_a = get_fit_distance(&ctx->a, ctx->b.arr[ctx->b.start].nb, 1);
	*di_b = 0;
	d_a = *di_a;
	d_b = *di_b;
	while (++d_b < ctx->b.len)
	{
		d_a = get_fit_distance(&ctx->a, ctx->b.arr[_i(&ctx->b, d_b)].nb, 1);
		if (comparable_distance(d_a, d_b, ctx) < comparable_distance(*di_a,
				*di_b, ctx))
		{
			*di_a = d_a;
			*di_b = d_b;
		}
	}
}

void	medium(t_ctx *ctx)
{
	int	di_a;
	int	di_b;
	int	buckets_size;
	int	i;

	buckets_size = get_index_bucket(ctx->max);
	i = 0;
	while (i <= buckets_size)
	{
		di_a = get_bucket_distance(&ctx->a, i);
		if (di_a == -1 && i++ >= 0)
			continue ;
		move_to_top(di_a, ctx->a.len, 1);
		push_b();
	}
	move_to_top(get_distance(&ctx->b, ctx->min), ctx->b.len, 0);
	push_a();
	move_to_top(get_distance(&ctx->b, ctx->max), ctx->b.len, 0);
	push_a();
	while (ctx->b.len > 0)
	{
		get_less_distance_rev(ctx, &di_a, &di_b);
		move_to_top_dual(di_a, di_b, ctx);
		push_a();
	}
	move_to_top(get_distance(&ctx->a, ctx->min), ctx->a.len, 1);
}
