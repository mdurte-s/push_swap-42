/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:43:10 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/24 14:08:37 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Shift down all elements of stack a by one.
The last element becomes the first one. */
void	rev_rotate_a(int rrr)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
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
void	rev_rotate_b(int rrr)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
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
void	rev_rotate_r(void)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	rev_rotate_a(1);
	rev_rotate_b(1);
	ctx->bench.total++;
	ctx->bench.rrr++;
	ft_printf_fd(1, "rrr\n");
}
