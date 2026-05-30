/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:50:42 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/30 18:51:59 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_fit_distance(t_stk *stk, int val)
{
	int	prev_nb;
	int	curr_nb;
	int	i;

	i = 0;
	while (i < stk->len)
	{
		prev_nb = stk->arr[_i(stk, i - 1)].nb;
		curr_nb = stk->arr[_i(stk, i)].nb;
		if (curr_nb < val && val < prev_nb)
			return (i);
		i++;
	}
	return (0);
}

int	move_to_top_dual(int di_a, int di_b, t_ctx *ctx)
{
	if (di_a > ctx->a.len - di_a && di_b > ctx->b.len - di_b)
	{
		di_a = ctx->a.len - di_a;
		di_b = ctx->b.len - di_b;
		if (di_b > di_a)
		{
			rev_rotate_r(di_a);
			di_a = 0;
			di_b -= di_a;
		}
		else
		{
			rev_rotate_r(di_b);
			di_b = 0;
			di_a -= di_b;
		}
		return (rev_rotate_a(di_a), rev_rotate_b(di_b), 0);
	}
	else if (di_a <= ctx->a.len - di_a && di_b <= ctx->b.len - di_b)
	{
		if (di_b > di_a)
		{
			rotate_r(di_a);
			di_a = 0;
			di_b -= di_a;
		}
		else
		{
			rotate_r(di_b);
			di_b = 0;
			di_a -= di_b;
		}
		return (rotate_a(di_a), rotate_b(di_b), 0);
	}
	move_to_top(di_a, ctx->a.len, 1);
	move_to_top(di_b, ctx->b.len, 0);
	return (0);
}

void	get_less_distance(t_ctx *ctx, int *di_a, int *di_b)
{
	int	d_a;
	int	d_b;

	*di_a = 0;
	*di_b = get_fit_distance(&ctx->b, ctx->a.arr[ctx->a.start].nb);
	d_a = *di_a;
	d_b = *di_b;
	while (++d_a < ctx->a.len)
	{
		d_b = get_fit_distance(&ctx->b, ctx->a.arr[_i(&ctx->a, d_a)].nb);
		if (comparable_distance(d_a, d_b, ctx) < comparable_distance(*di_a,
				*di_b, ctx))
		{
			*di_a = d_a;
			*di_b = d_b;
		}
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

	move_to_top(get_distance(&ctx->a, ctx->min), ctx->a.len, 1);
	push_b();
	print_stacks(ctx);
	move_to_top(get_distance(&ctx->a, ctx->max), ctx->a.len, 1);
	push_b();
	print_stacks(ctx);
	rotate_b(1);
	print_stacks(ctx);
	while (ctx->a.len > 0)
	{
		get_less_distance(ctx, &di_a, &di_b);
		/* move_to_top_dual(9, get_fit_distance(&ctx->b, ctx->a.arr[_i(&ctx->a,
					9)].nb), ctx); */
		move_to_top_dual(di_a, di_b, ctx);
		push_b();
		print_stacks(ctx);
	}
	move_to_top(get_distance(&ctx->b, ctx->max), ctx->b.len, 0);
	while (ctx->b.len > 0)
		push_a();
}
