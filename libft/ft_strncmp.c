/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:31:05 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/24 11:15:45 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	main(int argc, char **argv)
{
	size_t	n;

	n = 3;
	if (argc != 3)
		return (0);
	if (ft_strncmp(argv[1], argv[2], n) == 0)
		printf("The strings are equal.\n");
	else if (ft_strncmp(argv[1], argv[2], n) > 0)
		printf("The first string is greater.\n");
	if (ft_strncmp(argv[1], argv[2], n) < 0)
		printf("The second string is greater.\n");
	return (0);
}*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && i < n - 1 && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
