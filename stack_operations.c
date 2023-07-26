/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:11:07 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/21 19:34:35 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile **stack)
{
	t_pile	*tmp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	push(t_pile	**stack_a, t_pile **stack_b)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	tmp = *stack_a;
	tmp2 = *stack_b;
	*stack_a = tmp->next;
	*stack_b = tmp;
	(*stack_b)->next = tmp2;
}

void	rotate(t_pile **stack)
{
	t_pile	*tmp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack) = (*stack)->next;
	tmp->next->next = NULL;
}

void	r_rotate(t_pile **stack)
{
	t_pile	*tmp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	(*stack)->next->next = tmp;
	tmp = (*stack)->next;
	(*stack)->next = NULL;
	*stack = tmp;
}
