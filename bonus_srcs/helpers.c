/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 10:49:42 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/21 10:57:45 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_includes/checker.h"

int	get_ops(t_ctx *ctx)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!parser_ops(line))
			return (free(line), 0);
		mesure_disorder(ctx);
		if (!ctx->bench.disorder && !ctx->total_b)
			break ;
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (1);
}

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
