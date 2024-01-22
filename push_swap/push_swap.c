/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:30:11 by ashirzad          #+#    #+#             */
/*   Updated: 2024/01/22 14:07:49 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "push_swap.h"

void	sort_stack(s_stack **stack_a)
{
	s_stack *stack_t = *stack_a;

	int j = 0;
	while(stack_t)
	{

		if(!stack_t->next)
			{
				if(!j)
					return ;
				j = 0;
				stack_t = *stack_a;
			}
		if (stack_t->data > stack_t->next->data)
		{
			j++;
			sa(&stack_t);
		}
		stack_t = stack_t->next;
	}
}

int	main(int args, char **argv)
{
	if (args < 2)
	{
		printf("%%No arguments given.\n");
		return (0);
	}
	s_stack *stack_a = NULL;
	s_stack *stack_b = NULL;
	int i = 1;
	while (i != args)
	{
		append_stack(&stack_a, atoi(argv[i]));
		i++;
	}
	print_stack(&stack_a, &stack_b);
	write(1, "\n", 1);
	sort_stack(&stack_a);
	print_stack(&stack_a, &stack_b);
}


