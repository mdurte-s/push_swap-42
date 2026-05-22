/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:54:05 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/22 20:42:40 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	parser_argv(char **argv, t_ctx *ctx)
{
	int	flags;

	if (parser_flags(argv, &flags, ctx) == 0)
		return (0);
	while (flags && check_flag(*argv) == 1)
	{
		argv++;
		flags--;
	}
	if (!create_stack(&argv, ctx))
		return (0);
	while (flags)
	{
		argv++;
		flags--;
		if (*argv && !flags)
			return (0);
	}
	if (check_repeated(ctx->stack_a) == 0)
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
			if (j->content == i->content)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

int	create_stack(char ***argv, t_ctx *ctx)
{
	char	**temp_argv;

	while (*argv && **argv)
	{
		if (count_strings(**argv, ' ') == 0)
			return (0);
		if (check_flag(**argv) == 1)
			break ;
		temp_argv = ft_split(**argv, ' ');
		if (add_to_stack(temp_argv, ctx) == 0)
			return (free_array(temp_argv), 0);
		free_array(temp_argv);
		(*argv)++;
	}
	return (1);
}

int	parser_flags(char **av, int *f, t_ctx *ctx)
{
	int	i;

	i = -1;
	while (av[++i])
	{
		if (ft_strncmp(av[i], "--", 2))
			continue ;
		else if (ctx->bench.is_bench && !ft_strncmp(&av[i][2], "bench", 6))
			return (0);
		else if (!ft_strncmp(&av[i][2], "bench", 6))
			ctx->bench.is_bench = 1;
		else if (ctx->strategy)
			return (0);
		else if (!ft_strncmp(&av[i][2], "simple", 7))
			ctx->strategy = 1;
		else if (!ft_strncmp(&av[i][2], "medium", 7))
			ctx->strategy = 2;
		else if (!ft_strncmp(&av[i][2], "complex", 8))
			ctx->strategy = 3;
		else if (!ft_strncmp(&av[i][2], "adaptive", 9))
			ctx->strategy = 4;
	}
	return (*f = (ctx->bench.is_bench == 1) + (ctx->strategy != 0), 1);
}
