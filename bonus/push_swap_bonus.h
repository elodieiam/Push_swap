/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:07:30 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/24 19:47:16 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_pile
{
	int				num;
	struct s_pile	*next;
}	t_pile;

/*check_arguments.c*/
int		int_lim(char **av);
int		doublon(char **av);
int		is_num(char **av);
int		is_sort(char **av);
int		check_args(char **av);

/*create_stack_a.c*/
t_pile	*new_node(int value, t_pile *next);
void	create_stack_a(t_pile **pile, char **args, int i, int ac);

/*main.c*/
void	check_pile_is_sort(t_pile **p_a, t_pile **p_b, char **args, int ac);
void	apply_op(char *op, t_pile **pile_a, t_pile **pile_b);
void	sort_data(t_pile **pile_a, t_pile **pile_b, char **args, int ac);
void	start_checker(char **av, int i, int ac);

/*print_operations.c*/
void	print_swap(t_pile **stack_a, t_pile **stack_b, int op_num);
void	print_push(t_pile **stack_a, t_pile **stack_b, int op_num);
void	print_ra(t_pile **stack, int op_num);
void	print_rb(t_pile **stack, int op_num);
void	print_rr(t_pile **stack_a, t_pile **stack_b, int op_num);

/*stack_operations.c*/
void	swap(t_pile **stack);
void	push(t_pile	**stack_a, t_pile **stack_b);
void	rotate(t_pile **stack);
void	r_rotate(t_pile **stack);

/*utils.c*/
void	free_args(char **args);
void	free_stack(t_pile *pile);
int		pile_is_sort(t_pile *stack_a);

/*valid_move.c*/
int		ft_strlen_op(char *op);
int		ft_strncmp_op(const char *str1, const char *str2, int n);
int		is_valid_move(char *op);

#endif