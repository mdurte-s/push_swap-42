/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:23:07 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/23 17:48:31 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

int	ft_isalpha(char c);

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		printf("'%c' is alpha? %d\n", argv[i][0], ft_isalpha(argv[i][0]));
	return (0);
}*/

int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return (1);
	else
		return (0);
}
