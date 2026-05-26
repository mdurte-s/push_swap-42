/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 10:41:04 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/26 14:25:43 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
