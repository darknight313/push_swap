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
	sort_three(&stack_a);
	print_stack(&stack_a);
}


