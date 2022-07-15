/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:41:27 by hyap              #+#    #+#             */
/*   Updated: 2022/07/15 10:58:28 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_smallest	*find_smallest_pos(t_list *lst)
{
	t_smallest	*smallest;
	t_list		*head;
	int			index;
	int			is_last;

	smallest = (t_smallest *)malloc(sizeof(t_smallest));
	smallest->num = lst->num;
	head = lst;
	index = 0;
	is_last = 0;
	while (!is_last)
	{
		if (lst == head->prev)
			is_last = 1;
		if (smallest->num > lst->num)
		{
			smallest->num = lst->num;
			smallest->pos = index;
		}
		lst = lst->next;
		index++;
	}
	return (smallest);
}

void	push_smallest(t_data *data)
{
	int			size;
	t_smallest	*smallest;

	smallest = find_smallest_pos(data->stack_a);
	size = ft_lstsize(data->stack_a);
	if (smallest->pos <= (size / 2))
		while (data->stack_a->num != smallest->num)
			ft_ra(data);
	else
		while (data->stack_a->num != smallest->num)
			ft_rra(data);
	ft_pa(data);
	free(smallest);
}

void	insertion(t_data *data)
{
	while (data->stack_a)
		push_smallest(data);
	while (data->stack_b)
		ft_pb(data);
}
