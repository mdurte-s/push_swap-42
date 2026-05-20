/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:41:25 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/20 18:20:10 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Shift up all elements of stack a by one.
The first element becomes the last one. */
void	rotate_a(t_ctx *init, int rr)
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
	if (rr)
		return ;
	ctx->bench.total++;
	ctx->bench.ra++;
	//ft_printf_fd(1, "ra\n");
}

/* Shift up all elements of stack b by one.
The first element becomes the last one. */
void	rotate_b(t_ctx *init, int rr)
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
	if (rr)
		return ;
	ctx->bench.total++;
	ctx->bench.rb++;
	//ft_printf_fd(1, "rb\n");
}

/* ra and rb at the same time. */
void	rotate_r(t_ctx *init)
{
	static t_ctx	*ctx;

	if (init)
	{
		ctx = init;
		return ;
	}
	rotate_a(0, 1);
	rotate_b(0, 1);
	ctx->bench.total++;
	ctx->bench.rr++;
	//ft_printf_fd(1, "rr\n");
}
