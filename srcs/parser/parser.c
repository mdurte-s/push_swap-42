/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:54:05 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/22 19:49:39 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	parser_argv(int argc, char **argv, t_ctx *ctx)
{
	int	index;

	argc++;
	// char	**temp_argv;
	if (parser_flags(argv, &index, ctx) == 0)
		return (0);
	if (parser_split(argc, &argv, &index) == 0)
		return (0);
	if (create_stack(argv, index, ctx) == 0)
		return (free_array(argv), 0);
	// while (++argv)
	// {
	// 	if (count_strings(*argv, ' ') == 0)
	// 		break ;
	// 	temp_argv = ft_split(*argv, ' ');
	// 	create_stack(temp_argv, index, ctx);
	// }
	// free(temp_argv);
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

int	parser_split(int argc, char ***argv, int *index)
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

int	parser_flags(char *str, t_ctx *ctx)
{
	if (!ft_strncmp(str, "--bench", 15) && ctx->bench.is_bench)
		return (0);
	else if ((!ft_strncmp(str, "--simple", 9) || !ft_strncmp(str, "--medium", 9)
			|| !ft_strncmp(str, "--complex", 10) || !ft_strncmp(str,
				"--adaptive", 11)) && ctx->strategy)
		return (0);
	else if (!ft_strncmp(str, "--bench", 8))
		return (ctx->bench.is_bench = 1);
	else if (!ft_strncmp(str, "--simple", 9))
		return (ctx->strategy = 1, 1);
	else if (!ft_strncmp(str, "--medium", 9))
		return (ctx->strategy = 2, 1);
	else if (!ft_strncmp(str, "--complex", 10))
		return (ctx->strategy = 3, 1);
	else if (!ft_strncmp(str, "--adaptive", 11))
		return (ctx->strategy = 4, 1);
	return (2);
}

int	parser_flags_w(char **av, int *s, int *e, t_ctx *ctx)
{
	int	i;
	int	r;

	*e = -1;
	*s = -1;
	i = -1;
	while (av[++i])
	{
		r = parser_flags(av[i], ctx);
		if (r == 0)
			return (0);
		else if (r == 2 && *e == -1 && *s != -1)
			*e = i - 1;
		else if (r == 1)
			*s = i;
	}
	return (1);
}
