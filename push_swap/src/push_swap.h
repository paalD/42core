/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:24:06 by dpaal             #+#    #+#             */
/*   Updated: 2022/05/22 12:59:04 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int			push_swap(int fd);
long long	ft_atolli(const char *str);

//			swap.c
void		swap(t_list **stack);
int			sa(t_list **stack);
int			sb(t_list **stack);
int			ss(t_list **stack_a, t_list **stack_b);

//			rotate.c
int			ra(t_list **stack);
int			rb(t_list **stack);
int			rr(t_list **stack_a, t_list **stack_b);

//			reverse_rotate.c
int			rra(t_list **stack);
int			rrb(t_list **stack);
int			rrr(t_list **stack_a, t_list **stack_b);

//			push.c
int			pa(t_list **stack_b, t_list **stack_a);
int			pb(t_list **stack_a, t_list **stack_b);

//			lst_utils.c
t_list		*ft_lstnew(int content);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			listsize(t_list **list);
int			listmax(t_list **list);
int			listmin(t_list **list);

//			utils.c
int			find_next(t_list **list, int min, int max);
void		adjust_lists(t_list **stack_a, t_list **stack_b, int ac, int bc);
void		smart_rotate(t_list **stack_a, int n);

//			index_list.c
void		index_lst(t_list **lst, int lstsize);

//			check_input.c
int			check_input(int argc, char **argv);

//			sort_five.c
void		sort_five(t_list **stack_a, t_list **stack_b, int n);

//			sort_more.c
void		sort_more(t_list **stack_a, t_list **stack_b, int min, int max);

//			sort_more_utils.c
void		pushrange_a(t_list **stack_a, t_list **stack_b, int min, int max);
void		pushrange_b(t_list **stack_a, t_list **stack_b, int min, int max);
void		simple_pr_a(t_list **stack_a, t_list **stack_b, int min, int max);
void		simple_pr_b(t_list **stack_a, t_list **stack_b, int min, int max);

#endif
