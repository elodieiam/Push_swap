/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:51:13 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/24 10:35:23 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_swap(t_pile **stack_a, t_pile **stack_b, int op_num)
{
	if (op_num == 1)
	{
		swap(stack_a);
	}
	else if (op_num == 2)
	{
		swap(stack_b);
	}
	else if (op_num == 3)
	{
		swap(stack_a);
		swap(stack_b);
	}
}

void	print_push(t_pile **stack_a, t_pile **stack_b, int op_num)
{
	if (op_num == 1)
	{
		push(stack_a, stack_b);
	}
	else if (op_num == 2)
	{
		push(stack_b, stack_a);
	}
}

void	print_ra(t_pile **stack, int op_num)
{
	if (op_num == 1)
	{
		rotate(stack);
	}
	else if (op_num == 2)
	{
		r_rotate(stack);
	}
}

void	print_rb(t_pile **stack, int op_num)
{
	if (op_num == 1)
	{
		rotate(stack);
	}
	else if (op_num == 2)
	{
		r_rotate(stack);
	}
}

void	print_rr(t_pile **stack_a, t_pile **stack_b, int op_num)
{
	if (op_num == 1)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (op_num == 2)
	{
		r_rotate(stack_a);
		r_rotate(stack_b);
	}
}
