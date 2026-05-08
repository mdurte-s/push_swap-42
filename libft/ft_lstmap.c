/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:27:16 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/28 22:22:47 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	print_lst(t_list *lst);
void	del_content(void *content);
void	*dup_content(void *content);

int	main(void)
{
	t_list	*lst = NULL;
	t_list	*node1 = ft_lstnew(ft_strdup("1"));
	t_list	*node2 = ft_lstnew(ft_strdup("2"));
	t_list	*node3 = ft_lstnew(ft_strdup("3"));
	t_list	*mapped;

	ft_lstadd_back(&lst, node1);
	ft_lstadd_back(&lst, node2);
	ft_lstadd_back(&lst, node3);
	printf("Lista original:\n");
	print_lst(lst);
	mapped = ft_lstmap(lst, dup_content, del_content);
	printf("Lista mapeada:\n");
	print_lst(mapped);
	ft_lstclear(&lst, del_content);
	ft_lstclear(&mapped, del_content);
	return (0);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}

/*void	*dup_content(void *content)
{
	char	*str = (char *)content;
	char	*new;
	int		i = 0;

	new = malloc(ft_strlen(str) + 2);
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i++] = '!';
	new[i] = '\0';
	return (new);
}

void	del_content(void *content)
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
