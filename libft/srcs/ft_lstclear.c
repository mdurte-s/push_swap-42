/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:58:47 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/18 15:54:42 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*new;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		new = (*lst)->next;
		free(*lst);
		*lst = new;
	}
	*lst = NULL;
}
