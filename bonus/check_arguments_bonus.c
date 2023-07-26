/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:38:26 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/23 11:50:06 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	int_lim(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) < -2147483648 || ft_atoi(av[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	doublon(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_num(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][0] == '-')
			j++;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sort(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
		i++;
	if (i == 1)
		return (0);
	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) > ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args(char **av)
{
	if (!is_num(av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!int_lim(av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!doublon(av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
