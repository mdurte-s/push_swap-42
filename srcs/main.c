/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:38:35 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/11 12:38:39 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printf_stack(t_list *stack);

int	main(int argc, char **argv)
{
	t_list	**stack_a = NULL;
	t_list	**stack_b = NULL;

	if (argc == 1)
		return (1);
	if (validate_arg(argc, argv, stack_a) ==  0)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	swap_a(stack_a);
	swap_b(stack_b);
	swap_s(stack_a, stack_b);
	
	/* push_a(stack_a, stack_b);
	push_b(stack_a, stack_b); */

	/* rotate_a(stack_a);
	rotate_b(stack_b);
	rotate_r(stack_a, stack_b); */

	/* rev_rotate_a(stack_a);
	rev_rotate_b(stack_b);
	rev_rotate_r(stack_a, stack_b); */
	
	printf_stack(*stack_a);
	printf_stack(*stack_b);

	return (0);
}

void	printf_stack(t_list *stack)
{
	t_list	*new;

	new = stack;
	while (new)
	{
		ft_printf("%s\n", (int *)(new->content));
		new = new->next;
	}
	ft_printf("NULL\n");
}
