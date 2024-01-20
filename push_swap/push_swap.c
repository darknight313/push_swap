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



