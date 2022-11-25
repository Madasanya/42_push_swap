/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:05:58 by mamuller          #+#    #+#             */
/*   Updated: 2021/11/25 16:05:58 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_stack_assignment(t_list **stack_a, t_list **stack_b, int i)
{
	int	j;
	int	stack_a_size;

	stack_a_size = ft_lstsize(*stack_a);
	j = 0;
	while (j < stack_a_size)
	{
		if (((((t_content *)(*stack_a)->content)->sorted_index) >> i & 1) == 1)
			ft_rotate_call(stack_a, stack_b, "ra");
		else
			ft_push(stack_a, stack_b, "pb");
		j += 1;
	}
}

int	ft_get_bits(t_list **stack_a)
{
	int	max;
	int	bits;

	bits = 0;
	max = ft_lstsize(*stack_a) - 1;
	while ((max >> bits) != 0)
		bits++;
	bits++;
	return (bits);
}

void	ft_handle_bigger_five(t_list **stack_a, t_list **stack_b)
{
	int		j;
	int		bits;
	int		i;
	int		stack_b_size;

	stack_b_size = 0;
	bits = ft_get_bits(stack_a);
	j = 0;
	i = 0;
	while (i < bits)
	{
		ft_stack_assignment(stack_a, stack_b, i);
		j = 0;
		stack_b_size = ft_lstsize(*stack_b);
		while (j < stack_b_size)
		{
			ft_push(stack_b, stack_a, "pa");
			j += 1;
		}
		if (ft_sorted_checker(*stack_a) == 1 && !*stack_b)
			return ;
		i++;
	}
}
