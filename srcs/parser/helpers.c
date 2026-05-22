/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:54:14 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/22 20:58:50 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_flag(char *str)
{
	if (ft_strncmp(str, "--bench", 8) != 0
		&& ft_strncmp(str, "--simple", 9) != 0
		&& ft_strncmp(str, "--medium", 9) != 0
		&& ft_strncmp(str, "--complex", 10) != 0
		&& ft_strncmp(str, "--adaptive", 11) != 0)
		return (0);
	return (1);
}

int	add_to_stack(char **argv, t_ctx *ctx)
{
	int		index;
	int		nb;
	t_list	*new;

	index = -1;
	while (argv[++index])
	{
		if (argv_to_int(argv[index], &nb) == 0)
			return (0);
		new = ft_lstnew(nb);
		if (!new)
			return (0);
		ft_lstadd_back(&(ctx->stack_a), new);
		(ctx->total_a)++;
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

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}
