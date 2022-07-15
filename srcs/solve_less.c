/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_less.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:57:02 by hyap              #+#    #+#             */
/*   Updated: 2022/07/15 11:03:18 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve_three_num(t_data *data)
{
	t_list	*head;

	head = data->stack_a;
	if (head->num > head->next->num && head->num > head->next->next->num)
		ft_ra(data);
	else if (head->num > head->next->num && head->num < head->next->next->num)
		ft_sa(data);
	else if (head->num < head->next->num && head->num > head->next->next->num)
		ft_rra(data);
	else if (head->num < head->next->num
		&& head->next->num > head->next->next->num)
	{
		ft_sa(data);
		ft_ra(data);
	}
}

int	solve_five_helper(t_list *stack_a, int bee_num)
{
	int		pos;
	int		is_last;
	t_list	*ay;

	ay = stack_a;
	pos = 0;
	is_last = 0;
	while (!is_last)
	{
		if (ay == stack_a->prev)
			is_last = 1;
		if (ay->num > bee_num)
			return (pos);
		pos++;
		ay = ay->next;
	}
	return (pos);
}

void	solve_five_op_one(t_data *data, int pos)
{
	int	tmp_pos;

	tmp_pos = pos;
	while (pos-- != 0)
		ft_ra(data);
	ft_pb(data);
	if (data->stack_b)
	{
		if (data->stack_b->num > data->stack_a->num
			&& data->stack_b->num < data->stack_a->prev->num)
		{
			ft_pb(data);
			ft_rra(data);
		}
	}
	while (tmp_pos-- != 0)
		ft_rra(data);
}

void	solve_five_op_two(t_data *data, int pos, int size)
{
	int	tmp_pos;

	tmp_pos = pos;
	while (pos++ != size)
		ft_rra(data);
	ft_pb(data);
	if (data->stack_b)
	{
		if (data->stack_b->num < data->stack_a->num
			&& data->stack_b->num > data->stack_a->prev->num)
		{
			ft_pb(data);
			ft_ra(data);
		}
	}
	while (tmp_pos++ != size + 1)
		ft_ra(data);
}

void	solve_five_num(t_data *data)
{
	int		pos;
	int		size;
	int		tmp_pos;

	while (ft_lstsize(data->stack_a) > 3)
		ft_pa(data);
	while (!is_sorted(data->stack_a))
		solve_three_num(data);
	while (data->stack_b)
	{
		size = ft_lstsize(data->stack_a);
		pos = solve_five_helper(data->stack_a, data->stack_b->num);
		tmp_pos = pos;
		if (pos == 0)
			ft_pb(data);
		else if (pos == size)
		{
			ft_pb(data);
			ft_ra(data);
		}
		else if (pos <= (size / 2))
			solve_five_op_one(data, pos);
		else if (pos > (size / 2))
			solve_five_op_two(data, pos, size);
	}
}
