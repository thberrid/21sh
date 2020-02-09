/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 08:03:10 by thberrid          #+#    #+#             */
/*   Updated: 2020/02/09 08:03:12 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twentyonesh.h>
#include <ast.h>

int		btree_dfs(t_btree *btree, char **env, int (*f)(t_btree *, char **))
{
	int		retrn;

	retrn = 0;
	if (btree->left)
		retrn = btree_dfs(btree->left, env, f);
	if (retrn)
		return (retrn);
	if (btree->right)
		retrn = btree_dfs(btree->right, env, f);
	if (retrn)
		return (retrn);
	retrn = f(btree, env);
	return (retrn);
}

int		btree_apply(t_btree *btree, char **env)
{
	(void)env;
	ft_printf("applying: %s (%d)\n", btree->token.value, btree->token.name);
	return (0);
}

int		btree_free(t_btree *btree, char **env)
{
	(void)env;
	ft_strdel(&btree->token.value);
	ft_memdel((void **)&btree);
	return (0);
}

t_btree	*btree_create(t_token *new_token)
{
	t_btree		*new_node;

	if (!(new_node = ft_memalloc(sizeof(t_btree))))
		return (NULL);
	ft_memcpy(&new_node->token, new_token, sizeof(t_token));
	return (new_node);
}

int		btree_add(t_btree **ast, t_btree *new_node)
{
	t_token this_tok;

	this_tok = new_node->token;
	if (!*ast)
		*ast = new_node;
	else if (this_tok.name == tok_operator)
	{
		new_node->left = *ast;
		*ast = new_node;
	}
	else
	{
		if (!(*ast)->left)
			(*ast)->left = new_node;
		else if (!(*ast)->right)
			(*ast)->right = new_node;
		else
			return (-1);
				
	}
	return (0);
}
