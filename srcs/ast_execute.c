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

int		analyse_line(t_btree *btree, char **env, t_std_streams *streams)
{
	(void)btree;
	(void)env;
	(void)streams;
	return (0);
}

int		btree_execute(t_btree *btree, char **env, t_std_streams *streams)
{
	(void)env;
	ft_printf("exe: `%s` (%d)\n", btree->token.value, btree->token.name);
	if (token_is_operator(&btree->token))
		streams_set(streams, btree);
	else
		analyse_line(btree, env, streams);
	return (0);
}
