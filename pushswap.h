/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 16:00:09 by lsmit         #+#    #+#                 */
/*   Updated: 2021/09/17 15:27:18 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <libft.h>

typedef struct	stack {
	int 			data;
	struct stack		*prev;
	struct stack		*next;
}stack;

typedef struct data {
	stack	*a;
	stack	*b;
}data;

void	sa(stack **a);
void	sb(stack **b);
void	ss(stack **a, stack **b);
void	ra(stack **a);
void	rb(stack **b);
void	rr(stack **a, stack **b);
void	rra(stack **a);
void	rrb(stack **b);
void	rrr();
void	pa();
void	pb();

void	ft_add_back(stack **head, stack *new);

#endif