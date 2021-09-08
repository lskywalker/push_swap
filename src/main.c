/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 15:44:32 by lsmit         #+#    #+#                 */
/*   Updated: 2021/09/08 17:42:23 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>
#include <stdio.h>

stack	*ft_newlist(int data)
{
	stack	*head;

	head = malloc(sizeof(stack));
	if (!head)
		return (NULL);
	head->data = data;
	head->prev = NULL;
	head->next = NULL;
	return (head);
}

void	ft_pushstack(stack **list, int data)
{
	stack	*new;

	new = ft_newlist(data);
	if (*list != NULL)
		new->prev = *list;
	*list = new;
}

void	ft_displaylist(stack *head)
{
	stack *p;

	p = head;
	while(p != NULL)
	{
		printf("[%d]\n", p->data);
		p = p->prev;
	}
}

void	ft_add_front(stack **head, stack *new)
{
	if (!head)
		return ;
	new->prev = *head;
	*head = new;
}

void	ft_add_back(stack **head, stack *new)
{
	stack	*temp;

	if (!head)
		return ;
	temp = *head;
	if (temp)
	{
		while (temp->prev != NULL)
			temp = temp->prev;
		temp->prev = new;
		new->next = temp;
	}
	else
		ft_add_front(head, new);
}

stack	*ft_rotateup(stack **head)
{
	stack	*tmp;

	tmp = *head;
	(*head) = (*head)->prev;
	tmp->prev = NULL;
	ft_add_back(head, tmp);
	return (*head);
}

stack	*init_stack(char **input, int amount)
{
	stack	*list;
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

int		ft_findsmallest(stack *a)
{
	int		smallest;
	stack	*tmp;

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

int		ft_listsize(stack *lst)
{
	int		i;

	i = 1;
	if (lst == NULL)
		return (0);
	while (lst->prev != NULL)
	{
		lst = lst->prev;
		i++;
	}
	return (i);
}

void	ft_pushb(stack **b, int node)
{
	stack	*tmp;

	tmp = (*b)->prev;
	b->data = node;
	b->prev = tmp;
	// fix die pushb en pusha shit
}

void	ft_sortstack(stack **head_a, stack **head_b)
{
	int		smallest;
	int		i;

	i = 0;
	printf("\nA:");
	ft_displaylist(a);
	printf("\nB:");
	ft_displaylist(b);
	printf("\n");
	smallest = ft_findsmallest(*head_a);
	printf("-{%d}-\n", smallest);
	while (*head_a != NULL)
	{
		if ((*head_a)->data == smallest)
		{
			// push head_a to b
			ft_add_back(head_b, *head_a);
			break ;
		}
		else
			*head_a = ft_rotateup(head_a);
	}
}

int		main(int amount, char **input)
{
	data	stack;
	int		i;

	if (amount < 2)
	{
		ft_putchar_fd('\n', 0);
		return (0);
	}
	i = 0;
	stack.a = init_stack(input, amount);
	stack.b = NULL;
	while (i < ft_listsize(stack.a))
	{	
		ft_sortstack(&stack.a, &stack.b);
		i++;
	}
	printf("A: ");
	ft_displaylist(stack.a);
	printf("\nB:");
	ft_displaylist(stack.b);
	return (0);
}