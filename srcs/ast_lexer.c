/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_lexer.c                                        :+:      :+:    :+:   */
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
	if (line[cursor + 1] && ft_contains(line[cursor], "><")
		&& line[cursor] == line[cursor + 1])
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

t_token		*get_controllers(void)
{
	static t_token	controllers[] = {
		{"|", PIPE},
		{";", NEWLINE},
		{NULL, EMPTY_LINE}
	};

	return (controllers);
}

t_token		*get_redirections(void)
{
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
	while (operators[index].name)
	{
		if (ft_strnequ(str, operators[index].value, len))
			return (&operators[index]);
		index += 1;
	}
	return (NULL);
}

int			strn_is_empty(char *str, int len)
{
	int		index;

	index = 0;
	while (str[index] && index < len)
	{
		if (!ft_isspace(str[index]))
			return (0);
		index += 1;
	}
	return (1);
}

static enum e_token_names	token_get_name(char *str, int len)
{
	int		cursor;
	t_token	*reference;

	cursor = ft_spaceslen(str);
	if (strn_is_empty(str + cursor, len - cursor))
		return (EMPTY_LINE);
	reference = str_is_operator(str + cursor, len - cursor, &get_redirections);
	if (!reference)
		reference = str_is_operator(str + cursor, len - cursor, &get_controllers);
	if (!reference)
		return (WORD);
	return (reference->name);
}

int			lexer_set_token(t_token *token, char *line, size_t cursor)
{
	int		fragment_len;
	int		spaceslen;

	if (cursor >= ft_strlen(line))
		return (0);
	fragment_len = get_next_str_fragmnt(line + cursor);
	fragment_len -= ft_spaceslenr(line + cursor, fragment_len);
	if ((token->name = token_get_name(line + cursor, fragment_len)) != EMPTY_LINE)
	{
		spaceslen = ft_spaceslen(line + cursor);
		if (!(token->value = ft_strndup(line + cursor + spaceslen, fragment_len - spaceslen)))
			token->name = EMPTY_LINE;
	}
	return (cursor + fragment_len);
}
