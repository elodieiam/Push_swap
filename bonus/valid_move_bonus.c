/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:29:20 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/24 19:46:19 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlen_op(char *op)
{
	int	i;

	i = 0;
	while (op[i] && op[i] != '\n')
		i++;
	return (i);
}

int	ft_strncmp_op(const char *str1, const char *str2, int n)
{
	int				i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if (!s1 || !s2)
		return (-1);
	while (i < n)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	is_valid_move(char *op)
{
	if (!op)
		return (2);
	if (ft_strlen_op(op) == 2)
	{
		if (!ft_strncmp_op(op, "ra", 2) || !ft_strncmp_op(op, "rb", 2)
			|| !ft_strncmp_op(op, "rr", 2) || !ft_strncmp_op(op, "pa", 2)
			|| !ft_strncmp_op(op, "pb", 2) || !ft_strncmp_op(op, "sa", 2)
			|| !ft_strncmp_op(op, "sb", 2) || !ft_strncmp_op(op, "ss", 2))
			return (1);
		ft_printf("Error\n");
		return (0);
	}
	else if (ft_strlen_op(op) == 3)
	{
		if (!ft_strncmp_op(op, "rra", 3) || !ft_strncmp_op(op, "rrb", 3)
			|| !ft_strncmp_op(op, "rrr", 3))
			return (1);
		ft_printf("Error\n");
		return (0);
	}
	ft_printf("Error\n");
	return (0);
}
