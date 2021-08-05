/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 15:44:32 by lsmit         #+#    #+#                 */
/*   Updated: 2021/08/05 18:38:45 by lsmit         ########   odam.nl         */
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

void	ft_add_front(stack **alst, stack *new)
{
	if (!alst)
		return ;
	new->next = *alst;
	*alst = new;
}

void	ft_add_back(stack **head, stack *new)
{
	stack	**temp;

	if (!head)
		return ;
	temp = head;
	if (*temp)
	{
		while ((*temp)->prev != NULL)
			*temp = (*temp)->prev;
		(*temp)->prev = new;
	}
	else
		new->prev = *head;
		*head = new;
}

stack	*ft_rotateup(stack *head)
{
	stack	*tmp;

	ft_displaylist(head);
	tmp = head;
	head = head->prev;
	tmp->prev = NULL;
	// printf("old head = %d\nnew head = %d\n", tmp->data, head->data);
	printf("\n");
	ft_displaylist(head);
	ft_add_back(&head, tmp);
	printf("\n");
	ft_displaylist(tmp);
	return (head);
}

// stack	*ft_sort(stack *head)
// {
// 	stack	*tmp;
// 	stack	*list;

// 	while (1)
// 	{
// 		list = head;
// 		tmp = NULL;
// 		while (list->next != NULL)
// 		{
// 			tmp = list->next;
// 			if (list->data > tmp->data)
// 				list = ft_switch(list);
// 			list = list->next;
// 		}
// 		if (ft_sorted(list) == 1)
// 			break ;
// 	}
// 	return (head);
// }

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

// void	throughbottom(stack *a, stack *b)
// {
// 	while (a->prev != NULL)
// 		a = a->prev;
// 	Switch bottom with top
// 	a->data = head;?
// }

// void	throughtop(stack **a, stack **b)
// {
// 	stack *tmp;

// 	while ((*a)->next != NULL)
// 	{
// 		(*a) = ft_switch(*a);
// 		(*a) = (*a)->next;
// 	}
// 	if ((*b) == NULL)
// 		tmp = ft_newlist((*a)->data);
// 	else
// 	{
// 		tmp = (*b);
// 		ft_pushstack(&tmp, (*a)->data);
// 		(*b) = tmp;
// 	}
// 	(*a) = NULL;
// }

void	ft_sortstack(stack *head_a, stack *head_b)
{
	int		smallest;
	int		i;
	stack	*a;
	stack	*b;

	a = head_a;
	b = head_b;
	smallest = ft_findsmallest(a);
	i = 0;
	while (a != NULL)
	{
		if (a->data == smallest)
		{
			// if (i > (ft_listsize(a) / 2))
			// 	throughbottom(a, b);
			// else
				a = ft_rotateup(head_a);
			break ;
		}
		a = a->prev;
		i++;
	}
	while (a->next != NULL)
		a = a->next;
	head_a = a;
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
	// ft_displaylist(stack.a);
	ft_sortstack(stack.a, stack.b);
	// printf("\n");
	// ft_displaylist(stack.a);
	return (0);
}