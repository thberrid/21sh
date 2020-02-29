/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_rules_cond.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:36:06 by thberrid          #+#    #+#             */
/*   Updated: 2020/02/28 14:45:32 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twentyonesh.h>
#include <ast.h>

int     ast_cond_ast_unset(t_btree *ast)
{
    if (!ast)
		return (1);
    return (0);
}

int     ast_cond_node_balanced(t_btree *ast)
{
    if ((!ast->left && !ast->right)
		|| (ast->left && ast->right))
        return (1);
    return (0);
}

int     ast_cond_onlyone_floor(t_btree *ast)
{
    if (!ast->left->left)
        return (1);
    return (0);
}

int     ast_cond_several_floors(t_btree *ast)
{
    if (ast->left->left)
        return (1);
    return (0);
}