/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:43:10 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/29 00:54:03 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Shift down all elements of stack a by one.
The last element becomes the first one. */
void	rev_rotate_a(int amount)
{
	t_ctx	*ctx;
	int		is_dual;

	if (amount == 0)
		return ;
	is_dual = amount < 0;
	if (is_dual)
		amount *= -1;
	ctx = get_ctx(0);
	if (ctx->a.len > 1)
		ctx->a.start = _i(&ctx->a, amount * -1);
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

	if (amount == 0)
		return ;
	is_dual = amount < 0;
	if (is_dual)
		amount *= -1;
	ctx = get_ctx(0);
	if (ctx->b.len > 1)
		ctx->b.start = _i(&ctx->b, amount * -1);
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

	if (amount == 0)
		return ;
	ctx = get_ctx(0);
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
