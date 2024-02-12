/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:08:42 by ashirzad          #+#    #+#             */
/*   Updated: 2024/02/12 13:47:03 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static s_stack	*smallest_number(s_stack **stack_a)
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
	stack_t = *stack_a;
	while (index > 0)
	{
		stack_t = stack_t->next;
		index--;
	}
	return (stack_t);
}

static s_stack *biggest_number(s_stack **stack_a)
{
	s_stack *stack_t = *stack_a;
	int	index = 0;
	if (!stack_t->next)
		return (NULL);
	int	data = stack_t->data;
	while (stack_t->next)
	{
		if (data < stack_t->next->data)
		{
			data = stack_t->next->data;
			index = stack_t->next->index;
		}
		stack_t = stack_t->next;
	}
	stack_t = *stack_a;
	while (index > 0)
	{
		stack_t = stack_t->next;
		index--;
	}
	return (stack_t);
}

void	sort_three(s_stack **stack_a)
{
	s_stack *stack_t = *stack_a;
	if (!stack_t)
		return ;
	int index = 0;
	while (!sort_checker(&stack_t))
	{
		index = biggest_number(&stack_t)->index;
		if (index == 1)
		{
			// printf("rra\n");
			rra(&stack_t);
		}
		else
		{
			// printf("sa\n");
			sa(&stack_t);
		}

	}
}

void	sort_stack(s_stack **stack_a, s_stack **stack_b)
{
	s_stack *stack_tmp = NULL;
	s_stack *stack_t = *stack_a;
	if (!(*stack_a))
		return;
	int i = 0;
	while (i < 5)
	{
		append_stack(&stack_tmp, stack_t->data);
		stack_t = stack_t->next;
		i++;
	}
	while (stack_tmp)
	{
		stack_t = *stack_a;
		while (stack_t)
		{
			int s = smallest_number(&stack_tmp)->data;
			if ()
			stack_t = stack_t->next;
		}
		stack_tmp = stack_tmp->next;
	}

}
