/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 12:36:29 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/24 12:43:41 by igomes-d         ###   ########.fr       */
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
