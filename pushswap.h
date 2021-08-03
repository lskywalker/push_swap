/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 16:00:09 by lsmit         #+#    #+#                 */
/*   Updated: 2021/08/03 12:56:37 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <libft.h>

typedef struct	stack {
	int 			data;
	struct stack		*prev;
	struct stack		*next;
}stack;

typedef struct data {
	stack	*a;
	stack	*b;
}data;


#endif