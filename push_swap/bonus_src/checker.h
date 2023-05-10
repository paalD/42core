/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:17:49 by dpaal             #+#    #+#             */
/*   Updated: 2022/05/22 18:31:56 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

//				checker_utils.c
int				ft_strcmp(char *s1, char *s2);
int				check_list(t_list **stack_a, t_list **stack_b);
void			free_list(t_list **list);

//				ft_atolli.c
long long		ft_atolli(const char *str);

//				input_validation.c
int				check_input(int argc, char **argv);

//				lst_utils.c
t_list			*ft_lstnew(int content);
int				ft_lstadd_back(t_list **lst, t_list *new);

//				index_list.c
void			index_lst(int listsize, t_list **list);

//				str_utils.c
char			*ft_strjoin(char *s1, char *s2);
void			*ft_calloc(size_t nmemb, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

//				ft_split.c
char			**ft_split(char const *s, char c);

//				swap.c
void			swap(t_list **stack);
int				sa(t_list **stack);
int				sb(t_list **stack);
int				ss(t_list **stack_a, t_list **stack_b);

//				rotate.c
int				ra(t_list **stack);
int				rb(t_list **stack);
int				rr(t_list **stack_a, t_list **stack_b);

//				reverse_rotate.c
int				rra(t_list **stack);
int				rrb(t_list **stack);
int				rrr(t_list **stack_a, t_list **stack_b);

//				push.c
int				pa(t_list **stack_b, t_list **stack_a);
int				pb(t_list **stack_a, t_list **stack_b);

#endif
