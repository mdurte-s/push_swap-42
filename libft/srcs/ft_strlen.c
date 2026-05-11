/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:48:42 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/11 19:54:53 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		printf("strlen('%s') = %zu\n", argv[i], ft_strlen(argv[i]));
	return (0);
}*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
