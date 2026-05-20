/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:15:39 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/20 19:35:06 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_includes/checker.h"

int	parser_ops(char *line)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		return (swap_a(0, 0), 1);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		return (swap_b(0, 0), 1);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		return (swap_s(0), 1);
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		return (push_a(0), 1);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		return (push_b(0), 1);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		return (rotate_a(0, 0), 1);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		return (rotate_b(0, 0), 1);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		return (rotate_r(0), 1);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		return (rev_rotate_a(0, 0), 1);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		return (rev_rotate_b(0, 0), 1);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		return (rev_rotate_r(0), 1);
	else
		return (0);
}

void	mesure_disorder(t_ctx *ctx)
{
	int		mistakes;
	int		total_pairs;
	t_list	*stack_i;
	t_list	*stack_j;

	mistakes = 0;
	total_pairs = 0;
	stack_i = ctx->stack_a;
	while (stack_i && stack_i->next)
	{
		stack_j = stack_i->next;
		while (stack_j)
		{
			if (stack_i->content >= stack_j->content)
				mistakes++;
			stack_j = (total_pairs++, stack_j->next);
		}
		stack_i = stack_i->next;
	}
	if (total_pairs == 0)
		ctx->bench.disorder = 0;
	else
		ctx->bench.disorder = (double)100 * (double)mistakes
			/ (double)total_pairs;
}

int	create_stack(char **argv, int index, t_ctx *ctx)
{
	int		nb;
	t_list	*new;

	while (argv[index])
	{
		if (argv_to_int(argv[index], &nb) == 0)
			return (0);
		new = ft_lstnew(nb);
		if (!new)
			return (0);
		ft_lstadd_back(&(ctx->stack_a), new);
		(ctx->total_a)++;
		index++;
	}
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
	if (!argv[0] || argv[i] != '\0')
		return (0);
	*nb = (int)(res * signal);
	return (1);
}