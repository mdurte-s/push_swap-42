/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:36:29 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/22 12:34:31 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

/* int	main(void)
{
	char			c = 'a';
	char			*str = "Hello World!";
	void			*ptr = &c;
	int				d = -42;
	int				i = 0x2a;
	unsigned int	u = 42;
	unsigned int	x = 42;
	unsigned int	xx = 42;
	double			f = 25.99999;

	ft_printf_fd(1, "char:              %c\n", c);
	ft_printf_fd(1, "string:            %s\n", str);
	ft_printf_fd(1, "void:              %p\n", ptr);
	ft_printf_fd(1, "decimal:           %d\n", d);
	ft_printf_fd(1, "integer:           %i\n", i);
	ft_printf_fd(1, "unsigned decimal:  %u\n", u);
	ft_printf_fd(1, "hexadecimal (low): %x\n", x);
	ft_printf_fd(1, "hexadecimal (up):  %X\n", xx);
	ft_printf_fd(1, "float:             %f\n", f);
	return (0);
} */
