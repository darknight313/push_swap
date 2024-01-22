/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:18:53 by ashirzad          #+#    #+#             */
/*   Updated: 2024/01/21 18:24:16 by ashirzad         ###   ########.fr       */
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
	struct s_stack *pre;
	struct s_stack *next;
} s_stack;

// create stack
void	print_stack(s_stack **stack_a, s_stack **stack_b);
void	append_stack(s_stack **stack_a, int value);
void	push_stack(s_stack **stack_a, int value);
int		count_nodes(s_stack **stack_a);

//moves
void	sa(s_stack **stack_a);
void	sb(s_stack **stack_b);
void	ss(s_stack **stack_a, s_stack **stack_b);
void	pa(s_stack **stack_a, s_stack **stack_b);
void	pb(s_stack **stack_a, s_stack **stack_b);
void	ra(s_stack **stack_a);
void	rb(s_stack **stack_a);
void	rr(s_stack **stack_a, s_stack **stack_b);
void	rra(s_stack **stack_a);
void	rrb(s_stack **stack_b);
void	rrr(s_stack **stack_a, s_stack **stack_b);

#endif
