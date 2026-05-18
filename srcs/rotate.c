/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:41:25 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/18 19:05:41 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Shift up all elements of stack a by one.
The first element becomes the last one. */
void	rotate_a(t_ctx *ctx, int rr)
{
	t_list	*temp_1;
	t_list	*temp_2;
	t_list	*temp_3;

	if (ctx->total_a > 1)
	{
		temp_1 = ctx->stack_a;
		temp_2 = ctx->stack_a->next;
		temp_3 = ft_lstlast(ctx->stack_a);
		ctx->stack_a = temp_2;
		temp_3->next = temp_1;
		temp_1->next = NULL;
	}
	if (rr)
		return ;
	ctx->bench.total++;
	ctx->bench.ra++;
	ft_printf_fd(1, "ra\n");
}

/* Shift up all elements of stack b by one.
The first element becomes the last one. */
void	rotate_b(t_ctx *ctx, int rr)
{
	t_list	*temp_1;
	t_list	*temp_2;
	t_list	*temp_3;

	if (ctx->total_b > 1)
	{
		temp_1 = ctx->stack_b;
		temp_2 = ctx->stack_b->next;
		temp_3 = ft_lstlast(ctx->stack_b);
		ctx->stack_b = temp_2;
		temp_3->next = temp_1;
		temp_1->next = NULL;
	}
	if (rr)
		return ;
	ctx->bench.total++;
	ctx->bench.rb++;
	ft_printf_fd(1, "rb\n");
}

/* ra and rb at the same time. */
void	rotate_r(t_ctx *ctx)
{
	rotate_a(ctx, 1);
	rotate_b(ctx, 1);
	ctx->bench.total++;
	ctx->bench.rr++;
	ft_printf_fd(1, "rr\n");
}
