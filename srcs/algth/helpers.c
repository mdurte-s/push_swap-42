/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:49:21 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/22 09:54:19 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Returns the max value of the stack. */
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

/* Returns the min value of the stack. */
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

/* Returns the distance (int) from the first current node to the node with the
value specified. */
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
int	fix_distance(int distance, int total)
{
	if (distance > total - distance)
		distance = total - distance;
	return (distance);
}
