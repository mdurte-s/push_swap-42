/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:36:07 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/18 12:01:26 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

int		ft_printf_fd(int fd, const char *str, ...);

int		strlen_printf(char *str);
int		validate(char c);

void	put_char(int c, int *counter, int fd);
void	put_str(char *str, int *counter, int fd);
void	put_ptr(void *ptr, int *counter, int fd);
void	put_nbr(long int nb, char *base, int *ccounter, int fd);
void	conversion(char c, va_list arg, int *counter, int fd);

#endif
