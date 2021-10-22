/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 19:32:12 by lsmit         #+#    #+#                 */
/*   Updated: 2021/10/14 15:10:39 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_atoi(char *str)
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

int	precheck(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (a->prev != NULL)
	{
		if (a->data < a->prev->data)
			j++;
		i++;
		a = a->prev;
	}
	if (i == j)
		return (1);
	return (0);
}

int	ft_listsize(t_stack *lst)
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
