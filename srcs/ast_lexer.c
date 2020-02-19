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

static int	analyse_operator(char *line, int cursor)
{
	int		len;

	len = 1;
	if (line[cursor + 1] && ft_contains(line[cursor], "><") && line[cursor] == line[cursor + 1])
		len += 1;
	return (len);
}

static int	get_next_str_fragmnt(char *line)
{
	int		len;

	len = ft_spaceslen(line);
	if (line[len] && ft_contains(line[len], LINE_SEPARATOR))
		return ((len += analyse_operator(line, len)));
	while (line[len] && !ft_contains(line[len], LINE_SEPARATOR))
		len += 1;
	return (len);
}

t_token		*get_controllers(){
	static t_token	controllers[] = {
		{"|", PIPE},
		{";", NEWLINE},
		{NULL, EMPTY_LINE}
	};
	return (controllers);
}

t_token		*get_redirections(){
	static t_token	redirections[] = {
		{">", GREAT},
		{">>", DGREAT},
		{"<", LESS},
		{"<<", DLESS},
		{NULL, EMPTY_LINE}
	};
	return (redirections);
}

t_token		*str_is_operator(char *str, int len, t_token *(*get_operators)())
{
	int		index;
	t_token	*operators;

	operators = get_operators();
	index = 0;
	while (operators[index].value)
	{
		if (ft_strnequ(str, operators[index].value, len))
			return (&operators[index]);
		index += 1;
	}
	return (NULL);
}

static enum e_token_names	token_find_name(char *str, int len)
{
	int		cursor;
	t_token	*reference;

	cursor = ft_spaceslen(str);
	len -= cursor;
	reference = str_is_operator(str + cursor, len, &get_redirections);
	if (!reference)
		reference = str_is_operator(str + cursor, len, &get_controllers);
	if (!reference)
		reference->name = WORD;
	return (reference->name);
}

int			lexer_set_token(t_token *token, char *line, int cursor)
{
	int		fragment_len;

	if (cursor >= (int)ft_strlen(line))
		return (0);
	fragment_len = get_next_str_fragmnt(line + cursor);
	if ((token->name = token_find_name(line + cursor, fragment_len)) != EMPTY_LINE)
		if (!(token->value = ft_strndup(line + cursor, fragment_len)))
			token->name = EMPTY_LINE;
	return (cursor + fragment_len);
}
