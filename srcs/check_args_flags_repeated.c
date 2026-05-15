/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_flags_repeated.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:54:05 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/15 11:23:16 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_argv(int argc, char **argv, t_list **stack_a)
{
	int		index;
	int		bench;
	int		strategy;

	bench = 0;
	strategy = 0;
	if (check_flags(argv, &index, &bench, &strategy) == 0)
		return (0);
	if (check_first_argv(&argc, &argv, &index) == 0)
		return (0);
	*stack_a = create_stack(argv, index, bench, strategy);
	if (!stack_a)
		return (0);
	if (check_repeated(*stack_a) == 0)
		return (0);
	return (1);
}

int	check_repeated(t_list *stack_a)
{
	t_list	*i;
	t_list	*j;

	i = stack_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (*j->content == *i->content)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

int	check_first_argv(int *argc, char ***argv, int *index)
{
	if (*index + 2 == *argc && ft_strchr((*argv)[(*index) + 1], ' '))
	{
		*argc = (int)count_strings((*argv)[(*index) + 1], ' ');
		*argv = ft_split((*argv)[(*index) + 1], ' ');
		*index = -1;
		return (1);
	}
	else if (*index + 2 != *argc && ft_strchr((*argv)[(*index) + 1], ' '))
		return (0);
	else
		return (1);
}

int	check_flags(char **av, int *i, int *b, int *s)
{
	int	x;

	x = -1;
	while (av[++x])
	{
		if (ft_strncmp(av[x], "--bench", (size_t)15) == 0 && *b != 0)
			return (0);
		else if ((ft_strncmp(av[x], "--simple", (size_t)15) == 0
				|| ft_strncmp(av[x], "--medium", (size_t)15) == 0
				|| ft_strncmp(av[x], "--complex", (size_t)15) == 0
				|| ft_strncmp(av[x], "--adaptative", (size_t)15) == 0)
			&& *s != 0)
			return (0);
		else if (ft_strncmp(av[x], "--bench", (size_t)15) == 0 && *b == 0)
			*b = 1;
		else if (ft_strncmp(av[x], "--simple", (size_t)15) == 0 && *s == 0)
			*s = 1;
		else if (ft_strncmp(av[x], "--medium", (size_t)15) == 0 && *s == 0)
			*s = 2;
		else if (ft_strncmp(av[x], "--complex", (size_t)15) == 0 && *s == 0)
			*s = 3;
		else if (ft_strncmp(av[x], "--adaptative", (size_t)15) == 0 && *s == 0)
			*s = 4;
	}
	return (*i = (*b == 1) + (*s != 0), 1);
}
