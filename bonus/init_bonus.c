/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:53:34 by igomes-d          #+#    #+#             */
/*   Updated: 2026/06/03 13:59:27 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_ctx	*get_ctx(t_ctx *init)
{
	static t_ctx	*ctx;

	if (init)
		return (ctx = init, init);
	return (ctx);
}

void	init(t_ctx *ctx)
{
	ft_bzero(ctx, sizeof(t_ctx));
	get_ctx(ctx);
}
