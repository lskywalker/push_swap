/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 15:44:32 by lsmit         #+#    #+#                 */
/*   Updated: 2021/07/26 20:31:45 by lsmit         ########   odam.nl         */
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
	while(p)
	{
		printf("%d\n", p->data);
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

void	ft_checkinput(char **input)
{
	int		i;
	int		j;
	swap	*list;
	swap	*tmp;
	int		data;

	i = 0;
	list = NULL;
	tmp = NULL;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (!ft_isdigit(input[i][j]))
			{
				ft_putstr_fd("Error\n", 0);
				return ;
			}
			j++;
		}
		data = ft_atoi(input[i]);
		tmp = ft_newlist(data);
		ft_adddata(&list, tmp);
		free(tmp);
		i++;
	}
}

int		main(int amount, char **input)
{
	if (amount < 2)
	{
		ft_putchar_fd('\n', 0);
		return (0);
	}
	ft_checkinput(input);
	return (0);
}