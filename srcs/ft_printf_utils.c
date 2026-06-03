/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 11:37:17 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/06/03 13:24:36 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	validate_dup_sign(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		j = i + 1;
		while (str[j] != str[i] && str[j] != '\0')
			j++;
		if (str[j] == str[i])
			return (0);
		i++;
	}
	return (1);
}

double	power_nb(int base, int exp)
{
	double	res;

	res = 1;
	while (exp--)
		res *= base;
	return (res);
}

void	put_frc_part(int frc_part, int precision, int *counter, int fd)
{
	int			len;
	long int	tmp;

	len = 0;
	tmp = frc_part;
	while (tmp)
	{
		tmp = tmp / 10;
		len++;
	}
	while (precision - len)
	{
		put_char('0', counter, fd);
		len++;
	}
	if (frc_part)
		put_nbr(frc_part, "0123456789", counter, fd);
}
