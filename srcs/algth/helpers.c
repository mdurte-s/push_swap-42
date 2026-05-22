/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:49:21 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/21 12:34:26 by igomes-d         ###   ########.fr       */
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
int	fix_distance(int distance, int total)
{
	if (distance > total - distance)
		distance = total - distance;
	return (distance);
}
