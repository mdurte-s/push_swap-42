/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algth_adaptive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:42:37 by igomes-d          #+#    #+#             */
/*   Updated: 2026/06/03 14:36:41 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	mesure_disorder(t_ctx *ctx)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = -1;
	while (++i + 1 < ctx->a.len)
	{
		j = i;
		while (++j < ctx->a.len)
		{
			total_pairs++;
			if (ctx->a.arr[i].nb > ctx->a.arr[j].nb)
				mistakes++;
		}
	}
	if (total_pairs == 0)
		ctx->bench.disorder = 0;
	else
		ctx->bench.disorder = (double)100 * (double)mistakes
			/ (double)total_pairs;
	update_bench_strategy(ctx);
}

void	update_bench_strategy(t_ctx *ctx)
{
	if (ctx->strategy == 0 || ctx->strategy == 4)
	{
		if ((int)ctx->bench.disorder < 20)
			ctx->strategy = 1 + 4;
		else if ((int)ctx->bench.disorder < 50)
			ctx->strategy = 2 + 4;
		else
			ctx->strategy = 3 + 4;
	}
}

void	disorder_based_sort(t_ctx *ctx)
{
	if (ctx->strategy == 4 + 1)
		low_disorder_optimized_insertion_sort(ctx);
	else if (ctx->strategy == 4 + 2)
		bucket_sort(ctx);
	else
		intro_sort(ctx);
}
