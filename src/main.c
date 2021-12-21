/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 15:44:32 by lsmit         #+#    #+#                 */
/*   Updated: 2021/12/06 16:50:35 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_stack	*ft_rotateup(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	(*head) = (*head)->prev;
	tmp->prev = NULL;
	ft_add_back(head, tmp);
	return (*head);
}

t_stack	*init_stack(char **input, int amount)
{
	t_stack	*list;
	char	**stack;
	int		i;

	list = NULL;
	while (amount > 1)
	{
		amount--;
		i = 0;
		stack = ft_split(input[amount], ' ');
		while (stack[i])
			i++;
		while (i > 0)
		{
			i--;
			ft_pushstack(&list, ft_atoi(stack[i]));
			free(stack[i]);
		}
		free(stack);
	}
	return (list);
}

t_stack	*totop(t_stack *a, int nb, int bs, int amount)
{
	int		i;

	i = findnb(a, nb, 0);
	if (i == 1)
		rarb(&a, 1);
	if (i == 2)
	{
		rarb(&a, 1);
		sasb(&a, 1);
	}
	if (i > 2)
	{
		rrarrb(&a, 1);
		if (i == 3 && bs != 1 && amount != 5)
			rrarrb(&a, 1);
	}
	return (a);
}

void	biggerstack(t_stack **a, t_stack **b, double amount)
{
	t_stack	*head;
	t_info	i;

	i.oldamount = amount;
	i.prev = ft_findsmallest(*a);
	if (amount > 101)
		i.chunck = (ft_findbiggest(*a) - i.prev) / 12;
	else
		i.chunck = (ft_findbiggest(*a) - i.prev) / 5;
	head = *a;
	i.nb = i.prev + i.chunck;
	while (amount > 0)
	{
		*a = head;
		i.i = stepsfromtop(*a, i.prev, i.nb);
		i.j = stepsfrombottom(*a, i.prev, i.nb);
		rotate(&head, &i);
		if (i.on == 0)
		{	
			push(&head, b, 2);
			amount--;
		}
	}
	pushback(a, b, *b, i.oldamount);
}

int	main(int amount, char **input)
{
	t_data	stack;

	if (amount < 2)
		ft_exit();
	stack.a = init_stack(input, amount);
	stack.b = NULL;
	if (precheck(stack.a) == 1)
		return (0);
	amount = ft_listsize(stack.a);
	if (amount < 6)
	{
		if (amount < 4)
			smallstack(&stack.a, ft_findsmallest(stack.a));
		else
			midsizestack(&stack.a, &stack.b, amount + 1);
	}
	else
		biggerstack(&stack.a, &stack.b, (double)amount);
	return (0);
}
