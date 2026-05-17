/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:38:35 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/15 12:10:50 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		is_split;

	stack_a = NULL;
	stack_b = NULL;
	is_split = 0;
	if (argc == 1)
		return (1);
	if (check_argv(argc, &argv, &stack_a, &is_split) == 0)
	{
		if (is_split == 1)
			free_array(argv);
		return (ft_putstr_fd("Error\n", 2), ft_lstclear(&stack_a, del), 1);
	}
	swap_a(&stack_a);
	push_b(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	ft_lstclear(&stack_a, del);
	ft_lstclear(&stack_b, del);
	if (is_split == 1)
		free_array(argv);
	return (0);
}

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list	*new_a;
	t_list	*new_b;

	new_a = stack_a;
	new_b = stack_b;
	while (new_a || new_b)
	{
		if (new_a)
		{
			ft_printf("%d", *new_a->content);
			new_a = new_a->next;
		}
		else
			ft_printf(" ");
		ft_printf(" | ");
		if (new_b)
		{
			ft_printf("%d", *new_b->content);
			new_b = new_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("_ | _\na | b\n\n");
}

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}
