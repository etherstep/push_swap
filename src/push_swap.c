/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:42:28 by jpelline          #+#    #+#             */
/*   Updated: 2025/05/26 21:56:58 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack *a, t_stack *b, char **av)
{
	int	i;

	b->size = a->size;
	a->arr = ft_calloc(a->size, sizeof(int));
	a->isempty = ft_calloc((a->size + 1), sizeof(bool));
	b->arr = ft_calloc(b->size, sizeof(int));
	b->isempty = ft_calloc((b->size + 1), sizeof(bool));
	if (!a->arr || !b->arr || !a->isempty || !b->isempty)
		ft_error(a, b);
	i = 0;
	while (i < a->size)
	{
		a->isempty[i] = false;
		b->isempty[i] = true;
		i++;
	}
	a->isempty[i] = true;
	i = 0;
	while (av[i + 1])
	{
		a->arr[i] = ft_atoi(av[i + 1]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		ft_error(NULL, NULL);
	check_inputs(&a, av);
	init_stack(&a, &b, av);
	if (check_duplicates(&a) == 0)
		ft_error(&a, &b);
	if (sorted(&a))
	{
		ft_free(&a, &b);
		exit(EXIT_SUCCESS);
	}
	else if (a.size == 3)
		sort_three(&a);
	else if (a.size == 5)
		sort_five(&a, &b);
	else
		sort_stack(&a, &b);
	ft_free(&a, &b);
	exit(EXIT_SUCCESS);
}
