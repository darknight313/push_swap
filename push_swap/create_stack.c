/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:21:44 by ashirzad          #+#    #+#             */
/*   Updated: 2024/01/22 11:20:06 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "push_swap.h"

void	print_stack(s_stack **stack_a, s_stack **stack_b)
{
	s_stack *stack_t = *stack_a;
	s_stack *stack_p = *stack_b;
	while (stack_t || stack_p)
	{
		if (stack_t)
		{
			printf("%d", stack_t->data);
			stack_t = stack_t->next;
			fflush(stdout);
		}
		else
			write(1, " ", 1);
		if (stack_p)
		{
			write(1, "  ", 2);
			printf("%d", stack_p->data);
			stack_p = stack_p->next;
			fflush(stdout);
		}
		write(1, "\n", 1);
	}
	write(1, "-  -\n", 5);
	write(1, "a  b\n", 5);
}

void	push_stack(s_stack **stack_a, int value)
{
	s_stack *stack_tmp = malloc(sizeof(s_stack));
	stack_tmp->data = value;
	stack_tmp->index = 0;
	stack_tmp->next = *stack_a;
	stack_tmp->pre = NULL;
	*stack_a = stack_tmp;
}

void	append_stack(s_stack **stack_a, int value)
{
	s_stack *stack_t = *stack_a;
	if (!stack_t)
		push_stack(stack_a, value);
	else
	{
		while (stack_t->next)
			stack_t = stack_t->next;
		stack_t->next = malloc(sizeof(s_stack));
		stack_t->next->index = stack_t->index + 1;
		stack_t->next->pre = stack_t;
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
