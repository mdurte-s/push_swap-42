/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:39:49 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/29 00:32:31 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_from_to(t_stk *from, t_stk *to)
{
	size_t	from_start;

	from_start = from->start;
	if (to->len == 0)
	{
		from->empty_s = from_start;
		from->empty_e = from_start;
		to->arr[0] = from->arr[from_start];
		to->empty_s = 1;
		to->empty_e = to->capacity - 1;
		from->start = _i(from, 1);
		return ;
	}
	to->arr[push_i(to)] = from->arr[from_start];
	pop(from);
}

/* Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty. */
void	push_a(void)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	if (ctx->b.len < 1)
		return ;
	push_from_to(&ctx->b, &ctx->a);
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
	push_from_to(&ctx->a, &ctx->b);
	ctx->a.len--;
	ctx->b.len++;
	ctx->bench.pb++;
	ctx->bench.total_ops++;
	write(1, "pb\n", 3);
}
