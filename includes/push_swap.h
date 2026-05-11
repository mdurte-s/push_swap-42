/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurte-s <mdurte-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:37:26 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/11 22:11:11 by mdurte-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* --- includes ------------------------------------------------------------- */

# include "../libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"

/* --- functions ------------------------------------------------------------ */

void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_s(t_list **stack_a, t_list **stack_b);

void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);

void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_r(t_list **stack_a, t_list **stack_b);

void	rev_rotate_a(t_list **stack_a);
void	rev_rotate_b(t_list **stack_b);
void	rev_rotate_r(t_list **stack_a, t_list **stack_b);

int		validate_arg(int argc, char **argv, t_list **stack_a);
int		argv_to_int(char *argv, int *nb);
void	print_stacks(t_list *stack_a, t_list *stack_b);

#endif
