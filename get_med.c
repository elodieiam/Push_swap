/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_med.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:26:33 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/24 21:21:24 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_arr(int *arr, long size)
{
	long	i;
	long	j;
	int		tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_med(t_pile *stack_a, char **args, int ac)
{
	long		j;
	int			*arr;
	int			med;
	long		size;

	j = 0;
	size = stack_size(stack_a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
	{
		return (0);
		if (ac == 2)
			free_args(args);
		free_stack(stack_a);
		exit (EXIT_FAILURE);
	}
	while (j < size)
	{
		arr[j++] = stack_a->num;
		stack_a = stack_a->next;
	}
	sort_arr(arr, size);
	med = arr[size / 2];
	free(arr);
	return (med);
}
