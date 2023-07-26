/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:09:47 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/24 19:47:28 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	free_stack(t_pile *pile)
{
	t_pile	*next;

	next = NULL;
	while (pile)
	{
		next = pile->next;
		free(pile);
		pile = next;
	}
}

int	pile_is_sort(t_pile *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->num > stack_a->next->num)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
