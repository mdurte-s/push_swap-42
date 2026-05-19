/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesure_disorder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:17:26 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/19 16:26:19 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	mesure_disorder(t_ctx *ctx)
{
	int		mistakes;
	int		total_pairs;
	t_list	*stack_i;
	t_list	*stack_j;

	mistakes = 0;
	total_pairs = 0;
	stack_i = ctx->stack_a;
	while (stack_i->next)
	{
		stack_j = stack_i->next;
		while (stack_j)
		{
			if (stack_i->content >= stack_j->content)
				mistakes++;
			stack_j = stack_j->next;
			total_pairs++;
		}
		stack_i = stack_i->next;
	}
	ctx->bench.disorder = (double)100 * (double)mistakes / (double)total_pairs;
	update_bench_strategy(ctx);
}

void	update_bench_strategy(t_ctx *ctx)
{
	if (ctx->strategy == 0 || ctx->strategy == 4)
	{
		if ((int)ctx->bench.disorder <= 30)
		{
			ctx->strategy = 1 + 4;
			return ;
		}
		else if ((int)ctx->bench.disorder <= 80)
		{
			ctx->strategy = 2 + 4;
			return ;
		}
		else
			ctx->strategy = 3 + 4;
	}
}
