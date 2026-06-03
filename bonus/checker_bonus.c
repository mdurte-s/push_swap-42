/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:38:35 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/06/03 14:23:12 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	wrapper_op(void (*f)(void), char *b, int *i)
{
	f();
	*i = 0;
	b[0] = 0;
	b[1] = 0;
	b[2] = 0;
	b[3] = 0;
	return (1);
}

int	compute_ops(char *b, int *i)
{
	if (b[0] == 'p' && b[1] == 'a' && b[2] == '\n')
		return (wrapper_op(push_a, b, i));
	if (b[0] == 'p' && b[1] == 'b' && b[2] == '\n')
		return (wrapper_op(push_b, b, i));
	if (b[0] == 's' && b[1] == 'a' && b[2] == '\n')
		return (wrapper_op(swap_a, b, i));
	if (b[0] == 's' && b[1] == 'b' && b[2] == '\n')
		return (wrapper_op(swap_b, b, i));
	if (b[0] == 's' && b[1] == 's' && b[2] == '\n')
		return (wrapper_op(swap_s, b, i));
	if (b[0] == 'r' && b[1] == 'a' && b[2] == '\n')
		return (wrapper_op(rotate_a, b, i));
	if (b[0] == 'r' && b[1] == 'b' && b[2] == '\n')
		return (wrapper_op(rotate_b, b, i));
	if (b[0] == 'r' && b[1] == 'r' && b[2] == '\n')
		return (wrapper_op(rotate_r, b, i));
	if (b[0] == 'r' && b[1] == 'r' && b[2] == 'a' && b[3] == '\n')
		return (wrapper_op(rev_rotate_a, b, i));
	if (b[0] == 'r' && b[1] == 'r' && b[2] == 'b' && b[3] == '\n')
		return (wrapper_op(rev_rotate_b, b, i));
	if (b[0] == 'r' && b[1] == 'r' && b[2] == 'r' && b[3] == '\n')
		return (wrapper_op(rev_rotate_r, b, i));
	return (0);
}

int	parser_ops(void)
{
	char	read_buf[1024];
	char	op_buf[4];
	int		op_i;
	int		i;
	int		length_read;

	op_buf[0] = 0;
	op_i = 0;
	length_read = read(0, read_buf, 1024);
	while (length_read > 0)
	{
		i = -1;
		while (++i < length_read)
		{
			op_buf[op_i] = read_buf[i];
			if ((op_buf[op_i] != '\n' && op_i > 2) || (op_buf[op_i] == '\n'
					&& op_i < 2))
				return (0);
			if (op_buf[op_i++] == '\n')
				if (compute_ops(op_buf, &op_i) == 0)
					return (0);
		}
		length_read = read(0, read_buf, 1024);
	}
	return (op_buf[0] == 0);
}

int	main(int argc, char **argv)
{
	t_ctx	ctx;
	t_list	*lst;

	if (argc <= 1)
		return (0);
	init(&ctx);
	if (parser_argv(argv, 1, argc, &ctx) == 0)
		return (write(2, "Error\n", 6), ft_lstclear(&(ctx.stack_a)), 1);
	if (parser_ops() == 0)
		return (write(2, "Error\n", 6), ft_lstclear(&(ctx.stack_a)),
			ft_lstclear(&(ctx.stack_b)), 1);
	if (ctx.total_b != 0)
		return (write(1, "KO\n", 3), ft_lstclear(&(ctx.stack_a)),
			ft_lstclear(&(ctx.stack_b)), 0);
	lst = ctx.stack_a;
	while (lst && lst->next)
	{
		if (lst->content > lst->next->content)
			return (write(1, "KO\n", 3), ft_lstclear(&(ctx.stack_a)),
				ft_lstclear(&(ctx.stack_b)), 0);
		lst = lst->next;
	}
	write(1, "OK\n", 3);
	return (ft_lstclear(&(ctx.stack_a)), ft_lstclear(&(ctx.stack_b)), 0);
}
