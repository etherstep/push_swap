/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:41:43 by jpelline          #+#    #+#             */
/*   Updated: 2025/05/26 21:57:47 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int		*arr;
	int		size;
	bool	*isempty;
}			t_stack;

// Utility
int			check_duplicates(t_stack *a);
void		check_inputs(t_stack *a, char **av);
void		ft_error(t_stack *a, t_stack *b);
void		ft_free(t_stack *a, t_stack *b);

// Operations
void		push_b(t_stack *a, t_stack *b);
void		push_a(t_stack *a, t_stack *b);
void		swap_a(t_stack *a);
void		swap_b(t_stack *b);
void		swap_a_swap_b(t_stack *a, t_stack *b);
void		rotate_a(t_stack *a);
void		rotate_b(t_stack *b);
void		rotate_a_b(t_stack *a, t_stack *b);
void		reverse_rotate_a(t_stack *a);
void		reverse_rotate_b(t_stack *b);
void		reverse_rotate_a_b(t_stack *a, t_stack *b);

// Sorting
void		sort_two(t_stack *a);
void		sort_three(t_stack *a);
void		sort_four_and_five(t_stack *a, t_stack *b);
void		sort_stack(t_stack *a, t_stack *b);
bool		sorted(t_stack *a);

#endif // PUSH_SWAP_H
