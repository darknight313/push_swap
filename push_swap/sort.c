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
		return (NULL);
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

s_stack *biggest_number(s_stack **stack_a)
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

static void	bubble_sort(s_stack **stack_a)
{
	s_stack *stack_t = *stack_a;
	if (!stack_t)
		return ;
	int	i = 0;
	while (stack_t)
	{
		if (!stack_t->next)
		{
			if (!i)
				return ;
			i = 0;
			stack_t = *stack_a;
		}
		if (stack_t->data < stack_t->next->data)
		{
			sa(&stack_t);
			i++;
		}
		stack_t = stack_t->next;
	}
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
			printf("rra\n");
			rra(&stack_t);
		}
		else
		{
			printf("sa\n");
			sa(&stack_t);
		}

	}
}

static void	push_to_b(s_stack **stack_a, s_stack **stack_b, int index)
{
	if (!(*stack_a))
		return ;
	if (index < (count_nodes(stack_a) / 2))
	{
		while (index > 0)
		{
			printf("ra\n");
			ra(stack_a);
			index--;
		}
	}
	else
	{
		while (index < count_nodes(stack_a))
		{
			printf("rra\n");
			rra(stack_a);
			index++;
		}
	}
	printf("pb\n");
	pa(stack_b, stack_a);
}

static void	sort_chunk(s_stack **stack_a, s_stack **stack_b, s_stack **stack_tmp)
{
	while (*stack_tmp)
	{
		s_stack *stack_t = *stack_a;
		while (stack_t)
		{
			if (stack_t->data == (*stack_tmp)->data)
			{
				push_to_b(stack_a, stack_b, stack_t->index);
				break ;
			}
			stack_t = stack_t->next;
		}
		*stack_tmp = (*stack_tmp)->next;
	}
}

void	sort_stack(s_stack **stack_a, s_stack **stack_b)
{
	s_stack *stack_t = *stack_a;
	if (!(*stack_a))
		return;
	s_stack *tmp_one = NULL;
	s_stack *tmp_two = NULL;
	s_stack *tmp_three = NULL;
	s_stack *tmp_four = NULL;
	s_stack *tmp_five = NULL;
	while (stack_t)
	{
		if (stack_t->index < 20)
			append_stack(&tmp_one, stack_t->data);
		else if (stack_t->index >= 20 && stack_t->index < 40)
			append_stack(&tmp_two, stack_t->data);
		else if (stack_t->index >= 40 && stack_t->index < 60)
			append_stack(&tmp_three, stack_t->data);
		else if (stack_t->index >= 60 && stack_t->index < 80)
			append_stack(&tmp_four, stack_t->data);
		else
			append_stack(&tmp_five, stack_t->data);
		stack_t = stack_t->next;
	}
	bubble_sort(&tmp_one);
	bubble_sort(&tmp_two);
	bubble_sort(&tmp_three);
	bubble_sort(&tmp_four);
	bubble_sort(&tmp_five);
	sort_chunk(stack_a, stack_b, &tmp_one);
	sort_chunk(stack_a, stack_b, &tmp_two);
	sort_chunk(stack_a, stack_b, &tmp_three);
	sort_chunk(stack_a, stack_b, &tmp_four);
	sort_chunk(stack_a, stack_b, &tmp_five);
}
