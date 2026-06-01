/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:39:49 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/06/01 10:07:41 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty. */
void	push_a(void)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	if (ctx->b.len < 1)
		return ;
	ctx->a.start = (ctx->a.start - 1 + ctx->a.capacity) % ctx->a.capacity;
	ctx->a.arr[ctx->a.start] = ctx->b.arr[ctx->b.start];
	ctx->b.start = (ctx->b.start + 1) % ctx->b.capacity;
	ctx->a.len++;
	ctx->b.len--;
	ctx->bench.pa++;
	ctx->bench.total_ops++;
	write(1, "pa\n", 3);
}

/* Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty. */
void	push_b(void)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	if (ctx->a.len < 1)
		return ;
	ctx->b.start = (ctx->b.start - 1 + ctx->b.capacity) % ctx->b.capacity;
	ctx->b.arr[ctx->b.start] = ctx->a.arr[ctx->a.start];
	ctx->a.start = (ctx->a.start + 1) % ctx->a.capacity;
	ctx->a.len--;
	ctx->b.len++;
	ctx->bench.pb++;
	ctx->bench.total_ops++;
	write(1, "pb\n", 3);
}
