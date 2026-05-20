/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:39:49 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/20 18:19:51 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_list(t_list **from, t_list **to, int to_size)
{
	t_list	*tmp;

	tmp = *from;
	*from = tmp->next;
	if (*from)
		(*from)->prev = tmp->prev;
	if (to_size > 0)
	{
		if (to_size > 1)
			tmp->prev = (*to)->prev;
		if (to_size == 1)
			tmp->prev = (*to);
		(*to)->prev = tmp;
	}
	tmp->next = *to;
	*to = tmp;
}
/* Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty. */
void	push_a(t_ctx *init)
{
	static t_ctx	*ctx;

	if (init)
	{
		ctx = init;
		return ;
	}
	if (ctx->total_b < 1)
		return ;
	push_list(&ctx->stack_b, &ctx->stack_a, ctx->total_a);
	ctx->total_b--;
	ctx->total_a++;
	ctx->bench.pa++;
	ctx->bench.total++;
	//ft_printf_fd(1, "pa\n");
}

/* Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty. */
void	push_b(t_ctx *init)
{
	static t_ctx	*ctx;

	if (init)
	{
		ctx = init;
		return ;
	}
	if (ctx->total_a < 1)
		return ;
	push_list(&ctx->stack_a, &ctx->stack_b, ctx->total_b);
	ctx->total_b++;
	ctx->total_a--;
	ctx->bench.pb++;
	ctx->bench.total++;
	//ft_printf_fd(1, "pb\n");
}
