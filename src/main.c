/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 15:44:32 by lsmit         #+#    #+#                 */
/*   Updated: 2021/07/28 17:44:57 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>
#include <stdio.h>

swap	*ft_newlist(int data)
{
	swap	*head;

	head = malloc(sizeof(swap));
	if (!head)
		return (NULL);
	head->data = data;
	head->next = NULL;
	return (head);
}

void	ft_displaylist(swap *head)
{
	swap *p;

	p = head;
	while(p != NULL)
	{
		printf("[%d]\n", p->data);
		p = p->next;
	}
}

void	ft_add_front(swap **alst, swap *new)
{
	if (!alst)
		return ;
	new->next = *alst;
	*alst = new;
}

void	ft_adddata(swap **p, swap *new)
{
	swap	**temp;

	if (!p)
		return ;
	temp = p;
	if (*temp)
	{
		while ((*temp)->next != NULL)
			*temp = (*temp)->next;
		(*temp)->next = new;
	}
	else
		ft_add_front(p, new);
}

swap	*ft_sort(swap *head)
{
	int i;
	swap	*tmp;

	i = 0;
	while (head->next != NULL)
	{
		tmp = head->next;
		if (head->data > tmp->data)
			ft_switch(head, tmp);
		else
			head = head->next;
	}
}

swap	*ft_checkinput(char **input)
{
	int		i;
	int		j;
	swap	*list;
	swap	*tmp;
	swap	*p;
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

int		main(int amount, char **input)
{
	swap *head;

	head = NULL;
	if (amount < 2)
	{
		ft_putchar_fd('\n', 0);
		return (0);
	}
	head = ft_checkinput(input);
	head = ft_sort(head);
	return (0);
}