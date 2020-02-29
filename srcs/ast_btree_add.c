/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_btree_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:36:06 by thberrid          #+#    #+#             */
/*   Updated: 2020/02/28 14:45:32 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twentyonesh.h>
#include <ast.h>

t_ast_rules	*get_ast_rules(void)
{
	static t_ast_rules	rules[] = {
		{&ast_cond_ast_unset, &btree_add_set},
		{&ast_cond_node_balanced, &btree_add_from_top},
		{&ast_cond_onlyone_floor, &btree_add_from_right},
		{&ast_cond_several_floors, &btree_add_from_left},
		{NULL, NULL}
	};

	return (rules);
}

int			btree_add(t_btree **ast, t_btree *new_node)
{
	int				index;
	t_ast_rules		*rules;

	rules = get_ast_rules();
	index = 0;
	while (rules[index].cond)
	{
		if (rules[index].cond(*ast))
			return (rules[index].add(ast, new_node));
		index += 1;
	}
	ft_printf("LOL %d\n", index);
	return (E_CATCH_ALL);
}
