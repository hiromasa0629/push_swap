/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilstwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:08:39 by hyap              #+#    #+#             */
/*   Updated: 2022/07/15 11:06:31 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_lstnew(int num)
{
	t_list	*a;

	a = (t_list *)malloc(sizeof(t_list));
	if (!a)
		return (NULL);
	a->num = num;
	a->next = NULL;
	a->prev = NULL;
	a->inserted = 0;
	return (a);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (!tmp)
		return (lst);
	if (!tmp->next)
		tmp->next = tmp;
	if (tmp->next == lst)
		return (lst);
	while (tmp->next != lst)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		(*lst)->next = *lst;
		(*lst)->prev = *lst;
		return ;
	}
	new->next = *lst;
	new->prev = (*lst)->prev;
	(*lst)->prev->next = new;
	(*lst)->prev = new;
}

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;

	size = 0;
	tmp = lst;
	if (!tmp)
		return (size);
	if (tmp == tmp->next)
		return (++size);
	size++;
	while (tmp != lst->prev)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		(*lst)->next = (*lst);
		(*lst)->prev = (*lst);
		return ;
	}
	new->next = *lst;
	new->prev = (*lst)->prev;
	(*lst)->prev->next = new;
	(*lst)->prev = new;
	*lst = new;
}
