/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:43:10 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/06/01 22:23:43 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Shift down all elements of stack a by one.
The last element becomes the first one. */
void	rev_rotate_a(int amount)
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
	rotate_stk(&ctx->a, amount * -1);
	if (is_dual)
		return ;
	ctx->bench.total_ops += amount;
	ctx->bench.rra += amount;
	while (amount - 10 > 0)
	{
		amount -= 10;
		write(1, RRA_10, 40);
	}
	while (amount--)
		write(1, "rra\n", 4);
}

/* Shift down all elements of stack b by one.
The last element becomes the first one. */
void	rev_rotate_b(int amount)
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
	rotate_stk(&ctx->b, amount * -1);
	if (is_dual)
		return ;
	ctx->bench.total_ops += amount;
	ctx->bench.rrb += amount;
	while (amount - 10 > 0)
	{
		amount -= 10;
		write(1, RRB_10, 40);
	}
	while (amount--)
		write(1, "rrb\n", 4);
}

/* rra and rrb at the same time. */
void	rev_rotate_r(int amount)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	if (amount == 0 || (ctx->a.len < 2 && ctx->b.len < 2))
		return ;
	rev_rotate_a(amount * -1);
	rev_rotate_b(amount * -1);
	ctx->bench.total_ops += amount;
	ctx->bench.rrr += amount;
	while (amount - 10 > 0)
	{
		amount -= 10;
		write(1, RRR_10, 40);
	}
	while (amount--)
		write(1, "rrr\n", 4);
}
