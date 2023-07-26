/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:59:19 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/23 15:40:06 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_opti(t_pile **stack_a, t_pile **stack_b, int value)
{
	int		maj;
	long	pos_a;
	long	pos_b;

	maj = get_majorant(*stack_a, value);
	pos_a = get_pos(*stack_a, maj);
	pos_b = get_pos(*stack_b, value);
	while ((*stack_b)->num != value && (*stack_a)->num != maj)
	{
		if ((pos_a > stack_size(*stack_a) / 2)
			&& (pos_b > stack_size(*stack_b) / 2))
			print_rr(stack_a, stack_b, 2);
		else if ((pos_a < stack_size(*stack_a) / 2)
			&& (pos_b < stack_size(*stack_b) / 2))
			print_rr(stack_a, stack_b, 1);
		else
			return ;
	}
}

void	first_sort(t_pile **stack_a, t_pile **stack_b, int med)
{
	while (stack_size(*stack_a) > 1)
	{
		if ((*stack_a)->num == get_max(*stack_a))
			print_ra(stack_a, 1);
		else
		{
			if ((*stack_a)->num >= med)
			{
				print_push(stack_a, stack_b, 1);
				print_rb(stack_b, 1);
			}
			else
				print_push(stack_a, stack_b, 1);
		}
	}
}

void	last_sort(t_pile **stack_a)
{
	int		min;
	long	min_pos;

	min = get_min(*stack_a);
	min_pos = get_pos(*stack_a, min);
	if (min_pos == 0)
		return ;
	else if (min_pos > (stack_size(*stack_a) / 2))
		while ((*stack_a)->num != min)
			print_ra(stack_a, 2);
	else
		while ((*stack_a)->num != min)
			print_ra(stack_a, 1);
}

void	sort_big_stack(t_pile **stack_a, char **args, int ac)
{
	t_pile	*stack_b;
	int		min_cost;
	int		val_to_move;

	stack_b = NULL;
	first_sort(stack_a, &stack_b, get_med(*stack_a, args, ac));
	while (stack_b)
	{
		fill_current_pos(*stack_a);
		fill_current_pos(stack_b);
		fill_majorant_pos(*stack_a, stack_b);
		fill_cost(*stack_a, stack_b);
		min_cost = get_min_cost(stack_b);
		val_to_move = value_to_move(stack_b, min_cost);
		push_value(stack_a, &stack_b, val_to_move);
	}
	last_sort(stack_a);
}
