/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:21:44 by ashirzad          #+#    #+#             */
/*   Updated: 2024/02/12 09:00:36 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "push_swap.h"

void	print_stack(s_stack **stack)
{
	s_stack *stack_t = *stack;
	while (stack_t)
	{
		printf("%d ", stack_t->data);
		fflush(stdout);
		stack_t = stack_t->next;
	}
}

void	append_stack(s_stack **stack_a, int value)
{
	s_stack *stack_t = *stack_a;
	if (!stack_t)
	{
		*stack_a = malloc(sizeof(s_stack));
		(*stack_a)->data = value;
		(*stack_a)->next = NULL;
	}
	else
	{
		while (stack_t->next)
			stack_t = stack_t->next;
		stack_t->next = malloc(sizeof(s_stack));
		stack_t->next->index = stack_t->index + 1;
		stack_t->next->data = value;
		stack_t->next->next = NULL;
	}
}

int	count_nodes(s_stack **stack_a)
{
	s_stack *stack_t = *stack_a;
	if	(!stack_t)
		return (0);
	int	count = 0;
	while (stack_t)
	{
		stack_t = stack_t->next;
		count++;
	}
	return (count);
}

int	sort_checker(s_stack **stack_a)
{
	s_stack *stack_t = *stack_a;
	if (!stack_t || !stack_t->next)
		return (0);
	while (stack_t->next)
	{
		if (stack_t->data > stack_t->next->data)
			return (0);
		stack_t = stack_t->next;
	}
	return (1);
}

int	dup_checker(s_stack **stack_a)
{
	s_stack *stack_t = *stack_a;
	s_stack *stack_tmp = NULL;
	if (!stack_t || !stack_t->next)
		return (0);
	while (stack_t->next)
	{
		stack_tmp = stack_t->next;
		while (stack_tmp)
		{
			if (stack_t->data == stack_tmp->data)
				return (1);
			stack_tmp = stack_tmp->next;
		}
		stack_t = stack_t->next;
	}
	return (0);
}
