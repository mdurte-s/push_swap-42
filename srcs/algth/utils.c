/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 12:36:29 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/28 23:12:16 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Returns the max value of the stack. */
int	get_max(t_stk *stk, int size)
{
	int	max;
	int	nb;
	int	i;

	max = stk->arr[stk->start].nb;
	i = 0;
	while (++i < stk->len && --size > 0)
	{
		nb = stk->arr[_i(stk, i)].nb;
		if (nb > max)
			max = nb;
	}
	return (max);
}

/* Returns the min value of the stack. */
int	get_min(t_stk *stk, int size)
{
	int	min;
	int	nb;
	int	i;

	min = stk->arr[stk->start].nb;
	i = 0;
	while (++i < stk->len && --size > 0)
	{
		nb = stk->arr[_i(stk, i)].nb;
		if (nb < min)
			min = nb;
	}
	return (min);
}

int	ft_sqrt(int nb)
{
	long long	count;
	long long	check;

	if (nb <= 0)
		return (0);
	check = 1;
	count = 1;
	while (check < nb)
	{
		count++;
		check = count * count;
	}
	if (check == nb)
		return (count);
	return (count - 1);
}
