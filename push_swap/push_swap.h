/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:18:53 by ashirzad          #+#    #+#             */
/*   Updated: 2024/01/19 11:19:59 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_stack
{
	int	data;
	int	index;
	struct s_stack *pre;
	struct s_stack *next;
} s_stack;

void	print_stack(s_stack **stack_a);
void	append_stack(s_stack **stack_a, int value);
void	push_stack(s_stack **stack_a, int value);
int		count_nodes(s_stack **stack_a);


#endif

