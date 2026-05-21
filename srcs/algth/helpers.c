/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:49:21 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/21 11:48:45 by mdurte-s         ###   ########.fr       */
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

/* Takes the distance from get_distance and determines which is the faster path
to get the node with the specified value to the top of the stack and moves it.
If distance <= 0.5 * total_length -> rotate; Else reverse rotate. */
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
