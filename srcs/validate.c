/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:04:07 by hyap              #+#    #+#             */
/*   Updated: 2022/07/15 11:06:19 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_inputs(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	if (!*s)
		exit_error();
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			exit_error();
		s++;
	}
}

void	validate(char **av)
{
	int		index;
	char	*s;

	index = 0;
	while (av[index])
	{
		s = av[index++];
		check_inputs(s);
	}
}

void	check_dup(t_data *data, int num)
{
	t_list	*tmp;

	tmp = data->stack_a;
	if (!tmp)
		return ;
	if (tmp->next == data->stack_a)
		return ;
	while (tmp->next != data->stack_a)
	{
		if (tmp->num == num)
			exit_error();
		tmp = tmp->next;
	}
}

int	is_sorted(t_list *lst)
{
	int		is_last;
	t_list	*tmp;

	tmp = lst;
	is_last = 0;
	while (!is_last)
	{
		if (tmp == lst->prev)
			is_last = 1;
		if (tmp->next->num < tmp->num && tmp != lst->prev)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
