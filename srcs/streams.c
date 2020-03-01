/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   streams.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:34:27 by thberrid          #+#    #+#             */
/*   Updated: 2020/03/01 20:34:35 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twentyonesh.h>
#include <ast.h>

void	streams_reset(t_std_streams *streams)
{
	ft_bzero(streams, sizeof(t_std_streams));
	streams->in.id = 1;
	streams->error.id = 1;
}

void	streams_set(t_std_streams *streams, t_btree *btree)
{
	(void)btree;
	(void)streams;
}