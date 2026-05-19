/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:43:10 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/19 16:53:26 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Shift down all elements of stack a by one.
The last element becomes the first one. */
void	rev_rotate_a(t_ctx *init, int rrr)
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
		ctx->stack_a = ctx->stack_a->prev;
		ctx->stack_a->prev->next = NULL;
	}
	if (rrr)
		return ;
	ctx->bench.total++;
	ctx->bench.rra++;
	ft_printf_fd(1, "rra\n");
}

/* Shift down all elements of stack b by one.
The last element becomes the first one. */
void	rev_rotate_b(t_ctx *init, int rrr)
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
		ctx->stack_b = ctx->stack_b->prev;
		ctx->stack_b->prev->next = NULL;
	}
	if (rrr)
		return ;
	ctx->bench.total++;
	ctx->bench.rrb++;
	ft_printf_fd(1, "rrb\n");
}

/* rra and rrb at the same time. */
void	rev_rotate_r(t_ctx *init)
{
	static t_ctx	*ctx;

	if (init)
	{
		ctx = init;
		return ;
	}
	rev_rotate_a(0, 1);
	rev_rotate_b(0, 1);
	ctx->bench.total++;
	ctx->bench.rrr++;
	ft_printf_fd(1, "rrr\n");
}
