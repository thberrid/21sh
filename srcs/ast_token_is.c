/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_token_is.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 06:14:31 by thberrid          #+#    #+#             */
/*   Updated: 2020/02/28 14:50:08 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twentyonesh.h>
#include <ast.h>

int		token_is_redirection(t_token *token)
{
	if (token->name == LESS || token->name == GREAT
		|| token->name == DLESS || token->name == DGREAT)
		return (1);
	return (0);
}

int		token_is_controller(t_token *token)
{
	if (token->name == NEWLINE || token->name == PIPE)
		return (1);
	return (0);
}

int		token_is_operator(t_token *token)
{
	if (token_is_redirection(token) || token_is_controller(token))
		return (1);
	return (0);
}

int		is_portable_charset(char *token_value)
{
	int		index;

	index = 0;
	while (token_value[index])
	{
		if (!ft_isalnum(token_value[index]) && token_value[index] != '.'
			&& token_value[index] != '-' && token_value[index] != '_')
			return (0);
		index += 1;
	}
	return (1);
}

int		token_is_name(t_token *token)
{
	if (!token_is_operator(token) && is_portable_charset(token->value))
		return (1);
	return (0);
}
