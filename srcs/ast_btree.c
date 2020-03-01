/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_btree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 08:03:10 by thberrid          #+#    #+#             */
/*   Updated: 2020/02/09 08:03:12 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twentyonesh.h>
#include <ast.h>

/*
** browses a binary tree, with deepth first search
** applying on each node a `int (*fn): return value`
*/

int		btree_dfs(t_btree *btree, char **env, t_std_streams *streams, int (*f)(t_btree *, char **, t_std_streams *))
{
	int		retrn;

	retrn = 0;
	if (!btree)
		return (0);
	if (btree->left)
		retrn = btree_dfs(btree->left, env, streams, f);
	if (retrn)
		return (retrn);
	if (btree->right)
		retrn = btree_dfs(btree->right, env, streams, f);
	if (retrn)
		return (retrn);
	retrn = f(btree, env, streams);
	return (retrn);
}

int		btree_free(t_btree *btree, char **env, t_std_streams *streams)
{
	(void)env;
	(void)streams;
	if (btree->token.name != EMPTY_LINE)
		ft_strdel(&btree->token.value);
	ft_memdel((void **)&btree);
	return (E_SUCCESS);
}

t_btree	*btree_create(t_token *new_token)
{
	t_btree		*new_node;

	if (!(new_node = ft_memalloc(sizeof(t_btree))))
		return (NULL);
	ft_memcpy(&new_node->token, new_token, sizeof(t_token));
	return (new_node);
}
