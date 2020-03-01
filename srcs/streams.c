/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fildes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:34:27 by thberrid          #+#    #+#             */
/*   Updated: 2020/03/01 20:34:35 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twentyonesh.h>
#include <ast.h>

void	fildes_reset(t_fildes *fildes)
{
	ft_bzero(fildes, sizeof(t_fildes));
	fildes[1].id = 1;
	fildes[2].id = 2;
}

void	fildes_set(t_fildes *fildes, t_btree *btree)
{
	(void)btree;
	fildes_reset(fildes);
	if (btree->token.name == LESS || btree->token.name == DLESS
		|| btree->token.name == PIPE)
		fildes[0].state = FD_STATE_OPEN;
	if (btree->token.name == GREAT || btree->token.name == DGREAT
		|| btree->token.name == PIPE)
		fildes[1].state = FD_STATE_OPEN;
	// IF ERROR >> fildes[2].state = OPEN
	if (btree->token.name == DLESS)
		fildes[0].flags |= O_APPEND;
	if (btree->token.name == DGREAT)
		fildes[1].flags |= O_APPEND;
}