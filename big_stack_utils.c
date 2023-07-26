/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:25:39 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/20 15:49:40 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_pos(t_pile *stack, int value)
{
	long	pos;

	pos = 0;
	while (stack->next)
	{
		if (stack->num == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

int	get_majorant(t_pile *stack_a, int num)
{
	int	maj;

	maj = get_max(stack_a);
	while (stack_a)
	{
		if (stack_a->num > num && stack_a->num < maj)
			maj = stack_a->num;
		stack_a = stack_a->next;
	}
	return (maj);
}

int	get_min_cost(t_pile *stack_b)
{
	int	min;

	min = stack_b->cost;
	while (stack_b)
	{
		if (stack_b->cost < min)
			min = stack_b->cost;
		stack_b = stack_b->next;
	}
	return (min);
}

int	value_to_move(t_pile *stack_b, int min_cost)
{
	while (stack_b)
	{
		if (stack_b->cost == min_cost)
			return (stack_b->num);
		stack_b = stack_b->next;
	}
	return (0);
}

void	push_value(t_pile **stack_a, t_pile **stack_b, int value)
{
	int		maj;
	long	pos_to_move;

	cost_opti(stack_a, stack_b, value);
	pos_to_move = get_pos(*stack_b, value);
	maj = get_majorant(*stack_a, value);
	while ((*stack_b)->num != value)
	{
		if (pos_to_move > (stack_size(*stack_b) / 2))
			print_rb(stack_b, 2);
		else
			print_rb(stack_b, 1);
	}
	pos_to_move = get_pos(*stack_a, maj);
	while ((*stack_a)->num != maj)
	{
		if (pos_to_move > (stack_size(*stack_a) / 2))
			print_ra(stack_a, 2);
		else
			print_ra(stack_a, 1);
	}
	print_push(stack_a, stack_b, 2);
}
