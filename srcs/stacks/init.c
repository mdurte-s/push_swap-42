/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 08:59:26 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/28 13:25:41 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stddef.h>

void	clear(void)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	if (ctx->a.arr)
		ctx->a.arr = (free(ctx->a.arr), NULL);
	if (ctx->b.arr)
		ctx->b.arr = (free(ctx->b.arr), NULL);
}

int	init_stk(t_stk *stk)
{
	ft_bzero(stk, sizeof(t_stk));
	stk->arr = (t_node *)malloc(8 * sizeof(t_node));
	if (stk->arr)
	{
		stk->capacity = 8;
	}
}
