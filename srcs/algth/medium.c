/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 12:34:30 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/30 14:14:48 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_index_bucket(int num)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	return ((num - ctx->min) / ctx->div);
}

int	get_bucket_distance(t_list *current, int bucket)
{
	int	i;

	i = 0;
	while (current)
	{
		if (get_index_bucket(current->content) == bucket)
			return (i);
		i++;
		current = current->next;
	}
	return (-1);
}

/* void	get_less_distance_rev(t_ctx *ctx, int *di_a, int *di_b)
{
	int		d_a;
	int		d_b;
	t_list	*current;

	*di_a = get_fit_distance(ctx->stack_a, ctx->stack_b->content, 1);
	*di_b = 0;
	d_a = *di_a;
	d_b = *di_b;
	current = ctx->stack_b->next;
	while (current)
	{
		d_a = get_fit_distance(ctx->stack_a, current->content, 1);
		d_b = get_distance(ctx->stack_b, current->content);
		if (comparable_distance(d_a, d_b, ctx) < comparable_distance(*di_a,
				*di_b, ctx))
		{
			*di_a = d_a;
			*di_b = d_b;
		}
		current = current->next;
	}
} */

/* void	medium(t_ctx *ctx)
{
	int	di_a;
	int	di_b;
	int	buckets_size;
	int	i;

	buckets_size = get_index_bucket(ctx->max);
	i = 0;
	while (i <= buckets_size)
	{
		di_a = get_bucket_distance(ctx->stack_a, i);
		if (di_a == -1 && i++ >= 0)
			continue ;
		move_to_top(di_a, ctx->total_a, 1);
		push_b();
	}
	move_to_top(get_distance(ctx->stack_b, ctx->max), ctx->total_b, 0);
	push_a();
	move_to_top(get_distance(ctx->stack_b, ctx->min), ctx->total_b, 0);
	push_a();
	while (ctx->total_b > 0)
	{
		get_less_distance_rev(ctx, &di_a, &di_b);
		(move_to_top_dual(di_a, di_b, ctx), push_a());
	}
	move_to_top(get_distance(ctx->stack_a, ctx->min), ctx->total_a, 1);
} */
