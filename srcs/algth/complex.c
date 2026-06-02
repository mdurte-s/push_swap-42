/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 21:30:52 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/06/02 16:47:45 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	quick_b(t_ctx *ctx, int size)
{
	int	remainder;
	int	pushes;
	int	i;
	int	pivot;

	if (size <= 3)
		return (small_sort_b(ctx, size));
	i = -1;
	remainder = 0;
	pushes = 0;
	pivot = get_avg(&ctx->b, size);
	while (++i < size)
	{
		if (ctx->b.arr[ctx->b.start].nb <= pivot)
			(rotate_b(1), remainder++);
		else
			(push_a(), pushes++);
	}
	rev_rotate_b(remainder);
	if (remainder)
		quick_b(ctx, remainder);
}

void	quick_a(t_ctx *ctx, int size)
{
	int	remainder;
	int	pushes;
	int	i;
	int	pivot;

	if (size <= 3)
		return (small_sort_a(ctx, size));
	i = -1;
	remainder = 0;
	pushes = 0;
	pivot = get_avg(&ctx->a, size);
	while (++i < size)
	{
		if (ctx->a.arr[ctx->a.start].nb > pivot)
			(rotate_a(1), remainder++);
		else
			(push_b(), pushes++);
	}
	rev_rotate_a(remainder);
	if (remainder)
		quick_a(ctx, remainder);
	if (pushes)
		quick_b(ctx, pushes);
}

void	complex(t_ctx *ctx)
{
	if (ctx->a.capacity < 500)
		return (medium(ctx));
	quick_a(ctx, ctx->a.len);
	simple(ctx);
}
