/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 12:34:30 by igomes-d          #+#    #+#             */
/*   Updated: 2026/06/01 19:03:43 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_index_bucket(int num)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	return ((num - ctx->min) / ctx->div);
}

int	get_bucket_distance(t_stk *stk, int bucket, int min, int max)
{
	int	i;
	int	nb;

	i = 0;
	while (i < stk->len)
	{
		nb = stk->arr[_i(stk, i)].nb;
		if (nb != min && nb != max && get_index_bucket(nb) == bucket)
			return (i);
		i++;
	}
	return (-1);
}

void	medium(t_ctx *ctx)
{
	int	di_a;
	int	di_b;
	int	buckets_size;
	int	i;
	int	nb;

	buckets_size = get_index_bucket(ctx->max);
	i = 0;
	di_b = buckets_size;
	while (i <= buckets_size)
	{
		di_a = get_bucket_distance(&ctx->a, i, ctx->min, ctx->max);
		if (di_a == -1 && i++ >= 0 && --di_b >= -10)
			continue ;
		while (di_a--)
		{
			nb = ctx->a.arr[ctx->a.start].nb;
			if (nb != ctx->max && nb != ctx->min
				&& get_index_bucket(nb) == di_b)
				(push_b(), rotate_b(1));
			else
				rotate_a(1);
		}
		push_b();
	}
	while (ctx->b.len > 0)
	{
		get_less_distance(ctx, &di_a, &di_b, get_min_index(&ctx->a));
		move_to_top_dual(di_a, di_b, ctx);
		push_a();
	}
	move_to_top(get_distance(&ctx->a, ctx->min), ctx->a.len, 1);
}
