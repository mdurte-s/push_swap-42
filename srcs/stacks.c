/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 08:59:26 by igomes-d          #+#    #+#             */
/*   Updated: 2026/06/03 13:01:52 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	clear(void)
{
	t_ctx	*ctx;

	ctx = get_ctx(0);
	if (ctx->a.arr)
		ctx->a.arr = (free(ctx->a.arr), NULL);
	if (ctx->b.arr)
		ctx->b.arr = (free(ctx->b.arr), NULL);
}

int	check_dup(t_stk *stk, int nb)
{
	ssize_t	i;

	i = -1;
	while (++i < stk->len)
		if (stk->arr[i].nb == nb)
			return (1);
	return (0);
}

int	add_stk(t_stk *stk, int nb)
{
	t_node	*tmp;
	ssize_t	new_capacity;

	if (check_dup(stk, nb))
		return (-1);
	if (stk->len + 1 > stk->capacity)
	{
		new_capacity = (stk->capacity + 1000) * 1.5;
		tmp = (t_node *)malloc(new_capacity * sizeof(t_node));
		if (!tmp)
			return (-1);
		if (stk->arr)
			(ft_memcpy(tmp, stk->arr, stk->len * sizeof(t_node)),
				free(stk->arr));
		stk->capacity = new_capacity;
		stk->arr = tmp;
	}
	stk->arr[stk->len++].nb = nb;
	return (0);
}

ssize_t	_i(t_stk *stk, ssize_t index)
{
	ssize_t	len;

	len = stk->len;
	return ((stk->start + ((index % len + len) % len)) % stk->capacity);
}

void	rotate_stk(t_stk *stk, int amount)
{
	ssize_t	target_index;
	ssize_t	capacity;
	ssize_t	len;

	len = stk->len;
	capacity = stk->capacity;
	if (amount > 0)
	{
		while (amount--)
		{
			stk->arr[(stk->start + len) % capacity] = stk->arr[stk->start];
			stk->start = (stk->start + 1) % capacity;
		}
		return ;
	}
	amount = -amount;
	while (amount--)
	{
		target_index = (stk->start + len - 1) % capacity;
		stk->start = (stk->start - 1 + capacity) % capacity;
		stk->arr[stk->start] = stk->arr[target_index];
	}
}
