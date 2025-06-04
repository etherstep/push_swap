/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:54:07 by jpelline          #+#    #+#             */
/*   Updated: 2025/06/03 15:54:11 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_by_pos(t_stack *a, int min_pos, int i)
{
	if (min_pos <= a->size / 2)
		while (min_pos--)
			rotate_a(a);
	else
	{
		min_pos = a->size - min_pos - i;
		while (min_pos--)
			reverse_rotate_a(a);
	}
}

static void	find_smallest_value(t_stack *a, int *min_pos)
{
	int	min_val;
	int	j;

	min_val = a->arr[0];
	j = 1;
	while (!a->isempty[j])
	{
		if (a->arr[j] < min_val)
		{
			min_val = a->arr[j];
			*min_pos = j;
		}
		j++;
	}
}

void	sort_four_and_five(t_stack *a, t_stack *b)
{
	int	i;
	int	min_pos;
	int	iter;

	if (a->size == 4)
		iter = 1;
	else
		iter = 2;
	i = 0;
	while (i < iter)
	{
		min_pos = 0;
		find_smallest_value(a, &min_pos);
		rotate_by_pos(a, min_pos, i);
		push_b(a, b);
		i++;
	}
	sort_three(a);
	if (b->arr[0] < b->arr[1])
		swap_b(b);
	while (iter--)
		push_a(a, b);
}

void	sort_three(t_stack *a)
{
	if (a->arr[0] > a->arr[1])
		swap_a(a);
	if (a->arr[1] > a->arr[2])
		reverse_rotate_a(a);
	if (a->arr[0] > a->arr[1])
		swap_a(a);
}

void	sort_two(t_stack *a)
{
	if (a->arr[0] > a->arr[1])
		swap_a(a);
}
