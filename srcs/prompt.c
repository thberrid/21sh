/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 07:32:59 by thberrid          #+#    #+#             */
/*   Updated: 2020/02/09 07:33:04 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twentyonesh.h>
#include <ast.h>

int		prompt_loop(char **env)
{
	int			retrn;
	char		*line;
	t_bintree	ast;


	line = NULL;
	ft_printf("%s\n", PROMPT);
	retrn = get_next_line(0, &line);
	if (!retrn)
		return (0);
	ft_bzero(&ast, sizeof(t_bintree));
	retrn = parser(&ast, line);
	if (retrn)
		return (0);
	retrn = btree_dfs(&ast, env, &btree_apply);
	if (retrn)
		return (0);
	btree_dfs(&ast, env, &btree_free);
	return (prompt_loop(env));
}