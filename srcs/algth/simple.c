/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:50:42 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/22 09:53:48 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_fit_distance(t_list *current, int val)
{
	int	i;

	i = 0;
	while (current)
	{
		if ((!current->prev || (current->prev && val < current->prev->content))
			&& current->content < val)
			return (i);
		i++;
		current = current->next;
	}
	return (0);
}

void	move_rest_dual(int di_a, int di_b, int is_rr)
{
	while (di_a--)
	{
		if (is_rr)
			rev_rotate_a(0, 0);
		else
			rotate_a(0, 0);
	}
	while (di_b--)
	{
		if (is_rr)
			rev_rotate_b(0, 0);
		else
			rotate_b(0, 0);
	}
}

void	move_to_top(int distance, int total, void (*r)(t_ctx *, int),
		void (*rr)(t_ctx *, int))
{
	if (distance > total - distance)
	{
		distance = total - distance;
		while (distance--)
			rr(0, 0);
	}
	else
		while (distance--)
			r(0, 0);
}

int	move_to_top_dual(int di_a, int di_b, t_ctx *ctx)
{
	if (di_a > ctx->total_a - di_a && di_b > ctx->total_b - di_b)
	{
		di_a = ctx->total_a - di_a;
		di_b = ctx->total_b - di_b;
		while (di_a > 0 && di_b > 0)
		{
			rev_rotate_r(0);
			di_a--;
			di_b--;
		}
		return (move_rest_dual(di_a, di_b, 1), 0);
	}
	else if (di_a <= ctx->total_a - di_a && di_b <= ctx->total_b - di_b)
	{
		while (di_a > 0 && di_b > 0)
		{
			rotate_r(0);
			di_a--;
			di_b--;
		}
		return (move_rest_dual(di_a, di_b, 0), 0);
	}
	move_to_top(di_a, ctx->total_a, rotate_a, rev_rotate_a);
	move_to_top(di_b, ctx->total_b, rotate_b, rev_rotate_b);
	return (0);
}

void	get_less_distance(t_ctx *ctx, int *di_a, int *di_b)
{
	int		d_a;
	int		d_b;
	t_list	*current;

	*di_a = 0;
	*di_b = get_fit_distance(ctx->stack_b, ctx->stack_a->content);
	d_a = 0;
	d_b = *di_b;
	current = ctx->stack_a->next;
	while (current)
	{
		d_a = get_distance(ctx->stack_a, current->content);
		d_b = get_fit_distance(ctx->stack_b, current->content);
		if (fix_distance(d_a, ctx->total_a) + fix_distance(d_b,
				ctx->total_b) < fix_distance(*di_a, ctx->total_a)
			+ fix_distance(*di_b, ctx->total_b))
		{
			*di_a = d_a;
			*di_b = d_b;
		}
		current = current->next;
	}
}

void	move_rest_dual(int di_a, int di_b, int is_rr)
{
	while (di_a--)
	{
		if (is_rr)
			rev_rotate_a(0, 0);
		else
			rotate_a(0, 0);
	}
	while (di_b--)
	{
		if (is_rr)
			rev_rotate_b(0, 0);
		else
			rotate_b(0, 0);
	}
}

void	move_to_top(int distance, int total, void (*r)(t_ctx *, int),
		void (*rr)(t_ctx *, int))
{
	if (distance > total - distance)
	{
		distance = total - distance;
		while (distance--)
			rr(0, 0);
	}
	else
		while (distance--)
			r(0, 0);
}

int	move_to_top_dual(int di_a, int di_b, t_ctx *ctx)
{
	if (di_a > ctx->total_a - di_a && di_b > ctx->total_b - di_b)
	{
		di_a = ctx->total_a - di_a;
		di_b = ctx->total_b - di_b;
		while (di_a > 0 && di_b > 0)
		{
			rev_rotate_r(0);
			di_a--;
			di_b--;
		}
		return (move_rest_dual(di_a, di_b, 1), 0);
	}
	else if (di_a <= ctx->total_a - di_a && di_b <= ctx->total_b - di_b)
	{
		while (di_a > 0 && di_b > 0)
		{
			rotate_r(0);
			di_a--;
			di_b--;
		}
		return (move_rest_dual(di_a, di_b, 0), 0);
	}
	move_to_top(di_a, ctx->total_a, rotate_a, rev_rotate_a);
	move_to_top(di_b, ctx->total_b, rotate_b, rev_rotate_b);
	return (0);
}

void	get_less_distance(t_ctx *ctx, int *di_a, int *di_b)
{
	int		d_a;
	int		d_b;
	t_list	*current;

	*di_a = 0;
	*di_b = get_fit_distance(ctx->stack_b, ctx->stack_a->content);
	d_a = 0;
	d_b = *di_b;
	current = ctx->stack_a->next;
	while (current)
	{
		d_a = get_distance(ctx->stack_a, current->content);
		d_b = get_fit_distance(ctx->stack_b, current->content);
		if (fix_distance(d_a, ctx->total_a) + fix_distance(d_b,
				ctx->total_b) < fix_distance(*di_a, ctx->total_a)
			+ fix_distance(*di_b, ctx->total_b))
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
void	simple(t_ctx *ctx, int min, int max)
{
	int	di_a;
	int	di_b;

	move_to_top(get_distance(ctx->stack_a, min), ctx->total_a, rotate_a,
		rev_rotate_a);
	push_b(0);
	move_to_top(get_distance(ctx->stack_a, max), ctx->total_a, rotate_a,
		rev_rotate_a);
	push_b(0);
	while (ctx->total_a > 0)
	{
		get_less_distance(ctx, &di_a, &di_b);
		move_to_top_dual(di_a, di_b, ctx);
		push_b(0);
	}
	move_to_top(get_distance(ctx->stack_b, max), ctx->total_b, rotate_b,
		rev_rotate_b);
	while (ctx->total_b > 0)
		push_a(0);
}
