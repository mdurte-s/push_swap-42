/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:24:20 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/27 10:15:07 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	main(int argc, char **argv)
{
	size_t	n;

	if (argc != 4)
		return (0);
	n = (size_t)ft_atoi(argv[3]);
	if (ft_memcmp(argv[1], argv[2], n) == 0)
		printf("The strings are equal.\n");
	else if (ft_memcmp(argv[1], argv[2], n) > 0)
		printf("The first string is greater.\n");
	else if (ft_memcmp(argv[1], argv[2], n) < 0)
		printf("The second string is greater.\n");
	return (0);
}*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	if (n == 0)
		return (0);
	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (ss1[i] == ss2[i] && i < n - 1)
		i++;
	return (ss1[i] - ss2[i]);
}
