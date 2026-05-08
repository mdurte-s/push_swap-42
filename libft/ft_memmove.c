/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:24:43 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/27 10:26:46 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	main(int argc, char **argv)
{
	size_t	n;

	n = 10;
	if (argc == 3)
	{
		printf("dst: %s\nsrc: %s\n", argv[1], argv[2]);
		printf("return: %s\n", (unsigned char *)ft_memmove(argv[1], argv[2], n));
	}
	return (0);
}*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dd;
	unsigned char	*ss;

	dd = (unsigned char *)dst;
	ss = (unsigned char *)src;
	if (!dd && !ss)
		return (0);
	if (dd < ss)
	{
		i = 0;
		while (i < len)
		{
			dd[i] = ss[i];
			i++;
		}
	}
	else
	{
		while (len--)
			dd[len] = ss[len];
	}
	return (dst);
}
