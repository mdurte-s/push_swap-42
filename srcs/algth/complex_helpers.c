/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:29:01 by igomes-d          #+#    #+#             */
/*   Updated: 2026/06/02 16:38:25 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_avg(t_stk *stk, int total)
{
	int	sum;
	int	i;
	int	limit;

	sum = 0;
	limit = total;
	i = 0;
	while (limit--)
		sum += stk->arr[_i(stk, i++)].nb;
	return (sum / total);
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
