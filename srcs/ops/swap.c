/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:37:48 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/28 16:04:59 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Swap the first two elements at the top of stack a.
Do nothing if there is only one or no elements. */
void	core_swap_a(int ss)
{
	t_ctx	*ctx;
	t_node	tmp;
	size_t	i;

	ctx = get_ctx(0);
	if (ctx->a.len > 1)
	{
		i = _i(&ctx->a, 1);
		tmp = ctx->a.arr[ctx->a.start];
		ctx->a.arr[ctx->a.start] = ctx->a.arr[i];
		ctx->a.arr[i] = tmp;
	}
	if (ss)
		return ;
	ctx->bench.total_ops++;
	ctx->bench.sa++;
	ft_printf_fd(1, "sa\n");
}
void	swap_a(void)
{
	core_swap_a(0);
}

/* Swap the first two elements at the top of stack b.
Do nothing if there is only one or no elements */
void	core_swap_b(int ss)
{
	t_ctx	*ctx;
	t_node	tmp;
	size_t	i;

	ctx = get_ctx(0);
	if (ctx->b.len > 1)
	{
		i = _i(&ctx->b, 1);
		tmp = ctx->b.arr[ctx->b.start];
		ctx->b.arr[ctx->b.start] = ctx->b.arr[i];
		ctx->b.arr[i] = tmp;
	}
	if (ss)
		return ;
	ctx->bench.total_ops++;
	ctx->bench.sb++;
	ft_printf_fd(1, "sb\n");
}

void	swap_b(void)
{
	core_swap_b(0);
}

/* sa and sb at the same time. */
void	swap_s(void)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	core_swap_a(1);
	core_swap_b(1);
	ctx->bench.total_ops++;
	ctx->bench.ss++;
	ft_printf_fd(1, "ss\n");
}
