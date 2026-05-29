/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-d <igomes-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 08:59:26 by igomes-d          #+#    #+#             */
/*   Updated: 2026/05/29 00:25:55 by igomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
|  -1 == empty_zone
|                                 v--start (9)
|  [0, 1, 2, -1, -1, -1, 6, 7, 8, 9, 10, 11, 12]
|
|  LOGICAL ORDER: [9, 10, 11, 12, 0, 1, 2, 6, 7, 8]
|  stk->len = 10, stk->capacity = 13
|
|             |--empty_s (3)
|             |       |--empty_e (5)
|             v       v
|  [0, 1, 2, -1, -1, -1, 6, 7, 8, 9, 10, 11, 12]
|
|  gap = (3 - 9 + 13) % 13 = 7
|
|  --- SCENARIO 1: logical index = 2 ---
|  index (2) < gap (7)
|  		return: (9 + 2) % 13 = 11
|
|                                         v--physical_index (11)
|  [0, 1, 2, -1, -1, -1, 6, 7, 8, 9, 10, 11, 12]
|
|  --- SCENARIO 2: logical index = 8 ---
|  index (8) >= gap (7)
|     return: (5 + 1 + 8 - 7) % 13 = 7
|
|                                 v--physical_index (7)
|  [0, 1, 2, -1, -1, -1, 6, 7, 8, 9, 10, 11, 12]
|
| ---
|
|  empty_e (1)--v   v--start (2)
|          [-1, -1, 7, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1]
|                                                    ^--empty_s (11)
|
|  LOGICAL ORDER: [7, 8, 9, 10, 11, 12, 13, 14, 15]
|  stk->len = 9, stk->capacity = 13
|
|  gap = (11 - 2 + 13) % 13 = 9
|
|  --- SCENARIO 3: logical index = 6 ---
|  index (6) < gap (9)
|     return: (2 + 6) % 13 = 8
|
|                                                v--physical_index (8)
|          [-1, -1, 7, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1]
*/
ssize_t	_i(t_stk *stk, ssize_t index)
{
	ssize_t	gap;

	index = index % stk->len;
	if (index < 0)
		index += stk->len;
	if (stk->len == stk->capacity)
		return ((stk->start + index) % stk->capacity);
	gap = (stk->empty_s - stk->start + stk->capacity) % stk->capacity;
	if (index < gap)
		return ((stk->start + index) % stk->capacity);
	return ((stk->empty_e + 1 + index - gap) % stk->capacity);
}

/*
|  -1 == empty_zone
|                                 v--start
|  [0, 1, 2, -1, -1, -1, 6, 7, 8, 9, 10, 11, 12]
|
|  index = (9 - 1 + 13) % 13 = 8 (+13 for fix negatives)
|
|             |--empty_s (3)
|             |       |--empty_e (5)
|             v       v        v--index
|  [0, 1, 2, -1, -1, -1, 6, 7, 8, 9, 10, 11, 12]
|  while (5 != 8)
|    next_elem = 6
|    arr[3] = arr[6]
|    empty_s = 4
|    empty_e = 6
|  ... loop ... loop ...
|
|  empty_e = 8 - 1 // 7
|  start = 8
|
|  FINAL ARR:
|                                     v--start (8)
|  [0, 1, 2, 6, 7, 8, -1, -1, -1, NEW_NODE_HERE, 9, 10, 11, 12]
|            ^  ^  ^ -- relocated
*/
ssize_t	push_i(t_stk *stk)
{
	ssize_t	index;
	ssize_t	next_elem;

	index = (stk->start - 1 + stk->capacity) % stk->capacity;
	while (stk->empty_e != index)
	{
		next_elem = (stk->empty_e + 1) % stk->capacity;
		stk->arr[stk->empty_s] = stk->arr[next_elem];
		stk->empty_s = (stk->empty_s + 1) % stk->capacity;
		stk->empty_e = next_elem;
	}
	stk->empty_e = (stk->empty_e - 1 + stk->capacity) % stk->capacity;
	stk->start = index;
	return (index);
}

/*
|  -1 == empty_zone
|                                 v--start
|  [0, 1, 2, -1, -1, -1, 6, 7, 8, 9, 10, 11, 12]
|
|  stop_i = (9 - 1 + 13) % 13 = 8 (+13 for fix negatives)
|
|             |--empty_s (3)
|             |       |--empty_e (5)
|             v       v        v--stop_i
|  [0, 1, 2, -1, -1, -1, 6, 7, 8, 9, 10, 11, 12]
|  while (5 != 8)
|    next_elem = 6
|    arr[3] = arr[6]
|    empty_s = 4
|    empty_e = 6
|  ... loop ... loop ...
|
|  empty_e = start (9)
|  start = 10
|
|  FINAL ARR:
|                                     v--start
|  [0, 1, 2, 6, 7, 8, -1, -1, -1, -1, 10, 11, 12]
|            ^  ^  ^ -- relocated
*/
void	pop(t_stk *stk)
{
	ssize_t	stop_i;
	ssize_t	next_elem;

	stop_i = (stk->start - 1 + stk->capacity) % stk->capacity;
	while (stk->empty_e != stop_i)
	{
		next_elem = (stk->empty_e + 1) % stk->capacity;
		stk->arr[stk->empty_s] = stk->arr[next_elem];
		stk->empty_s = (stk->empty_s + 1) % stk->capacity;
		stk->empty_e = next_elem;
	}
	stk->empty_e = stk->start;
	stk->start = (stk->start + 1) % stk->capacity;
}
