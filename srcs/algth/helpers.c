/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:49:21 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/19 20:21:53 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_max(t_list *current)
{
	int	max;

	max = current->content;
	while (current)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	return (max);
}

int	get_min(t_list *current)
{
	int	min;

	min = current->content;
	while (current)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	return (min);
}

int	get_distance(t_list *current, int val)
{
	int	i;

	i = 0;
	while (current)
	{
		if (current->content == val)
			return (i);
		i++;
		current = current->next;
	}
	return (0);
}

void	move_to_top(int distance, int total, void (*r)(t_ctx *, int),
		void (*rr)(t_ctx *, int))
{
	if (distance > total - distance)
	{
		distance = total - distance;
		while (distance--)
			rr(0, 0);
	}
	else
		while (distance--)
			r(0, 0);
}
