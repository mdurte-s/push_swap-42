/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:44:47 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/22 21:41:20 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	test(unsigned int i, char c);

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("test: %s\n", ft_strmapi(argv[1], test));
	return (0);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < ft_strlen(s))
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*char	test(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (ft_tolower(c));
	else
		return (ft_toupper(c));
}*/
