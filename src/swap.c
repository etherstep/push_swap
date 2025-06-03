/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:29:37 by jpelline          #+#    #+#             */
/*   Updated: 2025/06/03 18:15:03 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a)
{
	ft_printf("sa\n");
	if (a->isempty[1])
		return ;
	a->arr[0] ^= a->arr[1];
	a->arr[1] ^= a->arr[0];
	a->arr[0] ^= a->arr[1];
}

void	swap_b(t_stack *b)
{
	ft_printf("sb\n");
	if (b->isempty[1])
		return ;
	b->arr[0] ^= b->arr[1];
	b->arr[1] ^= b->arr[0];
	b->arr[0] ^= b->arr[1];
}

void	swap_a_swap_b(t_stack *a, t_stack *b)
{
	ft_printf("ss\n");
	swap_a(a);
	swap_b(b);
}
