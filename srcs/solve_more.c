/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:02:08 by hyap              #+#    #+#             */
/*   Updated: 2022/07/15 11:04:02 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insert_numth(t_data *data, int search, int index)
{
	t_list	*tmp;

	tmp = data->stack_a;
	while (tmp->num != search)
		tmp = tmp->next;
	tmp->numth = index;
	tmp->inserted = 1;
}

void	simplify_list(t_data *data)
{
	t_list	*ay;
	int		is_last;
	int		smallest;
	int		index;
	int		size;

	index = 0;
	size = ft_lstsize(data->stack_a);
	while (index < size)
	{
		ay = data->stack_a;
		while (ay->inserted)
			ay = ay->next;
		smallest = ay->num;
		is_last = 0;
		while (!is_last)
		{
			if (ay == data->stack_a->prev)
				is_last = 1;
			if (smallest > ay->next->num && !ay->next->inserted)
				smallest = ay->next->num;
			ay = ay->next;
		}
		insert_numth(data, smallest, index++);
	}
}

void	radix_sort(t_data *data, int index)
{
	t_list	*ay;
	t_list	*last;
	int		is_last;

	ay = data->stack_a;
	last = data->stack_a->prev;
	is_last = 0;
	while (!is_last)
	{
		if (ay == last)
			is_last = 1;
		if (((ay->numth >> index) & 1) == 1)
		{
			ft_ra(data);
			ay = ay->next;
		}
		else
		{
			ay = ay->next;
			ft_pa(data);
		}
	}
	while (data->stack_b)
		ft_pb(data);
}

void	solve_more(t_data *data)
{
	int	index;

	index = 0;
	simplify_list(data);
	while (!is_sorted(data->stack_a))
		radix_sort(data, index++);
}
