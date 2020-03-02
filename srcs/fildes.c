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

int		fildes_are_open(t_fildes *fildes, int *fd_id)
{
	int		index;

	index = 0;
	while (fd_id[index] != -1)
	{
		if (fildes[fd_id[index]].state == FD_STATE_OPEN)
			return (1);
		index += 1;
	}
	return (0);
}

void	fildes_set(t_fildes *fildes, t_btree *btree)
{
	int		index;

	index = 0;
	while (index < 3)
	{
		if (fildes[index].state == FD_STATE_OPEN)
		{
			fildes[index].state = FD_STATE_SET;
			ft_strcpy(fildes[index].path, btree->token.value);
			return ;
		}
		index += 1;
	}
}

void	fildes_reset(t_fildes *fildes)
{
	int		index;

	index = 0;
	while (index < 3)
	{
		ft_bzero(&fildes[index], sizeof(t_fildes));
		index += 1;
	}
	fildes[1].id = 1;
	fildes[2].id = 2;
}

void	fildes_state_set(t_fildes *fildes, t_btree *btree)
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