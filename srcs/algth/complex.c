/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 21:30:52 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/27 01:02:40 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_media(t_list *stack, int size)
{
	int	sum;
	int	media;
	int	total;

	sum = 0;
	total = size;
	while (total-- && stack)
	{
		sum += stack->content;
		stack = stack->next;
	}
	media = sum / size;
	return (media);
}

void	sort_three_b(t_ctx *ctx)
{
	int	start;
	int	middle;
	int	end;

	start = ctx->stack_b->content;
	middle = ctx->stack_b->next->content;
	end = ctx->stack_b->next->next->content;
	if (start > middle && middle > end)
		return ;
	if (start < middle && middle > end && start > end)
		swap_b(0);
	if (start < middle && middle < end)
		(swap_b(0), rotate_b(0), swap_b(0), rev_rotate_b(0), swap_b(0));
	if (start > middle && middle < end && start > end)
		(rotate_b(0), swap_b(0), rev_rotate_b(0));
	if (start < middle && middle > end && start < end)
		(swap_b(0), rotate_b(0), swap_b(0), rev_rotate_b(0));
	if (start > middle && middle < end && start < end)
		(rotate_b(0), swap_b(0), rev_rotate_b(0), swap_b(0));
}

void	sort_three_a(t_ctx *ctx)
{
	int	start;
	int	middle;
	int	end;

	start = ctx->stack_a->content;
	middle = ctx->stack_a->next->content;
	end = ctx->stack_a->next->next->content;
	if (start < middle && middle < end)
		return ;
	if (start > middle && middle < end && start < end)
		swap_a(0);
	if (start > middle && middle > end)
		(swap_a(0), rotate_a(0), swap_a(0), rev_rotate_a(0), swap_a(0));
	if (start > middle && middle < end && start > end)
		(swap_a(0), rotate_a(0), swap_a(0), rev_rotate_a(0));
	if (start < middle && middle > end && start < end)
		(rotate_a(0), swap_a(0), rev_rotate_a(0));
	if (start < middle && middle > end && start > end)
		(rotate_a(0), swap_a(0), rev_rotate_a(0), swap_a(0));
}

void	small_sort_b(t_ctx *ctx, int size)
{
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (ctx->stack_b->content < ctx->stack_b->next->content)
			swap_b(0);
		return ;
	}
	if (size == 3)
		return (sort_three_b(ctx));
}

void	small_sort_a(t_ctx *ctx, int size)
{
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (ctx->stack_a->content > ctx->stack_a->next->content)
			swap_a(0);
		return ;
	}
	if (size == 3)
		return (sort_three_a(ctx));
}

void	complex_b(t_ctx *ctx, int size)
{
	int		rotates;
	int		pushes;
	int		i;
	int		pivot;

	if (size <= 3)
		return (small_sort_b(ctx, size));
	i = -1;
	rotates = 0;
	pushes = 0;
	pivot = get_media(ctx->stack_b, size);
	while (++i < size)
	{
		if (ctx->stack_b->content <= pivot)
			(rotate_b(0), rotates++);
		else
			(push_a(), pushes++);
	}
	while (rotates--)
		rev_rotate_b(0);
	complex_b(ctx, size - pushes);
	complex_a(ctx, pushes);
	while (pushes--)
		push_b();
}

void	complex_a(t_ctx *ctx, int size)
{
	int		rotates;
	int		pushes;
	int		i;
	int		pivot;

	if (size <= 3)
		return (small_sort_a(ctx, size));
	i = -1;
	rotates = 0;
	pushes = 0;
	pivot = get_media(ctx->stack_a, size);
	while (++i < size)
	{
		if (ctx->stack_a->content > pivot)
			(rotate_a(0), rotates++);
		else
			(push_b(), pushes++);
	}
	while (rotates--)
		rev_rotate_a(0);
	complex_b(ctx, pushes);
	complex_a(ctx, size - pushes);
	while (pushes--)
		push_a();
}
