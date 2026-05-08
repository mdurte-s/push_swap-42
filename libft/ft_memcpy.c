/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:24:30 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/27 10:26:23 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	main(int argc, char **argv)
{
	size_t	n;

	n = 3;
	if (argc == 3)
	{
		printf("dst: %s\nsrc: %s\n", argv[1], argv[2]);
		printf("return: %s\n", (unsigned char *)ft_memcpy(argv[1], argv[2], n));
	}
	return (0);
}*/

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t			i;
	unsigned char	*dd;
	unsigned char	*ss;

	dd = (unsigned char *)dst;
	ss = (unsigned char *)src;
	if (!dd && !ss)
		return (0);
	i = 0;
	while (i < n)
	{
		dd[i] = ss[i];
		i++;
	}
	return (dst);
}
