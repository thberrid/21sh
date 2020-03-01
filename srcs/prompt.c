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
	int				retrn;
	char			*line;
	t_btree			*ast;
	t_fildes		fildes[3];

	line = NULL;
	ft_printf("%s", PROMPT);
	fildes_reset(&fildes);
	while ((retrn = get_next_line(0, &line)) > 0)
	{
		if (retrn <= 0)
			return (retrn);
		ast = NULL;
		retrn = ast_parser(&ast, line);
		if (!retrn)
			retrn = btree_dfs(ast, env, &fildes, &btree_execute);
		ft_strdel(&line);
		btree_dfs(ast, NULL, NULL, &btree_free);
		if (LEAKS)
			system("leaks 21sh");
		if (retrn)
			return (retrn);
		ft_printf("%s", PROMPT);
	}
	return (retrn);
}
