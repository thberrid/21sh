/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 08:23:50 by thberrid          #+#    #+#             */
/*   Updated: 2020/02/09 08:23:54 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twentyonesh.h>
#include <ast.h>

int		parser(t_btree **ast, char *line)
{
	int		cursor;
	t_token	new_token;
	t_btree *new_node;

	ft_bzero(&new_token, sizeof(t_token));
	cursor = 0;
	while ((cursor = lexer_set_token(&new_token, line, cursor)))
	{
		if (new_token.name != tok_comment)
		{
			if ((new_node = btree_create(&new_token)))
				return (-1);
			btree_add(ast, new_node);
		}
		ft_bzero(&new_token, sizeof(t_token));
	}
	return (0);
}