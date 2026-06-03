/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:09:11 by igomes-d          #+#    #+#             */
/*   Updated: 2026/06/03 13:50:25 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dd;
	unsigned char	*ss;

	dd = (unsigned char *)dst;
	ss = (unsigned char *)src;
	if (!dd && !ss)
		return (0);
	i = 0;
	while (i < n)
	{
		dd[i] = ss[i];
		i++;
	}
	return (dst);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && i < n - 1 && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ss;

	ss = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ss[i] = 0;
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s || *s == '\0')
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	len_s;
	size_t	i;
	char	*new;

	len_s = ft_strlen(s1);
	new = (char *)malloc((len_s + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
