/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:31:18 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/22 15:17:14 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	main(void)
{
	t_list	*lst = NULL;

	ft_lstadd_front(&lst, ft_lstnew("1"));
	ft_lstadd_front(&lst, ft_lstnew("2"));
	ft_lstadd_front(&lst, ft_lstnew("3"));
	t_list *last = ft_lstlast(lst);
	printf("last: %s\n", (char *)(last->content));
	return (0);
}*/

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
