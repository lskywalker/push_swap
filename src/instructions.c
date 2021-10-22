/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/17 14:10:22 by lsmit         #+#    #+#                 */
/*   Updated: 2021/10/12 18:19:07 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <stdio.h>

void	sasb(t_stack **s, int type)
{
	int	tmp;
	int	tmp2;

	tmp = (*s)->data;
	*s = (*s)->prev;
	tmp2 = (*s)->data;
	(*s)->data = tmp;
	*s = (*s)->next;
	(*s)->data = tmp2;
	if (type == 1)
		ft_putstr_fd("sa\n", 1);
	if (type == 2)
		ft_putstr_fd("sb\n", 1);
}

void	rarb(t_stack **s, int type)
{
	t_stack	*tmp;

	tmp = *s;
	*s = (*s)->prev;
	tmp->prev = NULL;
	(*s)->next = NULL;
	ft_add_back(s, tmp);
	if (type == 1)
		ft_putstr_fd("ra\n", 1);
	if (type == 2)
		ft_putstr_fd("rb\n", 1);
}

void	rrarrb(t_stack **s, int type)
{
	t_stack	*tmp;

	tmp = *s;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	tmp->prev = *s;
	(*s)->next = tmp;
	tmp->next->prev = NULL;
	tmp->next = NULL;
	*s = tmp;
	if (type == 1)
		ft_putstr_fd("rra\n", 1);
	if (type == 2)
		ft_putstr_fd("rrb\n", 1);
}

void	push2(t_stack **src, t_stack **dst, t_stack **tmp)
{
	*tmp = *src;
	*src = (*src)->prev;
	(*src)->next = NULL;
	if (*dst == NULL)
	{
		*dst = *tmp;
		(*dst)->prev = NULL;
	}
	else
	{
		(*dst)->next = *tmp;
		(*tmp)->prev = *dst;
		*dst = *tmp;
	}
}

void	push(t_stack **src, t_stack **dst, int type)
{
	t_stack	*tmp;

	if ((*src)->prev != NULL)
		push2(src, dst, &tmp);
	else
	{
		tmp = *src;
		*src = NULL;
		tmp->prev = *dst;
		*dst = tmp;
	}
	if (type == 1)
		ft_putstr_fd("pa\n", 1);
	if (type == 2)
		ft_putstr_fd("pb\n", 1);
}
