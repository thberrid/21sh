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
	if (line[len] && ft_contains(line[len], CMD_SEPARATOR))
		return ((len += analyse_operator(line, len)));
	while (line[len] && !ft_contains(line[len], CMD_SEPARATOR))
		len += 1;
	return (len);
}

t_token		**get_controllers(){
	static t_token	*(controllers[3]) = {
		{"|", PIPE},
		{";", NEWLINE},
		{NULL, EMPTY_LINE}
	};
	return (controllers);
}

t_token		**get_redirections(){
	static t_token	*(redirections[5]) = {
		{">", GREAT},
		{">>", DGREAT},
		{"<", LESS},
		{"<<", DLESS},
		{NULL, EMPTY_LINE}
	};
	return (redirections);
}

int			str_is_operator(char *str, int len, t_token *token, t_token **(*f)())
{
	t_token	**operators;
	int		index;

	operators = f();
	index = 0;
	while (operators[index]->value)
	{
		if (ft_strnequ(str, operators[index]->value, len))
		{
			token->name = operators[index]->name;
			if (!(token->value = ft_strdup(operators[index]->value)))
				return (E_MALLOCFAIL);
			return (1);
		}
		index += 1;
	}
	return (0);
}

static int	associate_token(t_token *token, char *str, int len)
{
	int		retrn;
	int		cursor;

	cursor = ft_spaceslen(str);
	len -= cursor;
	retrn = str_is_operator(str + cursor, len, token, &get_redirections);
	if (retrn)
		return (retrn);
	retrn = str_is_operator(str + cursor, len, token, &get_controllers);
	if (retrn)
		return (retrn);
	token->name = WORD;
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
