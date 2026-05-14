/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:54:05 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/14 17:47:11 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	validate_arg(int argc, char **argv, t_list **stack_a)
{
	int		index;
	int		bench;
	int		strategy;
	int		*nb;
	t_list	*new;

	nb = 0;
	bench = 0;
	strategy = 0;
	if (check_flags(argv, &index, &bench, &strategy) == 0)
		return (0);
	if (check_first_argv(&argc, &argv, &index) == 0)
		return (0);
	while (++index < argc)
	{
		nb = (int *)malloc(sizeof(int));
		if (!nb)
			return (0);
		if (argv_to_int(argv[index], nb) == 0)
			return (0);
		new = ft_lstnew_ps(&index, &bench, &strategy, nb);
		if (!new)
			return (0);
		ft_lstadd_back(stack_a, new);
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

int	argv_to_int(char *argv, int *nb)
{
	int		i;
	int		signal;
	long	res;

	i = 0;
	signal = 1;
	res = 0;
	if (argv[i] == '-' || argv[i] == '+')
	{
		signal = 44 - argv[i];
		i++;
	}
	while ('0' <= argv[i] && argv[i] <= '9')
	{
		res = res * 10 + argv[i] - '0';
		if (!(-2147483648 <= (res * signal) && (res * signal) <= 2147483647))
			return (0);
		i++;
	}
	if (argv[i] != '\0')
		return (0);
	*nb = (int)(res * signal);
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
	*i = (*b == 1) + (*s != 0);
	return (1);
}
