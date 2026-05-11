/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:37:48 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/11 22:35:02 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Swap the first two elements at the top of stack a.
Do nothing if there is only one or no elements. */
void	swap_a(t_list **stack_a)
{
	t_list	*temp_1;
	t_list	*temp_2;
	t_list	*temp_3;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	temp_1 = (*stack_a);
	temp_2 = (*stack_a)->next;
	temp_3 = (*stack_a)->next->next;
	(*stack_a) = temp_2;
	(*stack_a)->next = temp_1;
	(*stack_a)->next->next = temp_3;
	ft_printf("sa\n");
}

/* Swap the first two elements at the top of stack b.
Do nothing if there is only one or no elements */
void	swap_b(t_list **stack_b)
{
	t_list	*temp_1;
	t_list	*temp_2;
	t_list	*temp_3;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	temp_1 = (*stack_b);
	temp_2 = (*stack_b)->next;
	temp_3 = (*stack_b)->next->next;
	(*stack_b) = temp_2;
	(*stack_b)->next = temp_1;
	(*stack_b)->next->next = temp_3;
	ft_printf("sb\n");
}

/* sa and sb at the same time. */
void	swap_s(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
