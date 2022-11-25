/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_forwarding_n_calls.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:05:21 by mamuller          #+#    #+#             */
/*   Updated: 2021/11/25 16:05:21 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_handle_three(t_list **stack_a, t_list **stack_b)
{
	int	value[3];

	value[0] = ((t_content *)(*stack_a)->content)->value;
	value[1] = ((t_content *)(*stack_a)->next->content)->value;
	value[2] = ((t_content *)(*stack_a)->next->next->content)->value;
	if (value[0] > value[1] && value[1] < value[2] && value[0] < value[2])
		ft_swap_call(stack_a, stack_b, "sa");
	else if (value[0] > value[1] && value[1] > value[2] && value[0] > value[2])
	{
		ft_swap_call(stack_a, stack_b, "sa");
		ft_rev_rotate_call(stack_a, stack_b, "rra");
	}
	else if (value[0] > value[1] && value[1] < value[2] && value[0] > value[2])
		ft_rotate_call(stack_a, stack_b, "ra");
	else if (value[0] < value[1] && value[1] > value[2] && value[0] < value[2])
	{
		ft_swap_call(stack_a, stack_b, "sa");
		ft_rotate_call(stack_a, stack_b, "ra");
	}
	else if (value[0] < value[1] && value[1] > value[2] && value[0] > value[2])
		ft_rev_rotate_call(stack_a, stack_b, "rra");
}

void	ft_handle_four(t_list **stack_a, t_list **stack_b, int j)
{
	if ((((t_content *)(*stack_a)->content)->sorted_index) == j)
		ft_push(stack_a, stack_b, "pb");
	else if ((((t_content *)(*stack_a)->next->content)->sorted_index) == j)
	{
		ft_rotate_call(stack_a, stack_b, "ra");
		ft_push(stack_a, stack_b, "pb");
	}
	else if ((((t_content *)(*stack_a)->next->next->content)->sorted_index) \
		== j)
		ft_multi_rotates(stack_a, stack_b, "rra");
	else
	{
		ft_rev_rotate_call(stack_a, stack_b, "rra");
		ft_push(stack_a, stack_b, "pb");
	}
	ft_handle_three(stack_a, stack_b);
	ft_push(stack_b, stack_a, "pa");
}

void	ft_handle_five(t_list **stack_a, t_list **stack_b)
{
	if ((((t_content *)(*stack_a)->content)->sorted_index) == 0)
		ft_push(stack_a, stack_b, "pb");
	else if ((((t_content *)(*stack_a)->next->content)->sorted_index) == 0)
	{
		ft_rotate_call(stack_a, stack_b, "ra");
		ft_push(stack_a, stack_b, "pb");
	}
	else if ((((t_content *)(*stack_a)->next->next->content)->sorted_index) \
		== 0)
		ft_multi_rotates(stack_a, stack_b, "ra");
	else if \
		((((t_content *)(*stack_a)->next->next->next->content)->sorted_index) \
		== 0)
		ft_multi_rotates(stack_a, stack_b, "rra");
	else
	{
		ft_rev_rotate_call(stack_a, stack_b, "rra");
		ft_push(stack_a, stack_b, "pb");
	}
	ft_handle_four(stack_a, stack_b, 1);
	ft_push(stack_b, stack_a, "pa");
}

void	ft_amount_handler(t_list **stack_a, t_list **stack_b)
{
	int	amount;

	amount = ft_lstsize(*stack_a);
	if (amount == 2)
		ft_swap_call(stack_a, stack_b, "sa");
	else if (amount == 3)
		ft_handle_three(stack_a, stack_b);
	else if (amount == 4)
		ft_handle_four(stack_a, stack_b, 0);
	else if (amount == 5)
		ft_handle_five(stack_a, stack_b);
	else if (amount > 5)
		ft_handle_bigger_five(stack_a, stack_b);
}
