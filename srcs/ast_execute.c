/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:42:39 by thberrid          #+#    #+#             */
/*   Updated: 2020/02/19 11:42:41 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twentyonesh.h>
#include <ast.h>

int		analyse_line(t_btree *btree, char **env, t_fildes *fildes)
{
	(void)btree;
	(void)env;
	(void)fildes;
	return (0);
}

int		btree_execute(t_btree *btree, char **env, t_fildes *fildes)
{
	(void)env;
	ft_printf("exe: `%s` (%d)\n", btree->token.value, btree->token.name);
	if (token_is_operator(&btree->token))
		fildes_state_set(fildes, btree);
	else if (fildes_are_open(fildes, (int *){1, 2, -1}))
		fildes_set(fildes, btree);
	else
	{
		fildes_set(fildes, btree);
		analyse_line(btree, env, fildes);
		// if ok, fork-dup-pipe-blablabla launch process
	}
	return (0);
}
