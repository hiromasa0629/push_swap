/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructionstwo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:59:13 by hyap              #+#    #+#             */
/*   Updated: 2022/07/15 11:00:14 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_data *data)
{
	if (data->stack_a)
	{
		data->stack_a = data->stack_a->next;
		ft_printf("ra\n");
	}
}

void	ft_rb(t_data *data)
{
	if (data->stack_b)
	{
		data->stack_b = data->stack_b->next;
		ft_printf("rb\n");
	}
}

void	ft_rra(t_data *data)
{
	if (data->stack_a)
	{
		data->stack_a = data->stack_a->prev;
		ft_printf("rra\n");
	}
}

void	ft_rrb(t_data *data)
{
	if (data->stack_b)
	{
		data->stack_b = data->stack_b->prev;
		ft_printf("rra\n");
	}
}
