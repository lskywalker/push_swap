/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bigstackutils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 14:52:59 by lsmit         #+#    #+#                 */
/*   Updated: 2021/10/14 15:35:25 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_stack	*pushback2(t_stack *head, double amount, double i)
{
	if (i < (amount / 2))
	{
		while (i > 0)
		{
			rarb(&head, 2);
			i--;
		}
	}
	else
	{
		while (i < amount)
		{
			rrarrb(&head, 2);
			i++;
		}
	}
	return (head);
}

void	pushback(t_stack **a, t_stack **b, t_stack **head, double amount)
{
	int		i;
	int		biggest;

	while (amount > 0)
	{
		*b = *head;
		i = 0;
		biggest = ft_findbiggest(*b);
		while ((*b)->prev != NULL)
		{
			if ((*b)->data == biggest)
				break ;
			*b = (*b)->prev;
			i++;
		}
		if (i < (amount / 2))
		{
			while (i > 0)
			{
				rarb(head, 2);
				i--;
			}
		}
		else
		{
			while (i < amount)
			{
				rrarrb(head, 2);
				i++;
			}
		}
		dprintf(2, "[%f]\n", amount);
			// head = pushback2(head, amount, i);
		push(head, a, 1);
		amount--;
	}
}

void	rotate(t_stack **head, t_info *i)
{
	if (i->i == -1 || i->j == -1)
	{
		i->prev = i->nb;
		i->nb = i->nb + i->chunck;
		i->on = 1;
	}
	else if (i->i <= i->j)
	{
		i->on = 0;
		while (i->i > 0)
		{
			rarb(head, 1);
			i->i--;
		}
	}
	else
	{
		i->on = 0;
		while (i->j > 0)
		{
			rrarrb(head, 1);
			i->j--;
		}
	}
}
