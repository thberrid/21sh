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

int		btree_execute(t_btree *btree, char **env)
{
	(void)env;
	ft_printf("exe: `%s` (%d)\n", btree->token.value, btree->token.name);
/*
	if (token_is_operator(&btree->token))
		set_fd(btree, fildes);
	else
		analyse_line(btree, fildes, env, loc_var);
*/
	return (0);
}
