/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:21:18 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/20 22:46:22 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		printf("atoi('%s') = %d\n", argv[i], ft_atoi(argv[i]));
	return (0);
}*/

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	n;

	i = 0;
	s = 1;
	n = 0;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		s = s * (44 - str[i]);
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * s);
}
