/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:39:49 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/18 19:06:08 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty. */
void	push_a(t_ctx *ctx)
{
	t_list	*temp;

	if (ctx->total_b < 1)
		return ;
	temp = ctx->stack_b;
	ctx->stack_b = ctx->stack_b->next;
	temp->next = ctx->stack_a;
	ctx->stack_a = temp;
	ctx->total_b--;
	ctx->total_a++;
	(ctx->bench.pa)++;
	ctx->bench.total++;
	ft_printf_fd(1, "pa\n");
}

/* Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty. */
void	push_b(t_ctx *ctx)
{
	t_list	*temp;

	if (ctx->total_a < 1)
		return ;
	temp = ctx->stack_a;
	ctx->stack_a = ctx->stack_a->next;
	temp->next = ctx->stack_b;
	ctx->stack_b = temp;
	ctx->total_b++;
	ctx->total_a--;
	(ctx->bench.pb)++;
	ctx->bench.total++;
	ft_printf_fd(1, "pb\n");
}
