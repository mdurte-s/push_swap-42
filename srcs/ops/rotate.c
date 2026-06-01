/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:41:25 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/06/01 22:23:54 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Shift up all elements of stack a by one.
The first element becomes the last one. */
void	rotate_a(int amount)
{
	t_ctx	*ctx;
	int		is_dual;

	ctx = get_ctx(0);
	amount = amount % ctx->a.len;
	if (amount == 0 || ctx->a.len < 2)
		return ;
	is_dual = amount < 0;
	if (is_dual)
		amount *= -1;
	rotate_stk(&ctx->a, amount);
	if (is_dual)
		return ;
	ctx->bench.total_ops += amount;
	ctx->bench.ra += amount;
	while (amount - 10 > 0)
	{
		amount -= 10;
		write(1, RA_10, 30);
	}
	while (amount--)
		write(1, "ra\n", 3);
}

/* Shift up all elements of stack b by one.
The first element becomes the last one. */
void	rotate_b(int amount)
{
	t_ctx	*ctx;
	int		is_dual;

	ctx = get_ctx(0);
	amount = amount % ctx->b.len;
	if (amount == 0 || ctx->b.len < 2)
		return ;
	is_dual = amount < 0;
	if (is_dual)
		amount *= -1;
	rotate_stk(&ctx->b, amount);
	if (is_dual)
		return ;
	ctx->bench.total_ops += amount;
	ctx->bench.rb += amount;
	while (amount - 10 > 0)
	{
		amount -= 10;
		write(1, RB_10, 30);
	}
	while (amount--)
		write(1, "rb\n", 3);
}

/* ra and rb at the same time. */
void	rotate_r(int amount)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	if (amount == 0 || (ctx->a.len < 2 && ctx->b.len < 2))
		return ;
	rotate_a(amount * -1);
	rotate_b(amount * -1);
	ctx->bench.total_ops += amount;
	ctx->bench.rr += amount;
	while (amount - 10 > 0)
	{
		amount -= 10;
		write(1, RR_10, 30);
	}
	while (amount--)
		write(1, "rr\n", 3);
}
