/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:35:52 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/18 12:01:13 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conversion(char flag, va_list arg, int *c, int fd)
{
	if (flag == 'c')
		put_char(va_arg(arg, int), c, fd);
	else if (flag == 's')
		put_str(va_arg(arg, char *), c, fd);
	else if (flag == 'p')
		put_ptr(va_arg(arg, void *), c, fd);
	else if (flag == 'd' || flag == 'i')
		put_nbr((long int)va_arg(arg, int), "0123456789", c, fd);
	else if (flag == 'u')
		put_nbr((long int)va_arg(arg, unsigned int), "0123456789", c, fd);
	else if (flag == 'x')
		put_nbr((long int)va_arg(arg, unsigned int), "0123456789abcdef", c, fd);
	else if (flag == 'X')
		put_nbr((long int)va_arg(arg, unsigned int), "0123456789ABCDEF", c, fd);
	else if (flag == '%')
		put_char('%', c, fd);
}

int	validate(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
