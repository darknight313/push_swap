/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:30:11 by ashirzad          #+#    #+#             */
/*   Updated: 2024/01/20 22:07:18 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "push_swap.h"

void	sa(s_stack **stack_a)
{
	s_stack *stack_t = *stack_a;
	if (count_nodes(&stack_t) < 2)
	{
		printf("Less than two arguments.\n");
		return ;
	}
	int tmp = stack_t->data;
	stack_t->data = stack_t->next->data;
	stack_t->next->data = tmp;
}

void	sb(s_stack **stack_b)
{
	s_stack *stack_p = *stack_b;
	if (count_nodes(&stack_p) < 2)
		return ;
	int tmp = stack_p->data;
	stack_p->data = stack_p->next->data;
	stack_p->next->data = tmp;
}

void	ss(s_stack **stack_a, s_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(s_stack **stack_a, s_stack **stack_b)
{
	s_stack *stack_p = *stack_b;
	if (count_nodes(&stack_p) < 1)
		return ;
	int tmp = stack_p->data;
	append_stack(stack_a, tmp);
	stack_p = (*stack_b)->next;
	if (stack_p == NULL)
	{
		*stack_b = NULL;
		return ;
	}
	stack_p->pre = NULL;
	*stack_b = stack_p;
}

void	pb(s_stack **stack_a, s_stack **stack_b)
{
	s_stack *stack_t = *stack_a;
	if (count_nodes(&stack_t) < 1)
		return ;
	int tmp = stack_t->data;
	append_stack(stack_b, tmp);
	stack_t = (*stack_a)->next;
	if (stack_t == NULL)
	{
		*stack_a = NULL;
		return ;
	}
	stack_t->pre = NULL;
	*stack_a = stack_t;
}

void	ra(s_stack **stack_a)
{
	s_stack *stack_t = *stack_a;
	s_stack *stack_tmp;
	if (!stack_t)
		return ;
	while(stack_t)
	{
		append_stack(&stack_tmp, stack_t->data);
		stack_t = stack_t->next;
	}
	*stack_a = stack_tmp;
}

void	rb(s_stack **stack_b)
{
	s_stack *stack_p = *stack_b;
	s_stack *stack_tmp;
	if (!stack_p)
		return ;
	while(stack_p)
	{
		append_stack(&stack_tmp, stack_p->data);
		stack_p = stack_p->next;
	}
	*stack_b = stack_tmp;
}

void	rr(s_stack **stack_a, s_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

int	main(int args, char **argv)
{
	s_stack *stack_a = NULL;
	if (args < 2)
	{
		printf("%%No arguments given.\n");
		return (0);
	}
	int i = 1;
	while (i != args)
	{
		push_stack(&stack_a, atoi(argv[i]));
		i++;
	}
	print_stack(&stack_a);
	sa(&stack_a);
	write(1, "\n", 1);
	

}



