/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks_n_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:06:44 by mamuller          #+#    #+#             */
/*   Updated: 2021/11/25 16:06:44 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	ft_digit_check(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 0 && i != 0)
			return (1);
		else if ((ft_isdigit(argv[i]) == 1) || (argv[0] == '-'))
			i++;
		else
			i++;
	}
	if ((argv[0] == '-') && !(argv[1]))
		return (1);
	return (0);
}

int	ft_sorted_checker(t_list *stack_a)
{
	while (stack_a != NULL && stack_a->next != NULL)
	{
		if (((t_content *)(stack_a->content))->value < \
			((t_content *)(stack_a->next->content))->value)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (1);
}

int	ft_duplic_checker(t_list *stack_a)
{
	t_list	*ptr;
	int		x;

	ptr = stack_a->next;
	while (stack_a->next != NULL)
	{
		ptr = stack_a->next;
		x = ((t_content *)stack_a->content)->value;
		while (ptr != NULL)
		{
			if (((t_content *)ptr->content)->value == x)
				return (1);
			ptr = ptr->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

void	ft_input_check(int argc, char **argv, t_list **stack_a)
{
	if (argc == 2)
	{
		if (ft_digit_check(argv[1]) == 1)
			ft_error_printer(stack_a);
	}
	else if (argc < 3)
		return ;
	else
		ft_stack_init(argc, argv, stack_a);
	if (ft_sorted_checker(*stack_a) == 1)
	{
		ft_lstclear(stack_a, ft_del);
		return ;
	}
	if (ft_duplic_checker(*stack_a) == 1)
		ft_error_printer(stack_a);
	ft_sorted_index(stack_a);
}

void	ft_stack_init(int argc, char **argv, t_list **stack_a)
{
	int			i;
	long		int_check;
	t_content	*elem;

	i = 1;
	while (i < argc)
	{
		if (ft_digit_check(argv[i]) == 1)
			ft_error_printer(stack_a);
		int_check = ft_strtol(argv[i]);
		if (int_check > 2147483647 || int_check < -2147483648)
			ft_error_printer(stack_a);
		elem = ft_calloc(sizeof(t_content), 1);
		elem->value = int_check;
		ft_lstadd_back(stack_a, ft_lstnew(elem));
		i++;
	}
}
