/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:37:26 by mdurte-s          #+#    #+#             */
/*   Updated: 2026/05/20 23:09:41 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

/* --- includes ------------------------------------------------------------- */

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/* --- typedef -------------------------------------------------------------- */

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_ctx
{
	t_list			*stack_a;
	t_list			*stack_b;
	int				total_a;
	int				total_b;
}					t_ctx;

/* --- functions ------------------------------------------------------------ */

void				init(t_ctx *ctx);
void				rev_rotate_a(t_ctx *init);
void				rev_rotate_b(t_ctx *init);
void				rev_rotate_r(t_ctx *init);
void				rotate_a(t_ctx *init);
void				rotate_b(t_ctx *init);
void				rotate_r(t_ctx *init);
int					wrapper_op(void (*f)(t_ctx *), char *b, int *i);
int					compute_ops(char *b, int *i);
int					parser_ops(void);
void				push_list(t_list **from, t_list **to, int to_size);
void				push_a(t_ctx *init);
void				push_b(t_ctx *init);
void				ft_lstclear(t_list **lst);
t_list				*ft_lstnew(int content);
void				ft_bzero(void *s, size_t n);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new_node);
void				swap_a(t_ctx *init);
void				swap_b(t_ctx *init);
void				swap_s(t_ctx *init);
char				*argv_to_int(char *argv, int *nb);
int					check_repeated(t_list *stack_a, int nb);
int					parser_argv(char **argv, int start_i, int max_i,
						t_ctx *ctx);

#endif
