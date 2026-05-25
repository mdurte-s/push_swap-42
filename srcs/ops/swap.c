/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:37:48 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/25 14:58:10 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Swap the first two elements at the top of stack a.
Do nothing if there is only one or no elements. */
void	swap_a(t_ctx *init, int ss)
{
	static t_ctx	*ctx;

	if (init)
	{
		ctx = init;
		return ;
	}
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
	ft_printf_fd(1, "sa\n");
}

/* Swap the first two elements at the top of stack b.
Do nothing if there is only one or no elements */
void	swap_b(t_ctx *init, int ss)
{
	static t_ctx	*ctx;

	if (init)
	{
		ctx = init;
		return ;
	}
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
	ft_printf_fd(1, "sb\n");
}

/* sa and sb at the same time. */
void	swap_s(t_ctx *init)
{
	static t_ctx	*ctx;

	if (init)
	{
		ctx = init;
		return ;
	}
	swap_a(0, 1);
	swap_b(0, 1);
	ctx->bench.total++;
	ctx->bench.ss++;
	ft_printf_fd(1, "ss\n");
}
