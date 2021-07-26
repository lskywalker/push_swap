/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmit <lsmit@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 16:00:09 by lsmit         #+#    #+#                 */
/*   Updated: 2021/07/26 20:31:30 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <libft.h>

typedef struct	swap {
	int 			data;
	struct swap		*next;
	struct swap 	*prev;
}swap;

#endif