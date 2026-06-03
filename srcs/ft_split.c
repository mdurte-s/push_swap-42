/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:14:42 by igomes-d          #+#    #+#             */
/*   Updated: 2026/06/03 13:37:55 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
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
