/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:37:48 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/20 21:41:30 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_a(t_ctx *init)
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
		ctx->stack_a->prev = ctx->stack_a->next->prev;
		ctx->stack_a->next->prev = ctx->stack_a;
		if (ctx->stack_a->next->next)
			ctx->stack_a->next->next->prev = ctx->stack_a->next;
	}
}

void	swap_b(t_ctx *init)
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
		ctx->stack_b->prev = ctx->stack_b->next->prev;
		ctx->stack_b->next->prev = ctx->stack_b;
		if (ctx->stack_b->next->next)
			ctx->stack_b->next->next->prev = ctx->stack_b->next;
	}
}

void	swap_s(t_ctx *init)
{
	static t_ctx	*ctx;

	if (init)
	{
		ctx = init;
		return ;
	}
	swap_a(0);
	swap_b(0);
}
