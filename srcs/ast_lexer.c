/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 08:24:00 by thberrid          #+#    #+#             */
/*   Updated: 2020/02/09 08:24:02 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twentyonesh.h>
#include <ast.h>

static int	ft_spaceslen(char *str)
{
	int		len;

	len = 0;
	while (str[len] && ft_isspace(str[len]))
		len += 1;
	return (len);
}

char	*ft_strndup(const char *src, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!(dest = ft_strnew(len)))
		return (NULL);
	while (src[i] != '\0' && i < len)
	{
		dest[i] = src[i];
		i += 1;
	}
	return (dest);
}

static int	get_next_str_fragmnt(char *line)
{
	int		len;

	len = ft_spaceslen(line);
	while (line[len] && !ft_isspace(line[len]))
		len += 1;
	return (len);
}

char		**get_operators(){
	static char	*(operators[8]) = {
		">",
		">>",
		"<",
		"<<",
		"|",
		"&",
		";",
		NULL
	};
	return (operators);
}

static int	associate_token(t_token *token, char *str, int len)
{
	int		index;
	int		cursor;
	char	**operators;

	cursor = ft_spaceslen(str);
	len -= cursor;
	operators = get_operators();
	index = 0;
	while (operators[index])
	{
		if (ft_strnequ(str + cursor, operators[index], len))
		{
			token->name = tok_operator;
			if (!(token->value = ft_strdup(operators[index])))
				return (-1);
			return (0);
		}
		index += 1;
	}
	token->name = tok_name;
	if (!(token->value = ft_strndup(str + cursor, len)))
		return (-1);
	return (0);
}

int			lexer_set_token(t_token *token, char *line, int cursor)
{
	int		fragment_len;

	if (cursor >= (int)ft_strlen(line))
		return (0);
	fragment_len = get_next_str_fragmnt(line + cursor);
	if (associate_token(token, line + cursor, fragment_len) < 0)
		return (-1);
	return (cursor + fragment_len);
}
