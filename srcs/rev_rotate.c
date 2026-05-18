/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:43:10 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/18 19:05:56 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Shift down all elements of stack a by one.
The last element becomes the first one. */
void	rev_rotate_a(t_ctx *ctx, int rrr)
{
	t_list	*temp_1;
	t_list	*temp_2;

	if (ctx->total_a > 1)
	{
		temp_1 = ctx->stack_a;
		temp_2 = ft_lstlast(ctx->stack_a);
		while (ctx->stack_a->next->next)
			ctx->stack_a = ctx->stack_a->next;
		ctx->stack_a->next = NULL;
		ctx->stack_a = temp_2;
		ctx->stack_a->next = temp_1;
	}
	if (rrr)
		return ;
	ctx->bench.total++;
	ctx->bench.rra++;
	ft_printf_fd(1, "rra\n");
}

/* Shift down all elements of stack b by one.
The last element becomes the first one. */
void	rev_rotate_b(t_ctx *ctx, int rrr)
{
	t_list	*temp_1;
	t_list	*temp_2;

	if (ctx->total_b > 1)
	{
		temp_1 = ctx->stack_b;
		temp_2 = ft_lstlast(ctx->stack_b);
		while (ctx->stack_b->next->next)
			ctx->stack_b = ctx->stack_b->next;
		ctx->stack_b->next = NULL;
		ctx->stack_b = temp_2;
		ctx->stack_b->next = temp_1;
	}
	if (rrr)
		return ;
	ctx->bench.total++;
	ctx->bench.rrb++;
	ft_printf_fd(1, "rrb\n");
}

/* rra and rrb at the same time. */
void	rev_rotate_r(t_ctx *ctx)
{
	rev_rotate_a(ctx, 1);
	rev_rotate_b(ctx, 1);
	ctx->bench.total++;
	ctx->bench.rrr++;
	ft_printf_fd(1, "rrr\n");
}
