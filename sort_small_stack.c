/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:39:11 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/22 14:11:32 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_elements(t_pile **stack)
{
	if ((*stack)->num == get_max(*stack))
	{
		if ((*stack)->next->num == get_min(*stack))
			print_ra(stack, 1);
		else
		{
			print_swap(stack, NULL, 1);
			print_ra(stack, 2);
		}	
	}
	else if ((*stack)->num == get_min(*stack))
	{
		if ((*stack)->next->num == get_max(*stack))
		{
			print_ra(stack, 2);
			print_swap(stack, NULL, 1);
		}
	}
	else
	{
		if ((*stack)->next->num == get_max(*stack))
			print_ra(stack, 2);
		else
			print_swap(stack, NULL, 1);
	}
}

void	sort_2_elements(t_pile **stack)
{
	if ((*stack)->num > (*stack)->next->num)
		print_swap(stack, NULL, 1);
}

void	put_min_up(t_pile **stack)
{
	int		min;
	long	pos_min;

	min = get_min(*stack);
	pos_min = get_pos(*stack, min);
	if (pos_min > (stack_size(*stack) / 2))
		while ((*stack)->num != min)
			print_ra(stack, 2);
	else
		while ((*stack)->num != min)
			print_ra(stack, 1);
}

void	sort_small_stack(t_pile **stack)
{
	t_pile	*stack_b;

	stack_b = NULL;
	if (stack_size(*stack) == 2)
	{
		sort_2_elements(stack);
		return ;
	}
	while (stack_size(*stack) > 3)
	{
		put_min_up(stack);
		print_push(stack, &stack_b, 1);
	}
	sort_3_elements(stack);
	while (stack_b)
		print_push(stack, &stack_b, 2);
}
