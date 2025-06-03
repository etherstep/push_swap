/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:47:17 by jpelline          #+#    #+#             */
/*   Updated: 2025/05/26 19:51:28 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ready_stack_for_push(void *param)
{
	t_stack	*stack;
	int		i;
	int		count;

	stack = (t_stack *)param;
	count = 0;
	while (count < stack->size && stack->isempty[count] == false)
		count++;
	i = count;
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		stack->isempty[i] = stack->isempty[i - 1];
		i--;
	}
}

void	push_a(t_stack *a, t_stack *b)
{
	int	i;
	int	size;

	ft_printf("pa\n");
	if (b->isempty[0] == true)
		return ;
	ready_stack_for_push(a);
	a->arr[0] = b->arr[0];
	a->isempty[0] = false;
	size = 0;
	while (b->isempty[size] == false)
		size++;
	i = 0;
	while (i < size - 1)
	{
		b->arr[i] = b->arr[i + 1];
		b->isempty[i] = b->isempty[i + 1];
		i++;
	}
	if (size > 0)
		b->isempty[size - 1] = true;
}

void	push_b(t_stack *a, t_stack *b)
{
	int	i;
	int	size;

	ft_printf("pb\n");
	if (a->isempty[0] == true)
		return ;
	ready_stack_for_push(b);
	b->arr[0] = a->arr[0];
	b->isempty[0] = false;
	i = 0;
	size = 0;
	while (a->isempty[size] == false)
		size++;
	while (i < size - 1)
	{
		a->arr[i] = a->arr[i + 1];
		a->isempty[i] = a->isempty[i + 1];
		i++;
	}
	if (size > 0)
		a->isempty[size - 1] = true;
}
