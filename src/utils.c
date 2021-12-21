/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 19:01:12 by lsmit         #+#    #+#                 */
/*   Updated: 2021/11/23 19:45:42 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_stack	*ft_newlist(int data)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head->data = data;
	head->prev = NULL;
	head->next = NULL;
	return (head);
}

void	ft_pushstack(t_stack **list, int data)
{
	t_stack	*new;

	new = ft_newlist(data);
	if (*list != NULL)
	{
		new->prev = *list;
		(*list)->next = new;
	}
	*list = new;
}

void	ft_add_front(t_stack **head, t_stack *new)
{
	if (!head)
		return ;
	new->prev = *head;
	*head = new;
	(*head)->next = NULL;
}

void	ft_add_back(t_stack **head, t_stack *new)
{
	t_stack	*temp;

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

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}
