/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   pushswap.h										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mamuller <mamuller@student.42wolfsburg>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/11/25 13:15:03 by mamuller		  #+#	#+#			 */
/*   Updated: 2021/11/25 13:15:03 by mamuller		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/incl/libft.h"

typedef struct s_content
{
	int				value;
	int				sorted_index;
}			t_content;

/* sort_forwarding_n_calls.c*/
void	ft_handle_three(t_list **stack_a, t_list **stack_b);
void	ft_handle_four(t_list **stack_a, t_list **stack_b, int j);
void	ft_handle_five(t_list **stack_a, t_list **stack_b);
void	ft_amount_handler(t_list **stack_a, t_list **stack_b);

/*radix.c*/
void	ft_stack_assignment(t_list **stack_a, t_list **sstack_b, int i);
int		ft_get_bits(t_list **stack_a);
void	ft_handle_bigger_five(t_list **stack_a, t_list **stack_b);

/*input_checks_n_init.c*/
int		ft_digit_check(char *argv);
int		ft_sorted_checker(t_list *stack_a);
int		ft_duplic_checker(t_list *stack_a);
void	ft_input_check(int argc, char **argv, t_list **stack_a);
void	ft_stack_init(int argc, char **argv, t_list **stack_a);

/*pre_processing.c*/
void	ft_index_assignment(int i, t_list **stack_a, int *values);
void	ft_bubble_swap(int *swap_val_1, int *swap_val_2);
void	ft_bubble_sort(int arr[], int n);
void	ft_sorted_index(t_list **stack_a);

/*utils.c*/
void	ft_del(void *content);
void	ft_error_printer(t_list **stack);
long	ft_strtol(const char *str);

/*operations1.c*/
int		ft_swap(t_list **stack);
void	ft_swap_call(t_list **stack_a, t_list **stack_b, char *operation);
void	ft_push(t_list **stack_from, t_list **stack_to, char *operation);
int		ft_rotate(t_list **stack);
void	ft_rotate_call(t_list **stack_a, t_list **stack_b, char *operation);

/*operations2.c*/
void	ft_rev_rotate(t_list **stack);
void	ft_rev_rotate_call(t_list **stack_a, t_list **stack_b, char *operation);
void	ft_multi_rotates(t_list **stack_a, t_list **stack_b, char *operation);

#endif