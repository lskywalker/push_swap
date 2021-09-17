/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/17 14:10:22 by lsmit         #+#    #+#                 */
/*   Updated: 2021/09/17 18:11:08 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <stdio.h>

void	sa(stack **a)
{
	int tmp;
	int	tmp2;

	tmp = (*a)->data;
	*a = (*a)->prev;
	tmp2 = (*a)->data;
	(*a)->data = tmp;
	*a = (*a)->next;
	(*a)->data = tmp2;
	ft_putstr_fd("sa\n", 0);
}

void	sb(stack **b)
{
	int tmp;
	int	tmp2;

	tmp = (*b)->data;
	*b = (*b)->prev;
	tmp2 = (*b)->data;
	(*b)->data = tmp;
	*b = (*b)->next;
	(*b)->data = tmp2;
	ft_putstr_fd("sb\n", 0);
}

void	ss(stack **a, stack **b)
{
	sa(a);
	sb(b);
	ft_putstr_fd("ss\n", 0);
}

void	ra(stack **a)
{
	stack	*tmp;

	tmp = *a;
	*a = (*a)->prev;
	tmp->prev = NULL;
	(*a)->next = NULL;
	ft_add_back(a, tmp);
	ft_putstr_fd("ra\n", 0);
}

void	rb(stack **b)
{
	stack	*tmp;

	tmp = *b;
	*b = (*b)->prev;
	tmp->prev = NULL;
	(*b)->next = NULL;
	ft_add_back(b, tmp);
	ft_putstr_fd("rb\n", 0);
}

void	rr(stack **a, stack **b)
{
	ra(a);
	rb(b);
	ft_putstr_fd("rr\n", 0);
}

void	rra(stack **a)
{
	stack	*tmp;

	tmp = *a;
	while(tmp->prev != NULL)
		tmp = tmp->prev;
	tmp->prev = *a;
	*a = tmp;
	tmp->next->prev = NULL;
	(*a)->next = NULL;
	ft_putstr_fd("rra\n", 0);
}

void	rrb(stack **b)
{
	stack	*tmp;

	tmp = *b;
	while(tmp->prev != NULL)
		tmp = tmp->prev;
	tmp->prev = *b;
	*b = tmp;
	tmp->next->prev = NULL;
	(*b)->next = NULL;
	ft_putstr_fd("rrb\n", 0);
}

void	pb(stack **a, stack **b)
{
	stack *tmp;

	if ((*a)->prev != NULL)
	{
		tmp = *a;
		*a = (*a)->prev;
		(*a)->next = NULL;
		if (*b == NULL)
		{
			*b = tmp;
			(*b)->prev = NULL;
		}
		else
		{
			(*a)->next = NULL;
			tmp->prev = *b;
			*b = tmp;
		}
	}
	else
	{
		tmp = *a;
		*a = NULL;
		tmp->prev = *b;
		*b = tmp;
	}
	ft_putstr_fd("pb\n", 0);
}

void	pa(stack **a, stack **b)
{
	stack *tmp;

	if ((*b)->prev != NULL)
	{
		tmp = *b;
		*b = (*b)->prev;
		(*b)->next = NULL;
		if (*a == NULL)
		{
			*a = tmp;
			(*a)->prev = NULL;
		}
		else
		{
			(*b)->next = NULL;
			tmp->prev = *a;
			*a = tmp;
		}
	}
	else
	{
		tmp = *b;
		*b = NULL;
		tmp->prev = *a;
		*a = tmp;
	}
	ft_putstr_fd("pa\n", 0);
}