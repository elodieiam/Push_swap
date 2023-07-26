/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:08:51 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/24 21:20:55 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*new_node(int value, long pos, t_pile *next)
{
	t_pile	*node;

	node = malloc(sizeof(t_pile));
	if (!node)
		return (NULL);
	node->num = value;
	node->next = next;
	node->cost = 0;
	node->pos = pos;
	node->maj_pos = 0;
	return (node);
}

void	create_stack_a(t_pile **pile, char **args, int i, int ac)
{
	int		size;

	size = i - 1;
	while (size >= 0)
	{
		*pile = new_node(ft_atoi(args[size]), size, *pile);
		if (!*pile)
		{
			if (ac == 2)
				free_args(args);
			free_stack(*pile);
			exit (EXIT_FAILURE);
		}
		size--;
	}
}
