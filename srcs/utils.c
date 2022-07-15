/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:37:21 by hyap              #+#    #+#             */
/*   Updated: 2022/07/15 11:04:52 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putstr_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	write(1, "\n", 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
	write(fd, "\n", 1);
}

void	exit_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

long long	ft_atoi(const char *s)
{
	int			i;
	long long	ans;
	long long	res;

	ans = 1;
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			ans = ans * -1;
		i++;
	}
	res = 0;
	while (s[i] >= '0' && s[i] <= '9')
		res = (res * 10) + (s[i++] - '0');
	ans = ans * res;
	return (ans);
}
