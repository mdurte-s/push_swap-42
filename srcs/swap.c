/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:37:48 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/18 19:05:30 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Swap the first two elements at the top of stack a.
Do nothing if there is only one or no elements. */
void	swap_a(t_ctx *ctx, int ss)
{
	t_list	*temp_1;
	t_list	*temp_2;
	t_list	*temp_3;

	if (ctx->total_a > 1)
	{
		temp_1 = (ctx->stack_a);
		temp_2 = (ctx->stack_a)->next;
		temp_3 = (ctx->stack_a)->next->next;
		ctx->stack_a = temp_2;
		ctx->stack_a->next = temp_1;
		ctx->stack_a->next->next = temp_3;
	}
	if (ss)
		return ;
	ctx->bench.total++;
	ctx->bench.sa++;
	ft_printf_fd(1, "sa\n");
}

/* Swap the first two elements at the top of stack b.
Do nothing if there is only one or no elements */
void	swap_b(t_ctx *ctx, int ss)
{
	t_list	*temp_1;
	t_list	*temp_2;
	t_list	*temp_3;

	if (ctx->total_b > 1)
	{
		temp_1 = (ctx->stack_b);
		temp_2 = (ctx->stack_b)->next;
		temp_3 = (ctx->stack_b)->next->next;
		ctx->stack_b = temp_2;
		ctx->stack_b->next = temp_1;
		ctx->stack_b->next->next = temp_3;
	}
	if (ss)
		return ;
	ctx->bench.total++;
	ctx->bench.sb++;
	ft_printf_fd(1, "sb\n");
}

/* sa and sb at the same time. */
void	swap_s(t_ctx *ctx)
{
	swap_a(ctx, 1);
	swap_b(ctx, 1);
	ctx->bench.total++;
	ctx->bench.ss++;
	ft_printf_fd(1, "ss\n");
}
