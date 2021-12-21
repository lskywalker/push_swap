/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 16:00:09 by lsmit         #+#    #+#                 */
/*   Updated: 2021/12/06 16:01:07 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>

typedef struct stack {
	int					data;
	struct stack		*prev;
	struct stack		*next;
}t_stack;

typedef struct data {
	t_stack	*a;
	t_stack	*b;
}t_data;

typedef struct info {
	double		chunck;
	double		prev;
	double		nb;
	double		i;
	double		j;
	int			biggest;
	double		oldamount;
	int			on;
}t_info;

void	sasb(t_stack **s, int type);
void	rarb(t_stack **s, int type);
void	rrarrb(t_stack **s, int type);
void	push(t_stack **src, t_stack **dst, int type);

void	ft_add_back(t_stack **head, t_stack *new);
void	pushback(t_stack **a, t_stack **b, t_stack *head, double amount);
void	rotate(t_stack **head, t_info *i);
void	ft_pushstack(t_stack **list, int data);
t_stack	*ft_newlist(int data);
void	ft_add_back(t_stack **head, t_stack *new);
int		precheck(t_stack *a);
int		findnb(t_stack *a, int nb, int i);
int		stepsfrombottom(t_stack *a, int prev, int nb);
int		stepsfromtop(t_stack *a, int prev, int nb);
int		ft_findbiggest(t_stack *a);
int		ft_findsmallest(t_stack *a);
void	smallstack(t_stack **a, int smallest);
void	midsizestack(t_stack **a, t_stack **b, int amount);
t_stack	*totop(t_stack *a, int nb, int bs, int amount);
void	ft_exit(void);
int		ft_listsize(t_stack *list);

int		ft_strlen(char const *str);
char	**ft_split(char const *s, char c);
int		ft_atoi(char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(char *s, int fd);

#endif