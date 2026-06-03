/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:37:48 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/06/03 13:04:27 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	core_swap_a(int ss)
{
	t_ctx	*ctx;
	t_node	tmp;
	size_t	i;

	ctx = get_ctx(0);
	if (ctx->a.len < 2)
		return ;
	i = (ctx->a.start + 1) % ctx->a.capacity;
	tmp = ctx->a.arr[ctx->a.start];
	ctx->a.arr[ctx->a.start] = ctx->a.arr[i];
	ctx->a.arr[i] = tmp;
	if (ss)
		return ;
	ctx->bench.total_ops++;
	ctx->bench.sa++;
	write(1, "sa\n", 3);
}

void	swap_a(void)
{
	core_swap_a(0);
}

void	core_swap_b(int ss)
{
	t_ctx	*ctx;
	t_node	tmp;
	size_t	i;

	ctx = get_ctx(0);
	if (ctx->b.len < 2)
		return ;
	i = (ctx->b.start + 1) % ctx->b.capacity;
	tmp = ctx->b.arr[ctx->b.start];
	ctx->b.arr[ctx->b.start] = ctx->b.arr[i];
	ctx->b.arr[i] = tmp;
	if (ss)
		return ;
	ctx->bench.total_ops++;
	ctx->bench.sb++;
	write(1, "sb\n", 3);
}

void	swap_b(void)
{
	core_swap_b(0);
}

void	swap_s(void)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	if (ctx->a.len < 2 && ctx->b.len < 2)
		return ;
	core_swap_a(1);
	core_swap_b(1);
	ctx->bench.total_ops++;
	ctx->bench.ss++;
	write(1, "ss\n", 3);
}
