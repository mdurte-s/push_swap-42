/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:41:25 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/20 21:40:34 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rotate_a(t_ctx *init)
{
	static t_ctx	*ctx;

	if (init)
	{
		ctx = init;
		return ;
	}
	if (ctx->total_a > 1)
	{
		ctx->stack_a->prev->next = ctx->stack_a;
		ctx->stack_a = ctx->stack_a->next;
		ctx->stack_a->prev->next = NULL;
	}
}

void	rotate_b(t_ctx *init)
{
	static t_ctx	*ctx;

	if (init)
	{
		ctx = init;
		return ;
	}
	if (ctx->total_b > 1)
	{
		ctx->stack_b->prev->next = ctx->stack_b;
		ctx->stack_b = ctx->stack_b->next;
		ctx->stack_b->prev->next = NULL;
	}
}

void	rotate_r(t_ctx *init)
{
	static t_ctx	*ctx;

	if (init)
	{
		ctx = init;
		return ;
	}
	rotate_a(0);
	rotate_b(0);
}
