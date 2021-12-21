/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 20:18:14 by lsmit         #+#    #+#                 */
/*   Updated: 2021/12/02 17:01:53 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	size_t			n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (n - start < len)
		len = n - start;
	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && start < n)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	return (substr);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_listsize(t_stack *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->prev;
		i++;
	}
	return (i);
}
