/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:54:14 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/15 12:08:15 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*create_stack(char **argv, int index, int bench, int strategy)
{
	int		*nb;
	t_list	*stack;
	t_list	*new;

	nb = 0;
	stack = NULL;
	while (index != -1)
	{
		argv++;
		(index)--;
	}
	while (argv[++index])
	{
		nb = (int *)malloc(sizeof(int));
		if (!nb)
			return (free(nb), ft_lstclear(&stack, del), NULL);
		if (argv_to_int(argv[index], nb) == 0)
			return (free(nb), ft_lstclear(&stack, del), NULL);
		new = ft_lstnew_ps(index, bench, strategy, nb);
		if (!new)
			return (free(nb), ft_lstclear(&stack, del), NULL);
		ft_lstadd_back(&stack, new);
	}
	return (stack);
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
		if (ft_isdigit(argv[i + 1]) == 0)
			return (0);
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

size_t	count_strings(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count_str;

	i = 0;
	count_str = 0;
	while (s[i])
	{
		j = 1;
		if (s[i] != c)
		{
			count_str++;
			while (s[i + j] != c && s[i + j])
				j++;
		}
		i = i + j;
	}
	return (count_str);
}
