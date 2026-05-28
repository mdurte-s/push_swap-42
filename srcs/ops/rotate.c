/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:41:25 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/28 14:25:48 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Shift up all elements of stack a by one.
The first element becomes the last one. */
void	core_rotate_a(int rr)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	if (ctx->a.len > 1)
		ctx->a.start = _i(&ctx->a, -1);
	if (rr)
		return ;
	ctx->bench.total_ops++;
	ctx->bench.ra++;
	ft_printf_fd(1, "ra\n");
}

void	rotate_a(void)
{
	core_rotate_a(0);
}

/* Shift up all elements of stack b by one.
The first element becomes the last one. */
void	core_rotate_b(int rr)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	if (ctx->b.len > 1)
		ctx->b.start = _i(&ctx->a, -1);
	if (rr)
		return ;
	ctx->bench.total_ops++;
	ctx->bench.rb++;
	ft_printf_fd(1, "rb\n");
}

void	rotate_b(void)
{
	core_rotate_b(0);
}

/* ra and rb at the same time. */
void	rotate_r(void)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	core_rotate_a(1);
	core_rotate_b(1);
	ctx->bench.total_ops++;
	ctx->bench.rr++;
	ft_printf_fd(1, "rr\n");
}
