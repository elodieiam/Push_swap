/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:51:13 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/22 11:39:51 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_swap(t_pile **stack_a, t_pile **stack_b, int op_num)
{
	if (op_num == 1)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
	else if (op_num == 2)
	{
		swap(stack_b);
		write(1, "sb\n", 3);
	}
	else if (op_num == 3)
	{
		swap(stack_a);
		swap(stack_b);
		write(1, "ss\n", 3);
	}
}

void	print_push(t_pile **stack_a, t_pile **stack_b, int op_num)
{
	if (op_num == 1)
	{
		push(stack_a, stack_b);
		write(1, "pb\n", 3);
	}
	else if (op_num == 2)
	{
		push(stack_b, stack_a);
		write(1, "pa\n", 3);
	}
}

void	print_ra(t_pile **stack, int op_num)
{
	if (op_num == 1)
	{
		rotate(stack);
		write(1, "ra\n", 3);
	}
	else if (op_num == 2)
	{
		r_rotate(stack);
		write(1, "rra\n", 4);
	}
}

void	print_rb(t_pile **stack, int op_num)
{
	if (op_num == 1)
	{
		rotate(stack);
		write(1, "rb\n", 3);
	}
	else if (op_num == 2)
	{
		r_rotate(stack);
		write(1, "rrb\n", 4);
	}
}

void	print_rr(t_pile **stack_a, t_pile **stack_b, int op_num)
{
	if (op_num == 1)
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
	}
	else if (op_num == 2)
	{
		r_rotate(stack_a);
		r_rotate(stack_b);
		write(1, "rrr\n", 4);
	}
}
