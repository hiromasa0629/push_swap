/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:25:58 by hyap              #+#    #+#             */
/*   Updated: 2022/07/15 11:11:14 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "./ft_printf.h"

typedef struct s_list
{
	int				num;
	int				numth;
	int				inserted;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef struct s_data {
	int		initial_size;
	t_list	*stack_a;
	t_list	*stack_b;
}				t_data;

typedef struct s_smallest {
	int		pos;
	int		num;
}				t_smallest;

typedef struct s_tmp {
	int				num;
	struct s_tmp	*next;
	struct s_list	*prev;
}				t_tmp;

void		ft_putnbr_nl(int n);
void		ft_putstr_nl(char *s);
long long	ft_atoi(const char *s);
void		exit_error(void);
void		validate(char **av);
void		check_dup(t_data *data, int num);
void		ft_sa(t_data *data);
void		ft_sb(t_data *data);
void		ft_pa(t_data *data);
void		ft_pb(t_data *data);
t_list		*ft_lstnew(int num);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void		print_lst(t_data *data);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_ra(t_data *data);
void		ft_rb(t_data *data);
void		ft_rra(t_data *data);
void		ft_rrb(t_data *data);
void		solve_three_num(t_data *data);
void		solve_five_num(t_data *data);
void		insertion(t_data *data);
int			is_sorted(t_list *lst);
char		**ft_split(char *s, char c);
void		print_hori(t_list *lst);
void		solve_more(t_data *data);
void		print_hori_with_numth(t_data *data);

#endif