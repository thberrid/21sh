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

enum			e_token_names
{
	tok_identifier,
	tok_separator,
	tok_literal,
	tok_comment
};

typedef struct	s_token
{
	char				*value;
	enum e_token_names	name;
}				t_token;

typedef struct	s_bintree
{
	struct s_token		token;
	struct s_bintree	*left;
	struct s_bintree	*right;
}				t_bintree;

#endif
