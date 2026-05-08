/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:31:30 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/29 12:45:37 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	main(int argc, char **argv)
{
	(void)argc;
	ft_strrchr(argv[1], argv[2][0]);
	printf("return: %s\n", ft_strrchr(argv[1], (int)argv[2][0]));
	return (0);
}*/

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[i]);
	while (i + 1)
	{
		if ((char)c == s[i])
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
