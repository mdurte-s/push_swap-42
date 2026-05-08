/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:18:08 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/21 16:27:55 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "libft.h"

void	test(unsigned int i, char *s);

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	write(1, "test: ", 6);
	ft_striteri(argv[1], &test);
	return (0);
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void	test(unsigned int i, char *s)
{
	(void)i;
	write(1, &s[0], 1);
}*/
