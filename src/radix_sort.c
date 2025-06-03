/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:30:07 by jpelline          #+#    #+#             */
/*   Updated: 2025/06/03 15:54:03 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	normalize_array(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	count;
	int	*normalized;

	normalized = malloc(a->size * sizeof(int));
	if (!normalized)
		ft_error(a, b);
	i = -1;
	while (++i < a->size)
	{
		count = 0;
		j = -1;
		while (++j < a->size)
			if (a->arr[j] < a->arr[i])
				count++;
		normalized[i] = count;
	}
	i = -1;
	while (++i < a->size)
		a->arr[i] = normalized[i];
	free(normalized);
}

static void	sort_by_bit(t_stack *a, t_stack *b)
{
	int		j;
	static int	i = 0;
	int		num;

	j = -1;
	while (++j < a->size)
	{
		num = a->arr[0];
		if (((num >> i) & 1) == 1)
			rotate_a(a);
		else
			push_b(a, b);
	}
	i++;
}

static void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	max_num;
	int	max_bits;

	max_num = a->size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		sort_by_bit(a, b);
		while (!b->isempty[0])
			push_a(a, b);
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int	i;

	normalize_array(a, b);
	radix_sort(a, b);
	while (!b->isempty)
		push_a(a, b);
	i = -1;
	while (++i < a->size)
		if (a->arr[i] == i)
			a->arr[i] = copy[i];
	free(copy);
}
