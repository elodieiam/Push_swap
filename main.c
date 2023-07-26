/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:12:42 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/23 15:50:33 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	sort(char **args, int i, int ac)
{
	t_pile	*pile;

	pile = NULL;
	create_stack_a(&pile, args, i, ac);
	if (stack_size(pile) <= 10)
		sort_small_stack(&pile);
	else
		sort_big_stack(&pile, args, ac);
	free_stack(pile);
	if (ac == 2)
		free_args(args);
}

int	main(int ac, char **av)
{
	char	**args;
	int		i;

	i = 0;
	if (ac > 1)
	{
		if (ac == 2)
		{
			args = ft_split(av[1], ' ');
			if (!args)
				return (0);
		}
		else
			args = &av[1];
		while (args[i])
				i++;
		if (!check_args(args))
		{
			if (ac == 2)
				free_args(args);
			return (0);
		}
		sort(args, i, ac);
	}
	return (0);
}
