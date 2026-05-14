/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:54:14 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/14 13:55:03 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	count_strings(char const *s, char c)
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