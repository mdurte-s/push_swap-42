/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algth_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 21:30:52 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/06/03 16:22:31 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	partial_quick_sort_b(t_ctx *ctx, int size)
{
	int	remainder;
	int	i;
	int	pivot;

	if (size <= 3)
		return (small_sort_b(ctx, size));
	i = -1;
	remainder = 0;
	pivot = get_avg(&ctx->b, size);
	while (++i < size)
	{
		if (ctx->b.arr[ctx->b.start].nb <= pivot)
			(rotate_b(1), remainder++);
		else
			push_a();
	}
	rev_rotate_b(remainder);
	if (remainder)
		partial_quick_sort_b(ctx, remainder);
}

void	partial_quick_sort_a_b(t_ctx *ctx, int size)
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
		partial_quick_sort_a_b(ctx, remainder);
	if (pushes)
		partial_quick_sort_b(ctx, pushes);
}

void	intro_sort(t_ctx *ctx)
{
	int	count;

	count = ctx->a.capacity / 500;
	if (count < 1)
		return (bucket_sort(ctx));
	while (count--)
		partial_quick_sort_a_b(ctx, ctx->a.len);
	low_disorder_optimized_insertion_sort(ctx);
}
