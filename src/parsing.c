/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:23:27 by jpelline          #+#    #+#             */
/*   Updated: 2025/05/26 19:23:36 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_stack *a)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = 0;
	while (i < a->size)
	{
		temp = a->arr[i];
		j = i + 1;
		while (j < a->size)
		{
			if (temp == a->arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_inputs(t_stack *a, char **av)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (!ft_atoib(av[i]))
			ft_error(NULL, NULL);
		i++;
	}
	a->size = i - 1;
}
