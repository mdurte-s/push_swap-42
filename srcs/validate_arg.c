/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:54:05 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/11 12:41:03 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int validate_arg(int argc, char **argv, t_list **stack_a)
{
    int     *i;
    int     *nb;
    t_list *new;
    
    i = 0;
    nb = 0;
    while (++(*i) < argc)
    {
        argv_to_int(argv[1], nb);
        if (nb == NULL)
            return (0);
        new = ft_lstnew(nb);
        if (!new)
            return (0);
        new->index = i;
        ft_lstadd_back(stack_a, new);
        i++;
    }
    return (1);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void    argv_to_int(char *argv, int *nb)
{
    int i;
    int signal; 
    
    i = 0;
    signal = 1;

    if (argv[i] == '-' || argv[i] == '+')
    {
        signal = 44 - argv[i];
        i++;
    }
    while ('0' <= argv[i] && argv[i] <= '9')
    {
        *nb = *nb * 10 + argv[i] - '0';
        i++;
    }
    if (argv[i] != '\0')
        *nb = 0; //queria que fosse NULL mas teria de mudar para void *
    else
        *nb = *nb * signal;
}
