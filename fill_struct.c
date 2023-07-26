/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:26:09 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/20 15:33:53 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_current_pos(t_pile *stack)
{
	long	pos;

	pos = 0;
	while (stack)
	{
		stack->pos = pos;
		stack = stack->next;
		pos++;
	}
}

void	fill_majorant_pos(t_pile *stack_a, t_pile *stack_b)
{
	int	maj;

	maj = 0;
	while (stack_b)
	{
		maj = get_majorant(stack_a, stack_b->num);
		stack_b->maj_pos = get_pos(stack_a, maj);
		stack_b = stack_b->next;
	}
}

void	fill_cost(t_pile *stack_a, t_pile *stack_b)
{
	int		cost;
	t_pile	*tmp;

	cost = 0;
	tmp = stack_b;
	while (tmp)
	{
		if (tmp->pos > (stack_size(stack_b) / 2))
			cost = stack_size(stack_b) - (tmp->pos);
		else
			cost = tmp->pos;
		if (tmp->maj_pos > (stack_size(stack_a) / 2))
			cost += stack_size(stack_a) - (tmp->maj_pos);
		else
			cost += tmp->maj_pos;
		tmp->cost = cost;
		tmp = tmp->next;
	}
}
