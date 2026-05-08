/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:19:41 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/27 14:35:22 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_strings(char const *s, char c);
static size_t	find_substr_start(char const *s, char c);
static size_t	find_substr_end(char const *s, char c);
static char		*allocate_substr(char const *s, size_t j, char **ar, size_t cs);

/*int	main(int argc, char **argv)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = count_strings(argv[1], argv[2][0]);
	if (argc != 3)
		return (0);
	ft_split(argv[1], argv[2][0]);
	printf("string: %s\nsplit: %c\n", argv[1], argv[2][0]);
	while (i < c)
	{
		printf("string[%zu] = %s\n", i + 1, ft_split(argv[1], argv[2][0])[i]);
		i++;
	}
	return (0);
}*/

char	**ft_split(char const *s, char c)
{
	size_t	cs;
	size_t	i;
	size_t	j;
	char	**array;

	array = (char **)malloc((count_strings(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	cs = 0;
	i = 0;
	while (cs < count_strings(s, c))
	{
		i = i + find_substr_start(&s[i], c);
		j = find_substr_end(&s[i], c);
		array[cs] = allocate_substr(&s[i], j, array, cs);
		if (!array[cs])
		{
			free(array);
			return (NULL);
		}
		i = i + j;
		cs++;
	}
	array[cs] = NULL;
	return (array);
}

static char	*allocate_substr(const char *s, size_t j, char **array, size_t cs)
{
	char	*new;
	size_t	i;

	new = ft_substr(s, 0, j);
	if (!new)
	{
		i = 0;
		while (i < cs)
		{
			free(array[i]);
			i++;
		}
		return (NULL);
	}
	return (new);
}

static size_t	find_substr_end(char const *s, char c)
{
	size_t	j;

	j = 0;
	while (s[j] != c && s[j])
		j++;
	return (j);
}

static size_t	find_substr_start(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] == c && s[i])
		i++;
	return (i);
}

static size_t	count_strings(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count_str;

	i = 0;
	count_str = 0;
	while (s[i])
	{
		j = 1;
		if (s[i] != c)
		{
			count_str++;
			while (s[i + j] != c && s[i + j])
				j++;
		}
		i = i + j;
	}
	return (count_str);
}
