/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:07:05 by mamuller          #+#    #+#             */
/*   Updated: 2021/11/25 16:07:05 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_index_assignment(int i, t_list **stack_a, int *values)
{
	int		j;
	t_list	*counter;

	j = 0;
	counter = *stack_a;
	while (j < i)
	{
		counter = *stack_a;
		while (counter)
		{
			if (values[j] == ((t_content *)(*counter).content)->value)
				((t_content *)(*counter).content)->sorted_index = j;
			counter = (*counter).next;
		}
		j++;
	}
}

void	ft_bubble_swap(int *swap_val_1, int *swap_val_2)
{
	int	temp;

	temp = *swap_val_1;
	*swap_val_1 = *swap_val_2;
	*swap_val_2 = temp;
}

void	ft_bubble_sort(int arr[], int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				ft_bubble_swap(&arr[j], &arr[j + 1]);
			j += 1;
		}
		i += 1;
	}
}

void	ft_sorted_index(t_list **stack_a)
{
	int		*values;
	int		i;
	t_list	*lst_ptr;

	values = ft_calloc(ft_lstsize(*stack_a), sizeof(int));
	lst_ptr = *stack_a;
	i = 0;
	while (i < ft_lstsize(*stack_a))
	{
		values[i] = ((t_content *)lst_ptr->content)->value;
		lst_ptr = lst_ptr->next;
		i++;
	}
	ft_bubble_sort(values, i);
	ft_index_assignment(i, stack_a, values);
	free(values);
}
