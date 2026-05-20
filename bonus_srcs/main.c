/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 10:41:04 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/20 19:26:00 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_includes/checker.h"

void	init(t_ctx *ctx)
{
	ft_bzero(ctx, sizeof(t_ctx));
	push_a(ctx);
	push_b(ctx);
	swap_a(ctx, 0);
	swap_b(ctx, 0);
	swap_s(ctx);
	rotate_a(ctx, 0);
	rotate_b(ctx, 0);
	rotate_r(ctx);
	rev_rotate_a(ctx, 0);
	rev_rotate_b(ctx, 0);
	rev_rotate_r(ctx);
}

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

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	init(&ctx);
	if (argc == 1)
		return (0);
	if (!create_stack(argv, 1, &ctx))
		return (ft_printf_fd(2, "Error\n"), ft_lstclear(&(ctx.stack_a)), 1);
	if (check_repeated(ctx.stack_a) == 0)
		return (ft_printf_fd(2, "Error\n"), ft_lstclear(&(ctx.stack_a)), 1);
	if (!get_ops(&ctx))
		return (ft_printf_fd(2, "Error\n"), ft_lstclear(&(ctx.stack_a)),
			ft_lstclear(&(ctx.stack_b)), 1);
	mesure_disorder(&ctx);
	if (!ctx.bench.disorder && !ctx.total_b)
		ft_printf_fd(1, "OK\n");
	else
		ft_printf_fd(1, "KO\n");
	ft_lstclear(&ctx.stack_a);
	ft_lstclear(&ctx.stack_b);
	return (0);
}
