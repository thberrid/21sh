/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_rules_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:36:06 by thberrid          #+#    #+#             */
/*   Updated: 2020/02/28 14:45:32 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twentyonesh.h>
#include <ast.h>

int	btree_add_first(t_btree **ast, t_btree *new_node)
{
    *ast = new_node;
    return (E_SUCCESS);
}

int	btree_add_from_right(t_btree **ast, t_btree *new_node)
{
	int		retrn;

	retrn = E_SUCCESS;
	if (!token_is_operator(&(*ast)->token))
		retrn = E_CATCH_ALL;
	new_node->left = *ast;
	new_node->right = (*ast)->left;
	(*ast)->left = NULL;
	*ast = new_node;
	return (retrn);
}

int	btree_add_from_left(t_btree **ast, t_btree *new_node)
{
	int		retrn;

	retrn = E_SUCCESS;
	if (!token_is_operator(&(*ast)->token))
		retrn = E_CATCH_ALL;
	new_node->right = *ast;
	new_node->left = (*ast)->left;
	(*ast)->left = NULL;
	*ast = new_node;
	return (retrn);
}

int	btree_add_from_top(t_btree **ast, t_btree *new_node)
{
	int		retrn;

	retrn = E_SUCCESS;
	if (token_is_operator(&(*ast)->token))
		retrn = E_CATCH_ALL;
	new_node->left = *ast;
	*ast = new_node;
	return (retrn);
}