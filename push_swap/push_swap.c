/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:30:11 by ashirzad          #+#    #+#             */
/*   Updated: 2024/02/12 13:42:17 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "push_swap.h"

void	final_sort(s_stack **stack_a, s_stack **stack_b)
{
	while (count_nodes(stack_b) > 3)
	{
		int index = biggest_number(stack_b)->index;
		if (index < (count_nodes(stack_b) / 2))
		{
			while (index > 0)
			{
				printf("ra\n");
				ra(stack_b);
				index--;
			}
		}
		else
		{
			while (index < count_nodes(stack_b))
			{
				printf("rra\n");
				rra(stack_b);
				index++;
			}
		}
		printf("pa\n");
		pa(stack_a, stack_b);
	}
	sort_three(stack_b);
	printf("rra\n");
	rra(stack_b);
	printf("pa\n");
	pa(stack_a, stack_b);
	printf("rra\n");
	rra(stack_b);
	printf("pa\n");
	pa(stack_a, stack_b);
	printf("pa\n");
	pa(stack_a, stack_b);
}

int	main(int args, char **argv)
{
	s_stack *stack_a = NULL;
	s_stack *stack_b = NULL;
	int	i = 1;
	while (i < args)
	{
		append_stack(&stack_a, atoi(argv[i]));
		i++;
	}
	sort_stack(&stack_a, &stack_b);
	final_sort(&stack_a, &stack_b);
}


