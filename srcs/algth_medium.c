/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algth_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 12:34:30 by igomes-d          #+#    #+#             */
/*   Updated: 2026/06/03 13:01:24 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sqrt(int nb)
{
	long long	count;
	long long	check;

	if (nb <= 0)
		return (0);
	check = 1;
	count = 1;
	while (check < nb)
	{
		count++;
		check = count * count;
	}
	if (check == nb)
		return (count);
	return (count - 1);
}

int	calc_bucket_index(int num)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	return ((num - ctx->min) / ctx->div);
}

int	find_nearby_bucket_distance(t_stk *stk, int bucket, int min, int max)
{
	int	i;
	int	nb;

	i = 0;
	while (i < stk->len)
	{
		nb = stk->arr[_i(stk, i)].nb;
		if (nb != min && nb != max && calc_bucket_index(nb) == bucket)
			return (i);
		i++;
	}
	return (-1);
}

void	move_to_top_bucket(t_ctx *ctx, int distance, int bucket_rev)
{
	int	nb;

	while (distance--)
	{
		nb = ctx->a.arr[ctx->a.start].nb;
		if (nb != ctx->max && nb != ctx->min
			&& calc_bucket_index(nb) == bucket_rev)
			(push_b(), rotate_b(1));
		else
			rotate_a(1);
	}
}

void	bucket_sort(t_ctx *ctx)
{
	int	distance;
	int	buckets_size;
	int	i;
	int	j;

	buckets_size = calc_bucket_index(ctx->max);
	i = 0;
	j = buckets_size;
	while (i <= buckets_size)
	{
		distance = find_nearby_bucket_distance(&ctx->a, i, ctx->min, ctx->max);
		if (distance == -1)
		{
			i++;
			--j;
			continue ;
		}
		move_to_top_bucket(ctx, distance, j);
		push_b();
	}
	binary_insertion_sort_a(ctx, binary_find_min_index(&ctx->a));
}
