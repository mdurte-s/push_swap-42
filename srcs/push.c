/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:39:49 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/11 12:23:34 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty. */
void	push_a(t_list **stack_a, t_list **stack_b)
{
    if (!stack_a || !stack_b || !stack_b)
        return ;
    ft_lstadd_front(stack_a, *stack_b);
    *stack_b = (*stack_b) -> next;
}

/* Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty. */
void	push_b(t_list **stack_a, t_list **stack_b)
{
    if (!stack_b || !stack_a || !stack_a)
        return ;
    ft_lstadd_front(stack_b, *stack_a);
    *stack_a = (*stack_a) -> next;
}
