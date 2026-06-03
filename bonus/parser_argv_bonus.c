/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_argv_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:54:05 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/06/03 13:41:27 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*argv_to_int(char *argv, int *nb)
{
	long long	signal;
	long long	res;

	signal = 1;
	res = 0;
	while (*argv == ' ' || (*argv > 8 && *argv < 14))
		argv++;
	if (*argv == '-' || *argv == '+')
		signal = 44 - *(argv++);
	while ('0' <= *argv && *argv <= '9')
		res = res * 10 + *(argv++) - '0';
	if ((long long)-2147483648 > (res * signal) || (res
			* signal) > (long long)2147483647)
		return (0);
	*nb = (int)(res * signal);
	while (*argv == ' ' || (*argv > 8 && *argv < 14))
		argv++;
	if (*argv == '\0')
		return ((char *)1);
	if (*argv == '-' || *argv == '+' || ('0' <= *argv && *argv <= '9'))
		return (argv);
	return (0);
}

int	check_repeated(t_list *stack_a, int nb)
{
	t_list	*i;

	i = stack_a;
	while (i)
	{
		if (i->content == nb)
			return (0);
		i = i->next;
	}
	return (1);
}

int	parser_argv(char **argv, int start_i, int max_i, t_ctx *ctx)
{
	int		nb;
	int		i;
	t_list	*new;
	char	*j;

	i = start_i;
	while (i < max_i)
	{
		if (!argv[i] || argv[i][0] == 0)
			return (0);
		j = argv_to_int(argv[i], &nb);
		if (j == 0 || check_repeated(ctx->stack_a, nb) == 0)
			return (0);
		if (j != (char *)1)
			argv[i--] = j;
		new = ft_lstnew(nb);
		if (!new)
			return (0);
		ft_lstadd_back(&(ctx->stack_a), new);
		(ctx->total_a)++;
		i++;
	}
	return (1);
}
