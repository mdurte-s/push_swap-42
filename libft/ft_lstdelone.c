/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:32:50 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/23 15:00:47 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	delete(void *content);
void	print_lst(t_list *lst);

int	main(void)
{
	t_list	*lst = NULL;
	t_list	*node1 = ft_lstnew(ft_strdup("1"));
	t_list	*node2 = ft_lstnew(ft_strdup("2"));
	t_list	*node3 = ft_lstnew(ft_strdup("3"));

	ft_lstadd_back(&lst, node1);
	ft_lstadd_back(&lst, node2);
	ft_lstadd_back(&lst, node3);
	print_lst(lst);
	node1->next = node2->next; //relinking nodes to print
	ft_lstdelone(node2, delete);
	print_lst(lst);
	return (0);
}*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*void	delete(void *content)
{
	free(content);
}

void	print_lst(t_list *lst)
{
	t_list	*new;

	new = lst;
	while (new)
	{
		printf("%s -> ", (char *)(new->content));
		new = new->next;
	}
	printf("NULL\n");
}*/
