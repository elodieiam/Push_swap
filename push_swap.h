/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:20:59 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/23 15:40:26 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_pile
{
	int				num;
	long			pos;
	long			maj_pos;
	long			cost;
	struct s_pile	*next;
}	t_pile;

/* big_stack_utils.c*/
long	get_pos(t_pile *stack, int value);
int		get_majorant(t_pile *stack_a, int num);
int		get_min_cost(t_pile *stack_b);
int		value_to_move(t_pile *stack_b, int min_cost);
void	push_value(t_pile **stack_a, t_pile **stack_b, int value);

/*check_arguments.c*/
int		int_lim(char **av);
int		doublon(char **av);
int		is_num(char **av);
int		is_sort(char **av);
int		check_args(char **av);

/*create_stack_a.c*/
t_pile	*new_node(int value, long pos, t_pile *next);
void	create_stack_a(t_pile **pile, char **args, int i, int ac);

/*fill_struct.c*/
void	fill_current_pos(t_pile *stack);
void	fill_majorant_pos(t_pile *stack_a, t_pile *stack_b);
void	fill_cost(t_pile *stack_a, t_pile *stack_b);

/*get_med.c*/
void	ft_sort_arr(int *arr, long size);
int		get_med(t_pile *stack_a, char **args, int ac);

/*main.c*/
void	free_stack(t_pile *pile);
void	sort(char **args, int i, int ac);
void	free_args(char **args);

/*print_operations.c*/
void	print_swap(t_pile **stack, t_pile **stack_b, int op_num);
void	print_push(t_pile **stack_a, t_pile **stack_b, int op_num);
void	print_ra(t_pile **stack, int op_num);
void	print_rb(t_pile **stack, int op_num);
void	print_rr(t_pile **stack_a, t_pile **stack_b, int op_num);

/*sort_big_stack.c*/
void	cost_opti(t_pile **stack_a, t_pile **stack_b, int value);
void	first_sort(t_pile **stack_a, t_pile **stack_b, int med);
void	last_sort(t_pile **stack_a);
void	sort_big_stack(t_pile **stack_a, char **args, int ac);

/*sort_small_stack.c*/
void	sort_3_elements(t_pile **stack);
void	sort_2_elements(t_pile **stack);
void	put_min_up(t_pile **stack);
void	sort_small_stack(t_pile **stack);

/*sort_utils.c*/
long	stack_size(t_pile *stack);
int		get_min(t_pile *stack);
int		get_max(t_pile *stack);

/*stack_operations.c*/
void	swap(t_pile **stack);
void	push(t_pile	**stack_a, t_pile **stack_b);
void	rotate(t_pile **stack);
void	r_rotate(t_pile **stack);

#endif