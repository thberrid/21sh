/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:36:06 by thberrid          #+#    #+#             */
/*   Updated: 2020/02/19 11:36:08 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twentyonesh.h>
#include <ast.h>

int		btree_add_operator(t_btree **ast, t_btree *new_node)
{
	t_token	this_tok;

	this_tok = new_node->token;
	if (token_is_redirection(&this_tok))
	{
		(*ast)->left = new_node;
	}
	else
	{
		new_node->left = *ast;
		*ast = new_node;
	}
	return (E_SUCCESS);
}

int		btree_add_word(t_btree **ast, t_btree *new_word)
{
	if (!(*ast)->left)
		(*ast)->left = new_word;
	else if (!(*ast)->right)
		(*ast)->right = new_word;
	else
		return (E_CATCH_ALL);
	return (E_SUCCESS);
}

int		btree_add(t_btree **ast, t_btree *new_node)
{
	t_token this_token;

	this_token = new_node->token;
	if (!*ast)
		*ast = new_node;
	else if (token_is_operator(&this_token))
		return (btree_add_operator(ast, new_node));
	btree_add_word(ast, new_node);
	return (E_SUCCESS);
}

int		ast_fill(t_btree **ast, char *line)
{
	int		cursor;
	t_token	new_token;
	t_btree *new_node;

	ft_bzero(&new_token, sizeof(t_token));
	cursor = 0;
	while ((cursor = lexer_set_token(&new_token, line, cursor)))
	{
		if (new_token.name != EMPTY_LINE)
		{
			if ((new_node = btree_create(&new_token)))
				btree_add(ast, new_node);
		}
		ft_bzero(&new_token, sizeof(t_token));
	}
	return (E_SUCCESS);
}