/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:08:16 by mamuller          #+#    #+#             */
/*   Updated: 2021/11/25 16:08:16 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_del(void *content)
{
	free((t_content *)content);
}

void	ft_error_printer(t_list **stack)
{
	write(2, "Error!\n", 7);
	ft_lstclear(stack, ft_del);
	exit(EXIT_FAILURE);
}

long	ft_strtol(const char *str)
{
	int		i;
	long	j;
	long	k;

	i = 0;
	j = 1;
	k = 0;
	while (str[i] != '\0' && (str[i] == ' ' || (str[i] > 8 && str[i] < 14)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] > 47 && str[i] < 58))
	{
		k = k * 10 + (str[i] - 48);
		i++;
	}
	return (k * j);
}
