/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:55:45 by jpelline          #+#    #+#             */
/*   Updated: 2025/05/27 11:56:29 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *a)
{
	int	i;
	int	temp;
	int	empty;

	ft_printf("rra\n");
	empty = 0;
	while (empty < a->size)
	{
		if (a->isempty[empty] == true)
			break ;
		empty++;
	}
	if (empty <= 1)
		return ;
	i = 0;
	temp = a->arr[empty - 1];
	while (i < empty - 1)
	{
		a->arr[empty - 1 - i] = a->arr[empty - 2 - i];
		i++;
	}
	a->arr[0] = temp;
}

void	reverse_rotate_b(t_stack *b)
{
	int	i;
	int	temp;
	int	empty;

	ft_printf("rrb\n");
	empty = 0;
	while (empty < b->size)
	{
		if (b->isempty[empty] == true)
			break ;
		empty++;
	}
	if (empty <= 1)
		return ;
	i = 0;
	temp = b->arr[empty - 1];
	while (i < empty - 1)
	{
		b->arr[empty - 1 - i] = b->arr[empty - 2 - i];
		i++;
	}
	b->arr[0] = temp;
}

void	reverse_rotate_a_b(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	reverse_rotate_a(a);
	reverse_rotate_b(b);
}
