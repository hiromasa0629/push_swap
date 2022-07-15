/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:53:32 by hyap              #+#    #+#             */
/*   Updated: 2022/07/15 10:59:58 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_data *data)
{
	t_list	*tmp;
	int		num_tmp;

	tmp = data->stack_a;
	if (!tmp || !tmp->next)
		return ;
	num_tmp = data->stack_a->num;
	data->stack_a->num = data->stack_a->next->num;
	data->stack_a->next->num = num_tmp;
	ft_printf("sa\n");
}

void	ft_sb(t_data *data)
{
	t_list	*tmp;
	int		num_tmp;

	tmp = data->stack_b;
	if (!tmp || !tmp->next)
		return ;
	num_tmp = data->stack_b->num;
	data->stack_b->num = data->stack_b->next->num;
	data->stack_b->next->num = num_tmp;
	ft_printf("sb\n");
}

void	ft_ss(t_data *data)
{
	ft_sa(data);
	ft_sb(data);
}

void	ft_pa(t_data *data)
{
	t_list	*tmp;

	if (!data->stack_a)
		return ;
	data->stack_a->next->prev = data->stack_a->prev;
	data->stack_a->prev->next = data->stack_a->next;
	tmp = data->stack_a;
	if (data->stack_a != data->stack_a->next)
		data->stack_a = data->stack_a->next;
	else
		data->stack_a = NULL;
	ft_lstadd_front(&data->stack_b, tmp);
	ft_printf("pb\n");
}

void	ft_pb(t_data *data)
{
	t_list	*tmp;

	if (!data->stack_b)
		return ;
	data->stack_b->next->prev = data->stack_b->prev;
	data->stack_b->prev->next = data->stack_b->next;
	tmp = data->stack_b;
	if (data->stack_b != data->stack_b->next)
		data->stack_b = data->stack_b->next;
	else
		data->stack_b = NULL;
	ft_lstadd_front(&data->stack_a, tmp);
	ft_printf("pa\n");
}
