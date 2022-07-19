/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:32:25 by hyap              #+#    #+#             */
/*   Updated: 2022/07/19 15:05:14 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/push_swap.h>

void	solve_less(t_data *data)
{
	if (data->initial_size <= 3)
		while (!is_sorted(data->stack_a))
			solve_three_num(data);
	else if (data->initial_size <= 5)
		solve_five_num(data);
}

void	create_stacks(char **av, t_data *data)
{
	long long	num;
	int			index;

	index = 0;
	data->stack_b = NULL;
	while (av[index])
	{
		num = ft_atoi(av[index]);
		if (num > __INT_MAX__ || num < -__INT_MAX__ - 1)
			exit_error();
		ft_lstadd_back(&data->stack_a, ft_lstnew(num));
		check_dup(data, num);
		index++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	data.initial_size = 0;
	if (ac < 2)
		exit_error();
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av = &av[1];
	validate(av);
	create_stacks(av, &data);
	data.initial_size = ft_lstsize(data.stack_a);
	if (is_sorted(data.stack_a))
		return (0);
	if (ft_lstsize(data.stack_a) <= 5)
		solve_less(&data);
	else
		solve_more(&data);
	return (0);
}
