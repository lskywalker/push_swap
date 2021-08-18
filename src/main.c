/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 15:44:32 by lsmit         #+#    #+#                 */
/*   Updated: 2021/08/18 18:08:55 by lsmit         ########   odam.nl         */
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

stack	*ft_checkinput(char **input)
{
	int		i;
	int		j;
	stack	*list;
	stack	*tmp;
	stack	*p;
	int		data;

	i = 1;
	list = NULL;
	tmp = NULL;
	p = NULL;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (!ft_isdigit(input[i][j]))
			{
				ft_putstr_fd("Error\n", 0);
				return (0);
			}
			j++;
		}
		data = ft_atoi(input[i]);
		tmp = ft_newlist(data);
		if (list == NULL)
			list = tmp;
		else
		{
			p = list;
			while (p->next != NULL)
				p = p->next;
			p->next = tmp;
		}
		i++;
	}
	ft_displaylist(list);
	return (list);
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
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_sortstack(stack **head_a, stack **head_b)
{
	int		smallest;
	int		i;
	stack	*a;
	stack	*b;

	a = *head_a;
	b = *head_b;
	i = 0;
	smallest = ft_findsmallest(a);
	while (a->prev != NULL)
	{
		if (a->data == smallest)
		{
			if ((*head_a)->data == smallest)
			{
				*head_a = (*head_a)->prev;
				ft_add_back(head_b, a);
			}
			a = ft_rotateup(head_a);
		}
		else
			a = a->prev;
	}
}

int		main(int amount, char **input)
{
	data	stack;

	if (amount < 2)
	{
		ft_putchar_fd('\n', 0);
		return (0);
	}
	stack.a = init_stack(input, amount);
	stack.b = NULL;

	// head = ft_checkinput(input);
	// head = ft_sort(head);
	ft_sortstack(&stack.a, &stack.b);
	printf("A: ");
	ft_displaylist(stack.a);
	printf("\nB:");
	ft_displaylist(stack.b);
	return (0);
}