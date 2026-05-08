/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:00:46 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/04/22 10:14:04 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	main(int argc, char **argv)
{
	int	fd;
	int	n;

	if (argc != 3)
		return (0);
	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	n = ft_atoi(argv[2]);
	if (fd < 0)
		return (1);
	ft_putnbr_fd(n, fd);
	return (0);
}*/

void	ft_putnbr_fd(int n, int fd)
{
	long int	long_n;

	long_n = n;
	if (long_n < 0)
	{
		ft_putchar_fd('-', fd);
		long_n = long_n * -1;
	}
	if (long_n > 9)
		ft_putnbr_fd(long_n / 10, fd);
	ft_putchar_fd(long_n % 10 + '0', fd);
}
