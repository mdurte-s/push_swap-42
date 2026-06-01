/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 21:30:52 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/06/01 22:31:22 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_avg(t_stk *stk, int total, int is_rev)
{
	int	sum;
	int	i;
	int	limit;

	sum = 0;
	limit = total;
	if (is_rev)
		i = -total;
	else
		i = 0;
	while (limit--)
		sum += stk->arr[_i(stk, i++)].nb;
	return (sum / total);
}

void	come_back(t_ctx *ctx, int rotates, int is_a)
{
	int	rev_amount;

	if (is_a)
	{
		rev_amount = ctx->a.len - rotates;
		if (rotates >= rev_amount)
			rotate_a(rev_amount);
		else if (rotates < rev_amount)
			rev_rotate_a(rotates);
		return ;
	}
	rev_amount = ctx->b.len - rotates;
	if (rotates >= rev_amount)
		rotate_b(rev_amount);
	else if (rotates < rev_amount)
		rev_rotate_b(rotates);
}

void	sort_three_b(t_ctx *ctx)
{
	int	start;
	int	middle;
	int	end;

	start = ctx->b.arr[ctx->b.start].nb;
	middle = ctx->b.arr[_i(&ctx->b, 1)].nb;
	end = ctx->b.arr[_i(&ctx->b, 2)].nb;
	if (start > middle && middle > end)
		return ;
	if (start < middle)
	{
		swap_b();
		if (start > end)
			return ;
	}
	rotate_b(1);
	swap_b();
	rev_rotate_b(1);
	if (middle < end && (start < middle || start < end))
		swap_b();
}

void	sort_three_a(t_ctx *ctx)
{
	int	start;
	int	middle;
	int	end;

	start = ctx->a.arr[ctx->a.start].nb;
	middle = ctx->a.arr[_i(&ctx->a, 1)].nb;
	end = ctx->a.arr[_i(&ctx->a, 2)].nb;
	if (start < middle && middle < end)
		return ;
	if (start > middle)
	{
		swap_a();
		if (start < end)
			return ;
	}
	rotate_a(1);
	swap_a();
	rev_rotate_a(1);
	if (middle > end && (start > middle || start > end))
		swap_a();
}

void	small_sort_b(t_ctx *ctx, int size)
{
	if (size == 2)
	{
		if (ctx->b.arr[ctx->b.start].nb < ctx->b.arr[_i(&ctx->b, 1)].nb)
			swap_b();
	}
	else if (size == 3)
		sort_three_b(ctx);
	while (size--)
		push_a();
}

void	small_sort_a(t_ctx *ctx, int size)
{
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (ctx->a.arr[ctx->a.start].nb > ctx->a.arr[_i(&ctx->a, 1)].nb)
			swap_a();
		return ;
	}
	if (size == 3)
		return (sort_three_a(ctx));
}

void	complex_b(t_ctx *ctx, int size)
{
	int	rotates;
	int	pushes;
	int	i;
	int	pivot;

	if (size <= 3)
		return (small_sort_b(ctx, size));
	i = -1;
	rotates = 0;
	pushes = 0;
	pivot = get_avg(&ctx->b, size, 0);
	while (++i < size)
	{
		if (ctx->b.arr[ctx->b.start].nb <= pivot)
			(rotate_b(1), rotates++);
		else
			(push_a(), pushes++);
	}
	if (pushes)
		complex_a(ctx, pushes);
	come_back(ctx, rotates, 0);
	if (rotates)
		complex_b(ctx, rotates);
}

void	complex_a(t_ctx *ctx, int size)
{
	int	rotates;
	int	pushes;
	int	i;
	int	pivot;

	if (size <= 3)
		return (small_sort_a(ctx, size));
	i = -1;
	rotates = 0;
	pushes = 0;
	pivot = get_avg(&ctx->a, size, 0);
	while (++i < size)
	{
		if (ctx->a.arr[ctx->a.start].nb > pivot)
			(rotate_a(1), rotates++);
		else
			(push_b(), pushes++);
	}
	come_back(ctx, rotates, 1);
	if (rotates)
		complex_a(ctx, rotates);
	if (pushes)
		complex_b(ctx, pushes);
}
