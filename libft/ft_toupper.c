/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:52:42 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/20 22:51:08 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

int	ft_toupper(int c);

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		printf("toupper('%c') = %c\n", argv[i][0], ft_toupper(argv[i][0]));
	return (0);
}*/

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	else
		return (c);
}
