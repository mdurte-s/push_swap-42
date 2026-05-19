/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char_str_nbr_ptr_flt.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:36:17 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/19 14:13:22 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	put_char(int c, int *counter, int fd)
{
	write(fd, &c, 1);
	(*counter)++;
}

void	put_str(char *str, int *counter, int fd)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		put_char(str[i], counter, fd);
		i++;
	}
}

void	put_nbr(long int nb, char *base, int *counter, int fd)
{
	if (strlen_printf(base) > 1 && validate_dup_sign(base) == 1)
	{
		if (nb < 0)
		{
			put_char('-', counter, fd);
			nb = nb * -1;
		}
		if (nb >= (long int)strlen_printf(base))
			put_nbr(nb / (long int)strlen_printf(base), base, counter, fd);
		put_char(base[nb % (long int)strlen_printf(base)], counter, fd);
	}
}

void	put_ptr(void *ptr, int *c, int fd)
{
	if (ptr == 0)
		put_str("(nil)", c, fd);
	else if (ptr == (void *)LONG_MIN)
		put_str("0x8000000000000000", c, fd);
	else if (ptr == (void *)ULONG_MAX)
		put_str("0xffffffffffffffff", c, fd);
	else
	{
		put_str("0x", c, fd);
		put_nbr((long int)ptr, "0123456789abcdef", c, fd);
	}
}

void	put_flt(double nb, char *base, int *counter, int fd)
{
	int			precision;
	long int	int_part;
	long int	frc_part;

	precision = 2;
	if (nb < 0)
	{
		put_char('-', counter, fd);
		nb = nb * -1;
	}
	int_part = (long int)nb;
	frc_part = (long int)((nb - int_part) * power_nb(10, precision) + 0.5);
	if (frc_part >= power_nb(10, precision))
	{
		int_part++;
		frc_part = 0;
	}
	put_nbr(int_part, base, counter, fd);
	put_char('.', counter, fd);
	put_frc_part(frc_part, precision, counter, fd);
}
