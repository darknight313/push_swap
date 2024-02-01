/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:30:11 by ashirzad          #+#    #+#             */
/*   Updated: 2024/02/01 11:24:40 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "push_swap.h"

// void	sort_stack(s_stack **stack_a)
// {
// 	s_stack *stack_t = *stack_a;

// 	int j = 0;
// 	while(stack_t)
// 	{

// 		if(!stack_t->next)
// 			{
// 				if(!j)
// 					return ;
// 				j = 0;
// 				stack_t = *stack_a;
// 			}
// 		if (stack_t->data > stack_t->next->data)
// 		{
// 			j++;
// 			sa(&stack_t);
// 		}
// 		stack_t = stack_t->next;
// 	}
// }

int	smallest_number(s_stack **stack_a)
{
	s_stack *stack_t = *stack_a;
	int	index = 0;
	if (!stack_t->next)
		return (index);
	int	data = stack_t->data;
	while (stack_t->next)
	{
		if (data > stack_t->next->data)
		{
			data = stack_t->next->data;
			index = stack_t->next->index;
		}
		stack_t = stack_t->next;
	}
	return (index);
}

void	sort_stack(s_stack **stack_a, s_stack **stack_b)
{
	s_stack *stack_t = *stack_a;
	s_stack *stack_p = *stack_b;
	if (!stack_t)
		return ;
	int i = 0;
	while (count_nodes(&stack_t) > 1)
	{
		int	index = smallest_number(&stack_t);
		while (index > 0)
		{
			printf("move : %d\n", i);
			i++;
			ra(&stack_t);
			index--;
		}
		printf("move : %d\n", i);
		i++;
		pb(&stack_t, &stack_p);
	}
}


int	main(int args, char **argv)
{
	s_stack *stack_a = NULL;
	s_stack *stack_b = NULL;
	int i = 1;
	while (i < args)
	{
		append_stack(&stack_a, atoi(argv[i]));
		i++;
	}
	sort_stack(&stack_a, &stack_b);
	
}


