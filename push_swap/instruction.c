/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:12:29 by ashirzad          #+#    #+#             */
/*   Updated: 2024/02/10 11:19:45 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "push_swap.h"

void	index_restart(s_stack **stack)
{
	s_stack *stack_t = *stack;
	if (!stack_t)
		return ;
	int index = 0;
	while (stack_t)
	{
		stack_t->index = index;
		stack_t = stack_t->next;
		index++;
	}
}

void	sa(s_stack **stack_a)
{
	s_stack *stack_t = *stack_a;
	if (!stack_t ||!stack_t->next)
		return ;
	int tmp = stack_t->data;
	stack_t->data = stack_t->next->data;
	stack_t->next->data = tmp;
}

void	pa(s_stack **stack_a, s_stack **stack_b)
{
	s_stack *stack_tmp = *stack_b;
	if (!(*stack_b))
		return ;
	*stack_b = (*stack_b)->next;
	stack_tmp->next = *stack_a;
	*stack_a = stack_tmp;
	index_restart(stack_b);
	index_restart(stack_a);
}


void	ra(s_stack **stack_a)
{
	s_stack *stack_t = *stack_a;
	if (!stack_t)
		return ;
	while(stack_t->next)
	{
		sa(&stack_t);
		stack_t = stack_t->next;
	}
}


void	rra(s_stack **stack_a)
{
	s_stack *stack_t = *stack_a;
	if (!stack_t)
		return ;
	int rounds = count_nodes(&stack_t);
	while (rounds > 1)
	{
		ra(&stack_t);
		rounds--;
	}
}
