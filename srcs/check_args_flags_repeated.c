/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_flags_repeated.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:54:05 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/18 17:40:04 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_argv(int argc, char **argv, t_ctx *ctx)
{
	int	index;

	if (check_flags(argv, &index, ctx) == 0)
		return (0);
	if (check_is_split(argc, &argv, &index) == 0)
		return (0);
	if (create_stack(argv, index, ctx) == 0)
		return (free_array(argv), 0);
	if (check_repeated(ctx->stack_a) == 0)
		return (free_array(argv), 0);
	return (free_array(argv), 1);
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
			if (j->content == i->content)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

int	check_is_split(int argc, char ***argv, int *index)
{
	if (ft_strchr((*argv)[*index], ' '))
	{
		if (*index + 1 != argc)
			return (0);
		else
		{
			*argv = ft_split((*argv)[*index], ' ');
			*index = 0;
		}
	}
	else
		(*argv)[0] = (char *)1;
	return (1);
}

int	check_flags(char **av, int *i, t_ctx *ctx)
{
	int	x;

	x = -1;
	while (av[++x])
	{
		if (ft_strncmp(av[x], "--bench", 15) == 0 && ctx->bench.is_bench != 0)
			return (0);
		else if ((ft_strncmp(av[x], "--simple", 9) == 0 || ft_strncmp(av[x],
					"--medium", 9) == 0 || ft_strncmp(av[x], "--complex",
					10) == 0 || ft_strncmp(av[x], "--adaptive", 11) == 0)
			&& ctx->strategy != 0)
			return (0);
		else if (ft_strncmp(av[x], "--bench", 8) == 0
			&& ctx->bench.is_bench == 0)
			ctx->bench.is_bench = 1;
		else if (ft_strncmp(av[x], "--simple", 9) == 0 && ctx->strategy == 0)
			ctx->strategy = 1;
		else if (ft_strncmp(av[x], "--medium", 9) == 0 && ctx->strategy == 0)
			ctx->strategy = 2;
		else if (ft_strncmp(av[x], "--complex", 10) == 0 && ctx->strategy == 0)
			ctx->strategy = 3;
		else if (ft_strncmp(av[x], "--adaptive", 11) == 0 && ctx->strategy == 0)
			ctx->strategy = 4;
	}
	return (*i = 1 + (ctx->bench.is_bench == 1) + (ctx->strategy != 0), 1);
}
