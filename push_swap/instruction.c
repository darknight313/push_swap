/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:12:29 by ashirzad          #+#    #+#             */
/*   Updated: 2024/01/22 11:42:10 by ashirzad         ###   ########.fr       */
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
	if (!stack_t->next)
		return ;
	int tmp = stack_t->data;
	stack_t->data = stack_t->next->data;
	stack_t->next->data = tmp;
}

void	sb(s_stack **stack_b)
{
	sa(stack_b);
}

void	ss(s_stack **stack_a, s_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(s_stack **stack_a, s_stack **stack_b)
{
	s_stack *stack_p = *stack_b;
	if (!stack_p)
		return ;
	int tmp = stack_p->data;
	push_stack(stack_a, tmp);
	*stack_b = (*stack_b)->next;
	(*stack_b)->pre = NULL;
	index_restart(&stack_p);
	index_restart(stack_a);
}

void	pb(s_stack **stack_a, s_stack **stack_b)
{
	pa(stack_b, stack_a);
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

void	rb(s_stack **stack_b)
{
	ra(stack_b);
}

void	rr(s_stack **stack_a, s_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
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

void	rrb(s_stack **stack_b)
{
	rra(stack_b);
}

void	rrr(s_stack **stack_a, s_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
