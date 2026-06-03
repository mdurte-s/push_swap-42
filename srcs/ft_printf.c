/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:36:29 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/06/03 13:26:37 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	else if (flag == 'f')
		put_flt(va_arg(arg, double), "0123456789", c, fd);
	else if (flag == '%')
		put_char('%', c, fd);
}

int	validate(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'f' || c == '%')
		return (1);
	return (0);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	int		c;
	int		i;
	va_list	args;

	c = 0;
	i = -1;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%' && validate(str[i + 1]) == 1)
		{
			conversion(str[i + 1], args, &c, fd);
			i++;
		}
		else
			put_char(str[i], &c, fd);
	}
	va_end(args);
	return (c);
}
