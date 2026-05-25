/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:50:42 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/24 14:42:46 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_fit_distance(t_list *list, int val, int rev)
{
	int	i;

	i = 0;
	while (list)
	{
		if ((!list->prev || (list->prev && ((rev && val > list->prev->content)
						|| (!rev && val < list->prev->content)))) && ((rev
					&& list->content > val) || (!rev && list->content < val)))
			return (i);
		i++;
		list = list->next;
	}
	return (0);
}

void	move_rest_dual(int di_a, int di_b, int is_rr)
{
	if (is_rr)
		while (di_a--)
			rev_rotate_a(0);
	else
		while (di_a--)
			rotate_a(0);
	if (is_rr)
		while (di_b--)
			rev_rotate_b(0);
	else
		while (di_b--)
			rotate_b(0);
}

int	move_to_top_dual(int di_a, int di_b, t_ctx *ctx)
{
	if (di_a > ctx->total_a - di_a && di_b > ctx->total_b - di_b)
	{
		di_a = ctx->total_a - di_a;
		di_b = ctx->total_b - di_b;
		while (di_a > 0 && di_b > 0)
		{
			rev_rotate_r();
			di_a--;
			di_b--;
		}
		return (move_rest_dual(di_a, di_b, 1), 0);
	}
	else if (di_a <= ctx->total_a - di_a && di_b <= ctx->total_b - di_b)
	{
		while (di_a > 0 && di_b > 0)
		{
			rotate_r();
			di_a--;
			di_b--;
		}
		return (move_rest_dual(di_a, di_b, 0), 0);
	}
	move_to_top(di_a, ctx->total_a, 1);
	move_to_top(di_b, ctx->total_b, 0);
	return (0);
}

void	get_less_distance(t_ctx *ctx, int *di_a, int *di_b)
{
	int		d_a;
	int		d_b;
	t_list	*current;

	*di_a = 0;
	*di_b = get_fit_distance(ctx->stack_b, ctx->stack_a->content, 0);
	d_a = *di_a;
	d_b = *di_b;
	current = ctx->stack_a->next;
	while (current)
	{
		d_a = get_distance(ctx->stack_a, current->content);
		d_b = get_fit_distance(ctx->stack_b, current->content, 0);
		if (comparable_distance(d_a, d_b, ctx) < comparable_distance(*di_a,
				*di_b, ctx))
		{
			*di_a = d_a;
			*di_b = d_b;
		}
		current = current->next;
	}
}

/* SIMPLE ALGORITHM:
1 > gets the distance to min value of the stack_a, moves it to the top of
stack_a and pushes it to stack_b;
2 > gets the distance to max value of the stack_b, moves it to the top of
stack_a and pushes it to stack_b;
3 > sorts the number in stack_b:
	> gets the perfect position for the top value of stack_a in stack_b;
	> moves the perfect position of stack_b to top;
	> pushes the top value of stack_a to stack_b;
4 > gets the distance to max value of the stack_b, moves it to the top of
stack_b and pushes all stack_b to stack_a; */
void	simple(t_ctx *ctx)
{
	int	di_a;
	int	di_b;

	move_to_top(get_distance(ctx->stack_a, ctx->min), ctx->total_a, 1);
	push_b();
	move_to_top(get_distance(ctx->stack_a, ctx->max), ctx->total_a, 1);
	push_b();
	while (ctx->total_a > 0)
	{
		get_less_distance(ctx, &di_a, &di_b);
		move_to_top_dual(di_a, di_b, ctx);
		push_b();
	}
	move_to_top(get_distance(ctx->stack_b, ctx->max), ctx->total_b, 0);
	while (ctx->total_b > 0)
		push_a();
}
