/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 21:30:52 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/26 15:13:14 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

double	disorder(t_list *stack_a)
{
	int		mistakes;
	int		total_pairs;
	t_list	*stack_i;
	t_list	*stack_j;

	mistakes = 0;
	total_pairs = 0;
	stack_i = stack_a;
	while (stack_i && stack_i->next)
	{
		stack_j = stack_i->next;
		while (stack_j)
		{
			if (stack_i->content > stack_j->content)
				mistakes++;
			stack_j = (total_pairs++, stack_j->next);
		}
		stack_i = stack_i->next;
	}
	if (total_pairs == 0)
		return (0);
	else
		return ((double)100 * (double)mistakes / (double)total_pairs);
}

/* Sorts an array of integers */
void	sort_int_array(int **array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (++i < size)
	{
		if ((*array)[i - 1] > (*array)[i])
		{
			j = (*array)[i];
			(*array)[i] = (*array)[i - 1];
			(*array)[i - 1] = j;
			i = -1;
		}
	}
}

/* Returns the median value of the stack. -- versao temporaria */
int	get_median(t_list *stack, int total, int *median)
{
	int		i;
	int		*array;
	t_list	*ss;

	if (total <= 0 || !stack || !median)
		return (0);
	array = (int *)malloc(sizeof(int) * total);
	if (!array)
		return (0);
	ss = stack;
	i = -1;
	while (++i < total)
	{
		if (!ss)
			return (free(array), 0);
		array[i] = ss->content;
		ss = ss->next;
	}
	sort_int_array(&array, total);
	*median = array[total / 2];
	free(array);
	return (1);
}

/* Sorts stack_b when total = 3 */
/* void	small_sort_b(t_ctx *ctx)
{
	int	start;
	int	middle;
	int	end;

	start = ctx->stack_b->content;
	middle = ctx->stack_b->next->content;
	end = ctx->stack_b->prev->content;
	if (start > middle && middle > end) // 4 3 2
		return ;
	else if (start < middle && middle > end && start > end) // 3 4 2
		swap_b(0);
	else if (start < middle && middle < end) // 2 3 4
	{
		swap_b(0);
		rev_rotate_b(0);
	}
	else if (start > middle && middle < end && start > end) // 4 2 3
	{
		swap_b(0);
		rotate_b(0);
	}
	else if (start < middle && middle > end && start < end) // 2 4 3
		rotate_b(0);
	else if (start < middle && middle > end && start > end) // 3 2 4
		rev_rotate_b(0);
} */

/* Sorts stack_a when total = 3 */
/* void	small_sort_a(t_ctx *ctx)
{
	int	start;
	int	middle;
	int	end;

	start = ctx->stack_a->content;
	middle = ctx->stack_a->next->content;
	end = ctx->stack_a->prev->content;
	if (start < middle && middle < end) // 3 4 5
		return ;
	else if (start > middle && middle < end && start < end) // 4 3 5
		swap_a(0);
	else if (start > middle && middle > end) // 5 4 3
	{
		swap_a(0);
		rev_rotate_a(0);
	}
	else if (start > middle && middle < end && start > end) // 5 3 4
		rotate_a(0);
	else if (start < middle && middle > end && start < end) // 3 5 4
	{
		swap_a(0);
		rotate_a(0);
	}
	else if (start < middle && middle > end && start > end) // 4 5 3
		rev_rotate_a(0);
} */

/* int		quick_sort_a(t_ctx *ctx, int size);

int	quick_sort_b(t_ctx *ctx, int size)
{
	int	counter;
	int	median;
	int	psh_counter;
	int	rot_counter;

	if (ctx->total_b <= 1)
		return (1);
	if (ctx->total_b == 2)
	{
		if (ctx->stack_b->content < ctx->stack_b->next->content)
			swap_b(0, 0);
		return (1);
	}
	if (ctx->total_b == 3)
		return (small_sort_b(ctx), 1);
	if (!get_median(ctx->stack_b, ctx->total_b, &median))
		return (0);
	counter = -1;
	psh_counter = 0;
	rot_counter = 0;
	while (++counter < size)
	{
		if (ctx->stack_b->content >= median)
		{
			push_a(0);
			psh_counter++;
		}
		else
		{
			rotate_b(0, 0);
			rot_counter++;
		}
	}
	while (rot_counter)
	{
		rev_rotate_b(0, 0);
		rot_counter--;
	}
	print_stacks(ctx->stack_a, ctx->stack_b);
	if (!quick_sort_b(ctx, size - psh_counter))
		return (0);
	if (!quick_sort_a(ctx, psh_counter))
		return (0);
	return (1);
}

int	quick_sort_a(t_ctx *ctx, int size)
{
	int	counter;
	int	median;
	int	psh_counter;
	int	rot_counter;

	if (ctx->total_a <= 1)
		return (1);
	if (ctx->total_a == 2)
	{
		if (ctx->stack_a->content > ctx->stack_a->next->content)
			swap_a(0, 0);
		return (1);
	}
	if (ctx->total_a == 3)
		return (small_sort_a(ctx), 1);
	if (!get_median(ctx->stack_a, ctx->total_a, &median))
		return (ft_printf_fd(1, "get_median == 0\n"), 0);
	counter = -1;
	psh_counter = 0;
	rot_counter = 0;
	while (++counter < size)
	{
		if (ctx->stack_a->content < median)
		{
			push_b(0);
			psh_counter++;
		}
		else
		{
			rotate_a(0, 0);
			rot_counter++;
		}
	}
	while (rot_counter)
	{
		rev_rotate_a(0, 0);
		rot_counter--;
	}
	//print_stacks(ctx->stack_a, ctx->stack_b);
	if (disorder(ctx->stack_a) == (double)0
		&& disorder(ctx->stack_b) == (double)100)
	{
		while (ctx->total_b)
		{
			push_a(0);
			// psh_counter--;
		}
		return (1);
	}
	if (!quick_sort_a(ctx, size - psh_counter))
		return (ft_printf_fd(1, "quick_sort_b == 0\n"), 0);
	if (!quick_sort_b(ctx, psh_counter))
		return (ft_printf_fd(1, "quick_sort_a == 0\n"), 0);
	while (ctx->total_b)
	{
		push_a(0);
		// psh_counter--;
	}
	return (1);
}

int	complex(t_ctx *ctx)
{
	if (!quick_sort_a(ctx, ctx->total_a))
		return (ft_printf_fd(1, "quick_sort_a == 0\n"), 0);
	print_stacks(ctx->stack_a, ctx->stack_b);
	return (1);
} */
