/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:28:58 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/22 21:40:37 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	main(int argc, char **argv)
{
	size_t	size;

	(void)argc;
	size = 20;
	printf("dest inicial: %s\nsrc: %s\n", 
		&argv[1][0], &argv[2][0]);
	printf("dest final: %s\nreturn: %zu\n", 
		&argv[1][0], ft_strlcat(argv[1], argv[2], size));
	return (0);
}*/

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t n)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (n <= len_d || n == 0)
		return (n + len_s);
	i = 0;
	while (src[i] != '\0' && i < n - len_d -1)
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = '\0';
	return (len_d + len_s);
}
