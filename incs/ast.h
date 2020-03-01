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

# define LINE_SEPARATOR	"><&|;"

# define FD_IN			0
# define FD_OUT			1
# define FD_ERR			2

enum			e_errors
{
	E_MALLOCFAIL = -1,
	E_SUCCESS,
	E_CATCH_ALL,
	E_BUILTIN_MISUSE
};

enum			e_token_names
{
	EMPTY_LINE,	//				0
	WORD,		//	default		1
	NEWLINE, 	// 	;			2
	LESS,		// 	<			3
	GREAT,		// 	>			4
	DLESS,		// 	<<			5
	DGREAT,		// 	>>			6
	PIPE		// 	pipe lol	7
	//	missing : 
	//		- agregats lol
};

typedef struct	s_token
{
	char				*value;
	enum e_token_names	name;
}				t_token;

/*
typedef struct 	s_localvar
{
	t_dlist * (import tdlist lol) ?
}				t_localvar;
*/

enum			e_fd_states
{
	FD_STATE_CLOSE,
	FD_STATE_OPEN,
	FD_STATE_SET
};

typedef struct	s_fildes
{
	enum e_fd_states	state;
	char				path[256];
	int					id;
	int					flags;
}				t_fildes;

/*
typedef struct s_std_streams
{
	t_fildes	fds[3];
	t_fildes	in;
	t_fildes	out;
	t_fildes	error;
}				t_std_streams;
*/

typedef struct	s_btree
{
	t_token	token;
	struct s_btree	*left;
	struct s_btree	*right;
}				t_btree;

typedef struct	s_ast_rules
{
	int		(*cond)(t_btree *);
	int		(*add)(t_btree **, t_btree *);
}				t_ast_rules;

t_btree			*btree_create(t_token *new);
int				btree_dfs(t_btree *btree, char **env, f_fildes *fildes,
					int (*f)(t_btree *, char **, f_fildes *));
int				btree_free(t_btree *btree, char **env, f_fildes *fildes);

int				btree_add(t_btree **btree, t_btree *new);

int				btree_add_set(t_btree **ast, t_btree *new_node);
int				btree_add_from_right(t_btree **ast, t_btree *new_node);
int				btree_add_from_left(t_btree **ast, t_btree *new_node);
int				btree_add_from_top(t_btree **ast, t_btree *new_node);

int     		ast_cond_ast_unset(t_btree *ast);
int     		ast_cond_node_balanced(t_btree *ast);
int     		ast_cond_onlyone_floor(t_btree *ast);
int     		ast_cond_several_floors(t_btree *ast);

int				lexer_set_token(t_token *new, char *line, size_t cursor);

int				btree_execute(t_btree *btree, char **env, f_fildes *fildes);

int				ast_parser(t_btree **ast, char *line);

int				token_is_name(t_token *token);
int				token_is_operator(t_token *token);
int				token_is_controller(t_token *token);
int				token_is_redirection(t_token *token);
int				is_portable_charset(char *token_value);

void			streams_reset(f_fildes *fildes);
void			streams_set(f_fildes *fildes, t_btree *btree);

#endif
