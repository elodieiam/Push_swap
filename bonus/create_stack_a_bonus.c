/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:08:51 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/23 16:17:15 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_pile	*new_node(int value, t_pile *next)
{
	t_pile	*node;

	node = malloc(sizeof(t_pile));
	if (!node)
		return (NULL);
	node->num = value;
	node->next = next;
	return (node);
}

void	create_stack_a(t_pile **pile, char **args, int i, int ac)
{
	int		size;

	size = i - 1;
	while (size >= 0)
	{
		*pile = new_node(ft_atoi(args[size]), *pile);
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
