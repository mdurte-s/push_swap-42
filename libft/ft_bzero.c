/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:21:33 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/29 13:48:42 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	main(int argc, char **argv)
{
	size_t			n;
	unsigned char	*return_value;

	(void)argc;
	n = 3;
	printf("starting adress: %s\n", &argv[1][2]);
	return_value = (unsigned char *)ft_bzero(&argv[1][2], n);
	printf("return: %s\n", return_value);
	return (0);
}*/

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ss;

	ss = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ss[i] = 0;
		i++;
	}
}
