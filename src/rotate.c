/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:46:17 by jpelline          #+#    #+#             */
/*   Updated: 2025/05/26 21:56:37 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *a)
{
	int	i;
	int	temp;
	int	empty;

	ft_printf("ra\n");
	empty = 0;
	while (empty < a->size)
	{
		if (a->isempty[empty] == true)
			break ;
		empty++;
	}
	i = 0;
	temp = a->arr[empty];
	a->arr[empty] = a->arr[i];
	while (i < empty)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->arr[i] = temp;
}

void	rotate_b(t_stack *b)
{
	int	i;
	int	temp;
	int	empty;

	ft_printf("rb\n");
	empty = 0;
	while (empty < b->size)
	{
		if (b->isempty[empty] == true)
			break ;
		empty++;
	}
	i = 0;
	temp = b->arr[empty];
	b->arr[empty] = b->arr[i];
	while (i < empty)
	{
		b->arr[i] = b->arr[i + 1];
		i++;
	}
	b->arr[i] = temp;
}

void	rotate_a_b(t_stack *a, t_stack *b)
{
	ft_printf("rr\n");
	rotate_a(a);
	rotate_b(b);
}
