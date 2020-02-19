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

# define CMD_SEPARATOR 	"><&|;"

enum			e_errors {
	E_MALLOCFAIL = -1,
	E_SUCCESS,
	E_CATCH_ALL,
	E_BUILTIN_MISUSE
};

enum			e_token_names
{
	EMPTY_LINE,
	WORD,		// default
	NEWLINE, 	// ;
	LESS,		// <
	GREAT,		// >
	DLESS,		// <<
	DGREAT,		// >>
	PIPE		// pipe lol
	//	missing : 
	//		- agregats lol
};

typedef struct	s_token
{
	char				*value;
	enum e_token_names	name;
}				t_token;

typedef struct	s_btree
{
	t_token	token;
	t_token	*left;
	t_token	*right;
}				t_btree;

t_btree			*btree_create(t_token *new);
int				btree_dfs(t_btree *btree, char **env,
					int (*f)(t_btree *, char **));
int				btree_free(t_btree *btree, char **env);

int				btree_add_operator(t_btree **ast, t_btree *new_node);
int				btree_add_word(t_btree **ast, t_btree *new_word);
int				btree_add(t_btree **btree, t_btree *new);

int				lexer_set_token(t_token *new, char *line, int cursor);

int				btree_execute(t_btree *btree, char **env);

int				ast_fill(t_btree **ast, char *line);

int				token_is_name(t_token *token);
int				token_is_operator(t_token *token);
int				token_is_controller(t_token *token);
int				token_is_redirection(t_token *token);
int				is_portable_charset(char *token_value);

#endif
