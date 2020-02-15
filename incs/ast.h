/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 03:58:55 by thberrid          #+#    #+#             */
/*   Updated: 2020/02/06 03:58:57 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include <libft.h>

# define CMD_SEPARATOR "><&|;"

enum			e_token_names
{
	tok_name,
	tok_operator,
	tok_comment,
	tok_empty
};

typedef struct	s_token
{
	char				*value;
	enum e_token_names	name;
}				t_token;

typedef struct	s_btree
{
	struct s_token		token;
	struct s_btree		*left;
	struct s_btree		*right;
}				t_btree;

t_btree			*btree_create(t_token *new);
int				btree_add(t_btree **btree, t_btree *new);
int				btree_dfs(t_btree *btree, char **env,
					int (*f)(t_btree *, char **));
int				btree_apply(t_btree *btree, char **env);
int				btree_free(t_btree *btree, char **env);

int				lexer_set_token(t_token *new, char *line, int cursor);

int				ast_fill(t_btree **ast, char *line);

// btree_bfs_lr_tb ? from top to bottom

#endif
