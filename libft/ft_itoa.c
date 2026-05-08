/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:34:27 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/24 11:11:33 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	module(int n);
static size_t	intlen(int n);

/*int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("int: %d\n", ft_atoi(argv[1]));
	printf("char: %s\n", ft_itoa(ft_atoi(argv[1])));
	return (0);
}*/

char	*ft_itoa(int n)
{
	char		*str;
	size_t		i;
	size_t		x;
	size_t		nn;

	i = intlen(n);
	x = 0;
	if (n < 0)
		x = 1;
	nn = module(n);
	str = (char *)malloc((i + 1 + x) * sizeof(char));
	if (!str)
		return (0);
	str[0] = '-';
	str[i + x] = '\0';
	while (--i + 1)
	{
		str[i + x] = nn % 10 + 48;
		nn = nn / 10;
	}
	return (str);
}

static size_t	intlen(int n)
{
	size_t	i;

	i = 1;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static size_t	module(int n)
{
	long int	int_min;

	if (n == -2147483648)
	{
		int_min = n;
		return ((size_t)(int_min * -1));
	}
	else if (n < 0)
		return ((size_t)(n * -1));
	return ((size_t)n);
}
