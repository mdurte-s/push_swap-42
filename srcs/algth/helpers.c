/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:49:21 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/19 17:51:35 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_distance_min_top(t_list *current)
{
	int	i;
	int	distance;
	int	min;

	i = 0;
	distance = 0;
	min = current->content;
	while (current)
	{
		if (current->content < min)
		{
			distance = i;
			min = current->content;
		}
		i++;
		current = current->next;
	}
	return (distance);
}

int	get_distance_max_top(t_list *current)
{
	int	i;
	int	distance;
	int	max;

	i = 0;
	distance = 0;
	max = current->content;
	while (current)
	{
		if (current->content > max)
		{
			distance = i;
			max = current->content;
		}
		i++;
		current = current->next;
	}
	return (distance);
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