/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:41:25 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/11 22:34:52 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Shift up all elements of stack a by one.
The first element becomes the last one. */
void	rotate_a(t_list **stack_a)
{
	t_list	*temp_1;
	t_list	*temp_2;
	t_list	*temp_3;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	temp_1 = (*stack_a);
	temp_2 = (*stack_a)->next;
	temp_3 = ft_lstlast(*stack_a);
	(*stack_a) = temp_2;
	temp_3->next = temp_1;
	temp_1->next = NULL;
	ft_printf("ra\n");
}

/* Shift up all elements of stack b by one.
The first element becomes the last one. */
void	rotate_b(t_list **stack_b)
{
	t_list	*temp_1;
	t_list	*temp_2;
	t_list	*temp_3;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	temp_1 = (*stack_b);
	temp_2 = (*stack_b)->next;
	temp_3 = ft_lstlast(*stack_b);
	(*stack_b) = temp_2;
	temp_3->next = temp_1;
	temp_1->next = NULL;
	ft_printf("rb\n");
}

/* ra and rb at the same time. */
void	rotate_r(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}
