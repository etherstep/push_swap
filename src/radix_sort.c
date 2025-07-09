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

static void	sort_copy(int **copy, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if ((*copy)[j] > (*copy)[j + 1])
			{
				temp = (*copy)[j];
				(*copy)[j] = (*copy)[j + 1];
				(*copy)[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	normalize_stack(t_stack *a, int **copy)
{
	int	i;
	int	j;

	ft_memcpy(*copy, a->arr, a->size * sizeof(int));
	sort_copy(copy, a->size);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->arr[i] == (*copy)[j])
			{
				a->arr[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

static void	sort_by_bit(t_stack *a, t_stack *b, int bit)
{
	int			j;

	j = 0;
	while (j < a->size)
	{
		if (((a->arr[0] >> bit) & 1) == 1)
			rotate_a(a);
		else
			push_b(a, b);
		j++;
	}
}

static void	radix_sort(t_stack *a, t_stack *b)
{
	int	bit;
	int	max_num;
	int	max_bits;

	max_num = a->size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		sort_by_bit(a, b, bit);
		while (!b->isempty[0])
			push_a(a, b);
		bit++;
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int	*copy;
	int	i;

	copy = malloc(a->size * sizeof(int *));
	if (!copy)
		ft_error(a, b);
	normalize_stack(a, &copy);
	radix_sort(a, b);
	free(copy);
}
