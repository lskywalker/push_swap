/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 19:25:17 by lsmit         #+#    #+#                 */
/*   Updated: 2021/10/12 18:19:07 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_findsmallest(t_stack *a)
{
	int		smallest;
	t_stack	*tmp;

	tmp = a;
	smallest = a->data;
	while (a != NULL)
	{
		if (a->prev != NULL)
		{
			tmp = a->prev;
			if (tmp->data < smallest)
				smallest = tmp->data;
		}
		a = a->prev;
	}
	return (smallest);
}

int	ft_findbiggest(t_stack *a)
{
	int		biggest;
	t_stack	*tmp;

	tmp = a;
	biggest = a->data;
	while (a != NULL)
	{
		if (a->prev != NULL)
		{
			tmp = a->prev;
			if (tmp->data > biggest)
				biggest = tmp->data;
		}
		a = a->prev;
	}
	return (biggest);
}

int	stepsfromtop(t_stack *a, int prev, int nb)
{
	int		i;

	i = 0;
	if (a->prev == NULL)
		return (0);
	while (a->prev != NULL)
	{
		if (a->data >= prev && a->data < nb)
			break ;
		a = a->prev;
		i++;
	}
	if (a->prev == NULL)
	{
		if (a->data >= prev && a->data < nb)
			return (1);
		return (-1);
	}
	return (i);
}

int	stepsfrombottom(t_stack *a, int prev, int nb)
{
	int		i;

	i = 1;
	while (a->prev != NULL)
		a = a->prev;
	while (a->next != NULL)
	{
		if (a->data >= prev && a->data < nb)
			break ;
		a = a->next;
		i++;
	}
	if (a->next == NULL)
	{
		if (a->data >= prev && a->data < nb)
			return (i);
		return (-1);
	}
	return (i);
}

int	findnb(t_stack *a, int nb, int i)
{
	while (a->prev != NULL)
	{	
		a = a->prev;
		i++;
		if (a->data == nb)
			break ;
	}
	return (i);
}
