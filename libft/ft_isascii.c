/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:24:00 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/23 17:13:54 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

int	ft_isascii(char c);

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		printf("'%c' is ascii? %d\n", argv[i][0], ft_isascii(argv[i][0]));
	return (0);
}*/

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	else
		return (0);
}
