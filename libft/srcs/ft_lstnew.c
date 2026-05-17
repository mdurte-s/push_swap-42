/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:17:53 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/14 15:19:04 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*int	main(void)
{
	t_list	*node;
	
	node = ft_lstnew("Hello");
	if (node)
		printf("node: %s\n", (char *)node->content);
	else
		printf("error");
	return (0);
}*/

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

t_list	*ft_lstnew_ps(int index, int bench, int strategy, int *nb)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->index = index;
	lst->bench = bench;
	lst->strategy = strategy;
	lst->content = nb;
	lst->next = NULL;
	return (lst);
}
