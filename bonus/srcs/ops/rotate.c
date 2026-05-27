/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:41:25 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/27 11:58:55 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

/* Shift up all elements of stack a by one.
The first element becomes the last one. */
void	rotate_a(int rr)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	if (ctx->total_a > 1)
	{
		ctx->stack_a->prev->next = ctx->stack_a;
		ctx->stack_a = ctx->stack_a->next;
		ctx->stack_a->prev->next = NULL;
	}
	if (rr)
		return ;
	ctx->bench.total++;
	ctx->bench.ra++;
}

/* Shift up all elements of stack b by one.
The first element becomes the last one. */
void	rotate_b(int rr)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	if (ctx->total_b > 1)
	{
		ctx->stack_b->prev->next = ctx->stack_b;
		ctx->stack_b = ctx->stack_b->next;
		ctx->stack_b->prev->next = NULL;
	}
	if (rr)
		return ;
	ctx->bench.total++;
	ctx->bench.rb++;
}

/* ra and rb at the same time. */
void	rotate_r(void)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	rotate_a(1);
	rotate_b(1);
	ctx->bench.total++;
	ctx->bench.rr++;
}
