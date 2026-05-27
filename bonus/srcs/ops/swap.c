/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:37:48 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/27 11:59:05 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

/* Swap the first two elements at the top of stack a.
Do nothing if there is only one or no elements. */
void	swap_a(int ss)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	if (ctx->total_a > 1)
	{
		ctx->stack_a = ctx->stack_a->next;
		ctx->stack_a->prev->next = ctx->stack_a->next;
		ctx->stack_a->next = ctx->stack_a->prev;
		if (ctx->total_a > 2)
			ctx->stack_a->prev = ctx->stack_a->next->prev;
		ctx->stack_a->next->prev = ctx->stack_a;
		if (ctx->stack_a->next->next)
			ctx->stack_a->next->next->prev = ctx->stack_a->next;
	}
	if (ss)
		return ;
	ctx->bench.total++;
	ctx->bench.sa++;
}

/* Swap the first two elements at the top of stack b.
Do nothing if there is only one or no elements */
void	swap_b(int ss)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	if (ctx->total_b > 1)
	{
		ctx->stack_b = ctx->stack_b->next;
		ctx->stack_b->prev->next = ctx->stack_b->next;
		ctx->stack_b->next = ctx->stack_b->prev;
		if (ctx->total_b > 2)
			ctx->stack_b->prev = ctx->stack_b->next->prev;
		ctx->stack_b->next->prev = ctx->stack_b;
		if (ctx->stack_b->next->next)
			ctx->stack_b->next->next->prev = ctx->stack_b->next;
	}
	if (ss)
		return ;
	ctx->bench.total++;
	ctx->bench.sb++;
}

/* sa and sb at the same time. */
void	swap_s(void)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	swap_a(1);
	swap_b(1);
	ctx->bench.total++;
	ctx->bench.ss++;
}
