/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 12:34:30 by igomes-d          #+#    #+#             */
/*   Updated: 2026/06/02 16:13:43 by igomes-d         ###   ########.fr       */
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

void	move_to_top_medium(t_ctx *ctx, int distance, int bucket_rev)
{
	int	nb;

	while (distance--)
	{
		nb = ctx->a.arr[ctx->a.start].nb;
		if (nb != ctx->max && nb != ctx->min
			&& get_index_bucket(nb) == bucket_rev)
			(push_b(), rotate_b(1));
		else
			rotate_a(1);
	}
}

void	medium(t_ctx *ctx)
{
	int	distance;
	int	buckets_size;
	int	i;
	int	j;

	buckets_size = get_index_bucket(ctx->max);
	i = 0;
	j = buckets_size;
	while (i <= buckets_size)
	{
		distance = get_bucket_distance(&ctx->a, i, ctx->min, ctx->max);
		if (distance == -1)
		{
			i++;
			--j;
			continue ;
		}
		move_to_top_medium(ctx, distance, j);
		push_b();
	}
	simple_sort_to_a(ctx, get_min_index(&ctx->a));
}
