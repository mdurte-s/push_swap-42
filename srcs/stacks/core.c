/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 08:59:26 by igomes-d          #+#    #+#             */
/*   Updated: 2026/06/02 15:06:03 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
