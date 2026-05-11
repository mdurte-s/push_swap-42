/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:54:05 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/11 21:43:30 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	validate_arg(int argc, char **argv, t_list **stack_a)
{
	int		i;
	int		*nb;
	t_list	*new;

	i = 0;
	nb = 0;
	while (++i < argc)
	{
		nb = (int *)malloc(sizeof(int));
		if (!nb)
			return (0);
		if (argv_to_int(argv[i], nb) == 0)
			return (free(nb), 0);
		new = ft_lstnew(nb);
		if (!new)
			return (free(nb), 0);
		new->index = i;
		ft_lstadd_back(stack_a, new);
	}
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
