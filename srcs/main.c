/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:38:35 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/25 19:58:50 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_ctx *ctx)
{
	ctx->min = get_min(ctx->stack_a);
	ctx->max = get_max(ctx->stack_a);
	ctx->sqrt = ft_sqrt(ctx->total_a);
	if ((ctx->sqrt / 4) > 0)
		ctx->div = (ctx->max - ctx->min) / (ctx->sqrt / 4);
	else
		ctx->div = ctx->max;
	complex_a(ctx, ctx->total_a, 1);
	// if (ctx->strategy == 1 || ctx->strategy == 4 + 1)
	// 	simple(ctx);
	// else if (ctx->strategy == 2 || ctx->strategy == 4 + 2)
	// 	medium(ctx);
	// else
	// 	medium(ctx);
}

int	get_media(t_list *stack, int total, int size)
{
	int	sum;
	int	media;

	sum = stack->content;
	while (stack->next && size--)
	{
		sum += stack->next->content;
		stack = stack->next;
	}
	media = sum / total;
	return (media);
}

int	get_less_media_distance(t_list *current, int media, int rev)
{
	int	i;

	i = 0;
	while (current)
	{
		if ((!rev && current->content < media) || (rev
				&& current->content > media))
			return (i);
		i++;
		current = current->next;
	}
	return (-1);
}

/* Sorts stack_b when total = 3 */
void	small_sort_b(t_ctx *ctx)
{
	int	start;
	int	middle;
	int	end;

	start = ctx->stack_b->content;
	middle = ctx->stack_b->next->content;
	end = ctx->stack_b->prev->content;
	if (start > middle && middle > end)
		return ;
	else if (start < middle && middle > end && start > end)
		swap_b(0);
	else if (start < middle && middle < end)
	{
		swap_b(0);
		rev_rotate_b(0);
	}
	else if (start > middle && middle < end && start > end)
	{
		swap_b(0);
		rotate_b(0);
	}
	else if (start < middle && middle > end && start < end)
		rotate_b(0);
	else if (start < middle && middle > end && start > end)
		rev_rotate_b(0);
}

/* Sorts stack_a when total = 3 */
void	small_sort_a(t_ctx *ctx)
{
	int	start;
	int	middle;
	int	end;

	start = ctx->stack_a->content;
	middle = ctx->stack_a->next->content;
	end = ctx->stack_a->prev->content;
	if (start < middle && middle < end)
		return ;
	else if (start > middle && middle < end && start < end)
		swap_a(0);
	else if (start > middle && middle > end)
	{
		swap_a(0);
		rev_rotate_a(0);
	}
	else if (start > middle && middle < end && start > end)
		rotate_a(0);
	else if (start < middle && middle > end && start < end)
	{
		swap_a(0);
		rotate_a(0);
	}
	else if (start < middle && middle > end && start > end)
		rev_rotate_a(0);
}

/* void	complex_b(t_ctx *ctx, int size)
	{
	int	rotates;
	int	pushes;
	int	media;
	int	pushes;
	int	media;
	int	media;
	int	pushes;
	int	media;
	int	pushes;

	if (size <= 1)
		return (push_a());
	if (size == 2)
	{
		if (ctx->stack_b->content < ctx->stack_b->next->content)
			swap_b(0);
		return ;
	}
	if (size == 3)
		return (small_sort_b(ctx));
	// media = get_media(ctx->stack_b, ctx->total_b, size);
	media = ctx->stack_b->content;
	rotates = 0;
	pushes = 0;
	while (size)
	{
		if (ctx->stack_b->content <= media)
		{
			rotates++;
			rotate_b(0);
		}
		else
		{
			pushes++;
			push_a();
		}
		size--;
	}
	while (rotates)
	{
		rotates--;
		rev_rotate_b(0);
	}
	// complex_a(ctx, pushes);
	complex_b(ctx, size - pushes);
	complex_a(ctx, pushes);
	} */

void	complex_a(t_ctx *ctx, int size, int is_a)
{
	int	pushes;
	int	media;

	if (size <= 1)
		return ;
	if (is_a)
		media = ctx->stack_a->content;
	else
		media = ctx->stack_b->content;
	pushes = 0;
	if (is_a)
	{
		while (size--)
		{
			if (ctx->stack_a->content >= media)
			{
				rotate_a(0);
			}
			else
			{
				push_b();
				pushes++;
			}
		}
	}
	else
	{
		while (size--)
		{
			if (ctx->stack_b->content < media)
			{
				rotate_b(0);
			}
			else
			{
				push_a();
				pushes++;
			}
		}
	}
	if (is_a)
	{
		complex_a(ctx, pushes -1, 0);
		complex_a(ctx, size - pushes -1, 1);
		//complex_a(ctx, pushes, 0);
	}
	else
	{
		//complex_a(ctx, pushes, 1);
		complex_a(ctx, size - pushes -1, 0);
		complex_a(ctx, pushes -1, 1);
	}
}

// void	complex_a(t_ctx *ctx)
// {
// 	int	media;
// 	int	i;
// 	int	di_a;
// 	int	di_b;

// 	while (ctx->total_a > 3)
// 	{
// 		media = get_media(ctx->stack_a, ctx->total_a);
// 		i = get_less_media_distance(ctx->stack_a, media, 0);
// 		while (i != -1)
// 		{
// 			move_to_top(i, ctx->total_a, 1);
// 			push_b();
// 			i = get_less_media_distance(ctx->stack_a, media, 0);
// 		}
// 	}
// 	while (ctx->total_a > 0)
// 		push_b();
// 	move_to_top(get_distance(ctx->stack_b, ctx->max), ctx->total_b, 0);
// 	push_a();
// 	move_to_top(get_distance(ctx->stack_b, ctx->min), ctx->total_b, 0);
// 	push_a();
// 	while (ctx->total_b > 0)
// 	{
// 		get_less_distance_rev(ctx, &di_a, &di_b);
// 		(move_to_top_dual(di_a, di_b, ctx), push_a());
// 	}
// 	move_to_top(get_distance(ctx->stack_a, ctx->min), ctx->total_a, 1);
// }

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc == 1)
		return (1);
	init(&ctx);
	if (parser_argv(++argv, &ctx) == 0)
		return (ft_printf_fd(2, "Error\n"), ft_lstclear(&(ctx.stack_a)), 1);
	mesure_disorder(&ctx);
	if (ctx.bench.disorder > 0)
		sort(&ctx);
	if (ctx.bench.is_bench == 1)
		print_bench(&ctx);
	// print_stacks(ctx.stack_a, ctx.stack_b);
	ft_lstclear(&ctx.stack_a);
	ft_lstclear(&ctx.stack_b);
	return (0);
}

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list	*new_a;
	t_list	*new_b;

	new_a = stack_a;
	new_b = stack_b;
	while (new_a || new_b)
	{
		if (new_a)
		{
			ft_printf_fd(2, "%d", new_a->content);
			new_a = new_a->next;
		}
		else
			ft_printf_fd(2, " ");
		ft_printf_fd(2, " | ");
		if (new_b)
		{
			ft_printf_fd(2, "%d", new_b->content);
			new_b = new_b->next;
		}
		ft_printf_fd(2, "\n");
	}
	ft_printf_fd(2, "_ | _\na | b\n\n");
}
