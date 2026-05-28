/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 08:59:26 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/28 14:22:48 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

ssize_t	_i(t_stk *stk, ssize_t index)
{
	ssize_t	capacity;

	capacity = stk->capacity;
	if (index >= 0)
	{
		index = (stk->start + index) % capacity;
		if (stk->empty_s <= index && index <= stk->empty_e)
			return ((stk->empty_e + 1) % capacity);
	}
	else
	{
		index = (stk->start + index) % capacity;
		if (index < 0)
			index += capacity;
		if (stk->empty_s <= index && index <= stk->empty_e)
		{
			index = (stk->empty_s - 1) % capacity;
			if (index < 0)
				index += capacity;
		}
	}
	return (index);
}

ssize_t	push_i(t_stk *stk)
{
	ssize_t	empty_s;
	ssize_t	empty_e;
	ssize_t	capacity;
	ssize_t	index;

	capacity = stk->capacity;
	empty_s = stk->empty_s;
	empty_e = stk->empty_e;
	index = stk->start;
	if (index < empty_s)
	{
		stk->empty_s = (empty_s + 1) % capacity;
		while (index++ < empty_s)
			stk->arr[index] = stk->arr[index - 1];
	}
	else if (index > empty_e)
	{
		stk->empty_e = (empty_e - 1) % capacity;
		stk->start = --index;
		while (index-- > empty_e)
			stk->arr[index] = stk->arr[index + 1];
	}
	if (empty_e == empty_s)
		stk->empty_e = stk->empty_s;
	return (stk->start);
}
