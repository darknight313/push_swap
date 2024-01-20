/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:21:44 by ashirzad          #+#    #+#             */
/*   Updated: 2024/01/20 22:02:05 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "push_swap.h"

void	print_stack(s_stack **stack_a)
{
	s_stack *stack_t = *stack_a;
	while (stack_t)
	{
		printf("%d\n", stack_t->data);
		stack_t = stack_t->next;
	}
}

void	append_stack(s_stack **stack_a, int value)
{
	s_stack *stack_tmp = malloc(sizeof(s_stack));
	stack_tmp->data = value;
	stack_tmp->index = 0;
	stack_tmp->next = *stack_a;
	stack_tmp->pre = NULL;
	*stack_a = stack_tmp;
}

void	push_stack(s_stack **stack_a, int value)
{
	s_stack *stack_t = *stack_a;
	if (stack_t == NULL)
	{
		append_stack(stack_a, value);
		return ;
	}
	while (stack_t->next)
	{
		stack_t = stack_t->next;
	}
	stack_t->next = malloc(sizeof(s_stack));
	stack_t->next->index = stack_t->index + 1;
	stack_t->next->pre = stack_t;
	stack_t->next->data = value;
	stack_t->next->next = NULL;
}

int	count_nodes(s_stack **stack_a)
{
	s_stack *stack_t = *stack_a;
	int	count = 0;
	while (stack_t)
	{
		count++;
		stack_t = stack_t->next;
	}
	return (count);
}
