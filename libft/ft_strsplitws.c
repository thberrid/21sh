/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitws.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <smoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:55:08 by smoreno-          #+#    #+#             */
/*   Updated: 2020/01/16 09:57:27 by smoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cnt_words(const char *str)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str && str[i])
	{
		if (!ft_isspace(str[i]) && (!str[i + 1] || ft_isspace(str[i + 1])))
			words++;
		i++;
	}
	return (words);
}

static char		*ft_get_word(const char *str)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	if ((word = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	word[i] = '\0';
	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	return (word);
}

char			**ft_strsplitws(char const *s)
{
	char	**tab;
	int		i;
	int		w;
	int		words;

	i = 0;
	w = 0;
	words = ft_cnt_words(s);
	if (!s || !(tab = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (*s && ft_isspace(*s))
		s++;
	words = 0;
	while (s[i])
	{
		if ((tab[words++] = ft_get_word(&s[i])) == NULL)
			return (NULL);
		while (s[i] && !ft_isspace(s[i]))
			i++;
		while (s[i] && ft_isspace(s[i]))
			i++;
	}
	tab[words] = NULL;
	return (tab);
}
