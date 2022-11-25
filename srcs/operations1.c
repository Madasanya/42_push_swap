/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:08:55 by mamuller          #+#    #+#             */
/*   Updated: 2021/11/25 16:08:55 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	ft_swap(t_list **stack)
{
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;

	if (*stack == NULL || (*stack)->next == NULL)
		return (1);
	elem1 = *stack;
	elem2 = (*stack)->next;
	elem3 = (*stack)->next->next;
	(*stack)->next->next = elem1;
	(*stack)->next = elem3;
	*stack = elem2;
	return (0);
}

void	ft_swap_call(t_list **stack_a, t_list **stack_b, char *operation)
{
	if (operation[1] == 'a' && ((*stack_a != NULL && (*stack_a)->next != NULL)))
	{
		ft_swap(stack_a);
		ft_putendl_fd(operation, 1);
	}
	else if (operation[1] == 'b' && \
			((*stack_b != NULL && (*stack_b)->next != NULL)))
	{
		ft_swap(stack_b);
		ft_putendl_fd(operation, 1);
	}
	else if (operation[1] == 's' && \
			((*stack_a != NULL && (*stack_a)->next != NULL)) && \
			((*stack_b != NULL && (*stack_b)->next != NULL)))
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
		ft_putendl_fd(operation, 1);
	}
}

void	ft_push(t_list **stack_from, t_list **stack_to, char *operation)
{
	t_list	*elem1;

	if (*stack_from == NULL)
		return ;
	elem1 = (*stack_from)->next;
	ft_lstadd_front(stack_to, (*stack_from));
	(*stack_from) = elem1;
	ft_putendl_fd(operation, 1);
}

int	ft_rotate(t_list **stack)
{
	t_list	*elem1;
	t_list	*elem2;

	if (*stack == NULL || (*stack)->next == NULL)
		return (1);
	elem1 = (*stack)->next;
	elem2 = *stack;
	ft_lstadd_back(stack, *stack);
	elem2->next = NULL;
	*stack = elem1;
	return (0);
}

void	ft_rotate_call(t_list **stack_a, t_list **stack_b, char *operation)
{
	if (operation[1] == 'a' && ((*stack_a != NULL && (*stack_a)->next != NULL)))
	{
		ft_rotate(stack_a);
		ft_putendl_fd(operation, 1);
	}
	else if (operation[1] == 'b' && \
			((*stack_b != NULL && (*stack_b)->next != NULL)))
	{
		ft_rotate(stack_b);
		ft_putendl_fd(operation, 1);
	}
	else if (operation[1] == 'r' && \
			((*stack_a != NULL && (*stack_a)->next != NULL)) && \
			((*stack_b != NULL && (*stack_b)->next != NULL)))
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
		ft_putendl_fd(operation, 1);
	}
}
