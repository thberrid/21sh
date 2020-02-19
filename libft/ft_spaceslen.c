/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaceslen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:13:07 by thberrid          #+#    #+#             */
/*   Updated: 2020/02/19 14:13:08 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_spaceslen(char *str)
{
	int		len;

	len = 0;
	while (str[len] && ft_isspace(str[len]))
		len += 1;
	return (len);
}
