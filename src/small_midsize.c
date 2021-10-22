/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_midsize.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 19:23:39 by lsmit         #+#    #+#                 */
/*   Updated: 2021/10/12 18:19:07 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	one_not_top2(t_stack **a, t_stack **head, int tmp)
{
	if ((*a)->data > tmp)
		rrarrb(head, 1);
	else
	{
		sasb(head, 1);
		rrarrb(head, 1);
	}
}

void	one_not_top(t_stack **a, int smallest)
{
	int		tmp;
	t_stack	*head;

	head = *a;
	tmp = (*a)->data;
	*a = (*a)->prev;
	if ((*a)->prev == NULL)
		sasb(&head, 1);
	else if ((*a)->data == smallest)
	{
		*a = (*a)->prev;
		if ((*a)->data > tmp)
			sasb(&head, 1);
		else
			rarb(&head, 1);
	}
	else
		one_not_top2(a, &head, tmp);
}

void	smallstack(t_stack **a, int smallest)
{
	int		tmp;
	t_stack	*head;

	head = *a;
	if ((*a)->data == smallest)
	{
		*a = (*a)->prev;
		tmp = (*a)->data;
		if ((*a)->prev != NULL)
		{
			*a = (*a)->prev;
			if (tmp > (*a)->data)
			{
				sasb(&head, 1);
				rarb(&head, 1);
			}
			else
				return ;
		}
		else
			return ;
	}
	else
		one_not_top(a, smallest);
}

void	midsizestack(t_stack **a, t_stack **b, int amount)
{
	t_stack	*head;

	head = *a;
	if ((*a)->data != ft_findsmallest(*a))
		*a = totop(*a, ft_findsmallest(*a), 0, amount);
	push(a, b, 2);
	if (amount == 6 && (*a)->data != ft_findbiggest(*a))
		*a = totop(*a, ft_findbiggest(*a), 1, amount);
	if (amount == 6)
		push(a, b, 2);
	smallstack(a, ft_findsmallest(*a));
	push(b, a, 1);
	if (amount == 6)
	{
		rarb(a, 1);
		push(b, a, 1);
	}
}
