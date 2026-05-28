/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:43:10 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/28 14:25:19 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Shift down all elements of stack a by one.
The last element becomes the first one. */
void	core_rev_rotate_a(int rrr)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	if (ctx->a.len > 1)
		ctx->a.start = _i(&ctx->a, 1);
	if (rrr)
		return ;
	ctx->bench.total_ops++;
	ctx->bench.rra++;
	ft_printf_fd(1, "rra\n");
}

void	rev_rotate_a(void)
{
	core_rev_rotate_a(0);
}

/* Shift down all elements of stack b by one.
The last element becomes the first one. */
void	core_rev_rotate_b(int rrr)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	if (ctx->b.len > 1)
		ctx->b.start = _i(&ctx->b, 1);
	if (rrr)
		return ;
	ctx->bench.total_ops++;
	ctx->bench.rrb++;
	ft_printf_fd(1, "rrb\n");
}

void	rev_rotate_b(void)
{
	core_rev_rotate_b(0);
}

/* rra and rrb at the same time. */
void	rev_rotate_r(void)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	core_rev_rotate_a(1);
	core_rev_rotate_b(1);
	ctx->bench.total_ops++;
	ctx->bench.rrr++;
	ft_printf_fd(1, "rrr\n");
}
