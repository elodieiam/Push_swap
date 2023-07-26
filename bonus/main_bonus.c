/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:22:47 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/26 12:18:07 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_pile_is_sort(t_pile **p_a, t_pile **p_b, char **args, int ac)
{
	if (pile_is_sort(*p_a) && !*p_b)
		ft_printf("OK\n");
	else
	{
		ft_printf("KO\n");
		free_stack(*p_a);
		free_stack(*p_b);
		if (ac == 2)
			free_args(args);
		exit (EXIT_FAILURE);
	}
}

void	apply_op(char *op, t_pile **pile_a, t_pile **pile_b)
{
	if (!ft_strncmp_op(op, "sa", 2))
		print_swap(pile_a, pile_b, 1);
	else if (!ft_strncmp_op(op, "sb", 2))
		print_swap(pile_a, pile_b, 2);
	else if (!ft_strncmp_op(op, "ss", 2))
		print_swap(pile_a, pile_b, 3);
	else if (!ft_strncmp_op(op, "pa", 2))
		print_push(pile_a, pile_b, 2);
	else if (!ft_strncmp_op(op, "pb", 2))
		print_push(pile_a, pile_b, 1);
	else if (!ft_strncmp_op(op, "ra", 2))
		print_ra(pile_a, 1);
	else if (!ft_strncmp_op(op, "rra", 3))
		print_ra(pile_a, 2);
	else if (!ft_strncmp_op(op, "rb", 2))
		print_rb(pile_b, 1);
	else if (!ft_strncmp_op(op, "rrb", 3))
		print_rb(pile_b, 2);
	else if (!ft_strncmp_op(op, "rrr", 3))
		print_rr(pile_a, pile_b, 2);
	else if (!ft_strncmp_op(op, "rr", 2))
		print_rr(pile_a, pile_b, 1);
}

void	sort_data(t_pile **pile_a, t_pile **pile_b, char **args, int ac)
{
	char	*op;

	op = "op";
	while (op)
	{
		op = get_next_line(0);
		if (is_valid_move(op))
		{
			apply_op(op, pile_a, pile_b);
			if (is_valid_move(op) == 1)
				free(op);
		}
		else
		{
			free(op);
			free_stack(*pile_a);
			free_stack(*pile_b);
			if (ac == 2)
				free_args(args);
			exit (EXIT_FAILURE);
		}	
	}
	check_pile_is_sort(pile_a, pile_b, args, ac);
}

void	start_checker(char **args, int i, int ac)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_a = NULL;
	pile_b = NULL;
	create_stack_a(&pile_a, args, i, ac);
	sort_data(&pile_a, &pile_b, args, ac);
	free_stack(pile_a);
	if (ac == 2)
		free_args(args);
}

int	main(int ac, char **av)
{
	char	**args;
	int		i;

	i = 0;
	if (ac <= 1)
		return (1);
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args)
			return (1);
	}
	else
		args = &av[1];
	while (args[i])
			i++;
	if (!check_args(args))
	{
		if (ac == 2)
			free_args(args);
		return (1);
	}
	start_checker(args, i, ac);
	return (0);
}
