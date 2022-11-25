/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:09:24 by mamuller          #+#    #+#             */
/*   Updated: 2021/11/25 16:09:24 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_rev_rotate(t_list **stack)
{
	t_list	*elem1;
	t_list	*elem2;

	elem1 = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	while (elem1->next->next != NULL)
	{
		elem1 = elem1->next;
	}
	elem2 = elem1->next;
	ft_lstadd_front(stack, elem2);
	elem1->next = NULL;
}

void	ft_rev_rotate_call(t_list **stack_a, t_list **stack_b, char *operation)
{
	if (operation[2] == 'a' && ((*stack_a != NULL && (*stack_a)->next != NULL)))
	{
		ft_rev_rotate(stack_a);
		ft_putendl_fd(operation, 1);
	}
	else if (operation[2] == 'b' && \
			((*stack_b != NULL && (*stack_b)->next != NULL)))
	{
		ft_rev_rotate(stack_b);
		ft_putendl_fd(operation, 1);
	}
	else if (operation[2] == 'r' && \
			((*stack_a != NULL && (*stack_a)->next != NULL)) && \
			((*stack_b != NULL && (*stack_b)->next != NULL)))
	{
		ft_rev_rotate(stack_a);
		ft_rev_rotate(stack_b);
		ft_putendl_fd(operation, 1);
	}
}

void	ft_multi_rotates(t_list **stack_a, t_list **stack_b, char *operation)
{
	if (operation[1] == 'a' )
	{
		ft_rotate_call(stack_a, stack_b, "ra");
		ft_rotate_call(stack_a, stack_b, "ra");
		ft_push(stack_a, stack_b, "pb");
	}
	else
	{
		ft_rev_rotate_call(stack_a, stack_b, "rra");
		ft_rev_rotate_call(stack_a, stack_b, "rra");
		ft_push(stack_a, stack_b, "pb");
	}
}
