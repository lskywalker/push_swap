/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 19:32:12 by lsmit         #+#    #+#                 */
/*   Updated: 2021/12/06 16:50:49 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int			i;
	long long	res;
	long long	n;

	i = 0;
	n = 1;
	res = 0;
	if (str[i] == '-')
		n = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		ft_exit();
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > INT_MAX)
			ft_exit();
		if (res < INT_MIN)
			ft_exit();
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (str[i])
		ft_exit();
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

void	*ft_calloc(size_t count, size_t size)
{
	size_t	len;
	void	*ptr;

	len = count * size;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, len);
	return (ptr);
}
