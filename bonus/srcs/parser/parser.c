/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:54:05 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/27 11:46:43 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	create_stack(char ***argv, t_ctx *ctx)
{
	char	**temp_argv;

	while (*argv && **argv)
	{
		if (!count_strings(**argv, ' '))
			return (0);
		temp_argv = ft_split(**argv, ' ');
		if (!add_to_stack(temp_argv, ctx))
			return (free_array(temp_argv), 0);
		free_array(temp_argv);
		(*argv)++;
	}
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
		if (!argv_to_int(argv[index], &nb))
			return (0);
		new = ft_lstnew(nb);
		if (!new)
			return (0);
		if (!check_repeated(ctx, nb))
			return (0);
		ft_lstadd_back(&(ctx->stack_a), new);
		(ctx->total_a)++;
	}
	return (1);
}
