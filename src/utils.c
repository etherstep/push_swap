/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:22:51 by jpelline          #+#    #+#             */
/*   Updated: 2025/05/26 19:23:04 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *a, t_stack *b)
{
	if (a && a->arr)
		free(a->arr);
	if (b && b->arr)
		free(b->arr);
	if (a && a->isempty)
		free(a->isempty);
	if (b && b->isempty)
		free(b->isempty);
}

void	ft_error(t_stack *a, t_stack *b)
{
	if (a && a->arr)
		free(a->arr);
	if (b && b->arr)
		free(b->arr);
	if (a && a->isempty)
		free(a->isempty);
	if (b && b->isempty)
		free(b->isempty);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
