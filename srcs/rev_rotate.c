/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:43:10 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/11 12:29:53 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Shift down all elements of stack a by one.
The last element becomes the first one. */
void	rev_rotate_a(t_list **stack_a)
{
    t_list *temp_1;
    t_list *temp_2;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return ;
    temp_1 = *stack_a;
    temp_2 = ft_lstlast(*stack_a);
    while ((*stack_a)->next)
    {
        if (!((*stack_a)->next->next))
        {
            (*stack_a)->next = NULL;
            break ;
        }
        (*stack_a) = (*stack_a)->next;
    }
    (*stack_a) = temp_2;
    (*stack_a)->next = temp_1;
}

/* Shift down all elements of stack b by one.
The last element becomes the first one. */
void	rev_rotate_b(t_list **stack_b)
{
    t_list *temp_1;
    t_list *temp_2;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return ;
    temp_1 = *stack_b;
    temp_2 = ft_lstlast(*stack_b);
    while ((*stack_b)->next)
    {
        if (!((*stack_b)->next->next))
        {
            (*stack_b)->next = NULL;
            break ;
        }
        (*stack_b) = (*stack_b)->next;
    }
    (*stack_b) = temp_2;
    (*stack_b)->next = temp_1;
}

/* rra and rrb at the same time. */
void	rev_rotate_r(t_list **stack_a, t_list **stack_b)
{
    rev_rotate_a(stack_a);
    rev_rotate_b(stack_b);
}
