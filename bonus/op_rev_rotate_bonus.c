/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:43:10 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/06/03 13:48:14 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rev_rotate_a(void)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	if (ctx->total_a > 1)
	{
		ctx->stack_a->prev->next = ctx->stack_a;
		ctx->stack_a = ctx->stack_a->prev;
		ctx->stack_a->prev->next = NULL;
	}
}

void	rev_rotate_b(void)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	if (ctx->total_b > 1)
	{
		ctx->stack_b->prev->next = ctx->stack_b;
		ctx->stack_b = ctx->stack_b->prev;
		ctx->stack_b->prev->next = NULL;
	}
}

void	rev_rotate_r(void)
{
	rev_rotate_a();
	rev_rotate_b();
}
