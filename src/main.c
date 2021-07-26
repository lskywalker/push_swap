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

#include "../pushswap.h"
#include <stdio.h>

int		ft_atoi(const char *str)
{
	int			i;
	long long	res;
	long long	n;

	i = 0;
	n = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		n = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res * 10 + (str[i] - '0')) < res)
			return (((-1 * n) - 1) / 2);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return ((int)res * n);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

///////////////////////////////////////////////////////////////////////

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