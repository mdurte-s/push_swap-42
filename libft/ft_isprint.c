/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:23:52 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/20 22:47:33 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

int ft_isprint(int c);

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		printf("'%c' is printable? %d\n", argv[i][0], ft_isprint(argv[i][0]));
	return (0);
}*/

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	else
		return (0);
}
