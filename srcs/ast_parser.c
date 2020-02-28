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

static int	ast_parser_error(char *last_token_value)
{
	ft_printf("%s: syntax error near unexpected token '%s'\n",
		SHELL_NAME, last_token_value);
	return (E_CATCH_ALL);
}

int			ast_parser(t_btree **ast, char *line)
{
	size_t	cursor;
	t_token	new_token;
	t_btree *new_node;

	ft_bzero(&new_token, sizeof(t_token));
	cursor = 0;
	while ((cursor = lexer_set_token(&new_token, line, cursor)))
	{
		if (new_token.name != EMPTY_LINE)
		{
			if ((new_node = btree_create(&new_token)))
				if (btree_add(ast, new_node))
					return (ast_parser_error((*ast)->token.value));
		}
		ft_bzero(&new_token, sizeof(t_token));
	}
	if (token_is_operator(&(*ast)->token) && !(*ast)->left)
		return (ast_parser_error((*ast)->token.value));
	return (E_SUCCESS);
}
