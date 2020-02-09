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

static int	get_next_str_fragmnt(char *line)
{
	int		len;

	len = ft_splaceslen(line);
	while (*(line + len) && !ft_isspace(line + len))
		len += 1;
	return (len);
}

static int	associate_token(t_token *token, char *str, int len)
{
	int		index;

	index = ft_splaceslen(str);
	
	return (0);
}

int			lexer_set_token(t_token *token, char *line, int cursor)
{
	int		fragment_len;

	if (cursor >= ft_strlen(line))
		return (0);
	fragment_len = get_next_str_fragmnt(line + cursor);
	associate_token(token, line + cursor, fragment_len);
	return (cursor + fragment_len);
}
