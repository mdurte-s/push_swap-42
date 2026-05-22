/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:26:38 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/11 19:54:11 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*int	main(int argc, char **argv)
{
	size_t			len;
	unsigned char	*return_value;

	(void)argc;
	len = 3;
	printf("starting adress: %s\nvalue to be filled: %c\n", 
		&argv[1][2], argv[2][0]);
	return_value = (unsigned char *)ft_memset(&argv[1][2], argv[2][0], len);
	printf("return: %s\n", return_value);
	return (0);
}*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bb;
	unsigned char	cc;

	bb = (unsigned char *)b;
	cc = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		bb[i] = cc;
		i++;
	}
	return (b);
}
