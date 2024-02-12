/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:18:53 by ashirzad          #+#    #+#             */
/*   Updated: 2024/02/12 09:54:18 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_stack
{
	int	data;
	int	index;
	struct s_stack *next;
} s_stack;

// create stack
void	print_stack(s_stack **stack);
void	append_stack(s_stack **stack_a, int value);
int		count_nodes(s_stack **stack_a);
int		dup_checker(s_stack **stack_a);
int		sort_checker(s_stack **stack_a);
void	sort_stack(s_stack **stack_a, s_stack **stack_b);
void	sort_three(s_stack **stack_a);
void	sort_five(s_stack **stack_a, s_stack **stack_b);

//moves
void	index_restart(s_stack **stack);
void	sa(s_stack **stack_a);
void	pa(s_stack **stack_a, s_stack **stack_b);
void	ra(s_stack **stack_a);
void	rra(s_stack **stack_a);

#endif
