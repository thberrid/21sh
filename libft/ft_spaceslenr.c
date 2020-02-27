/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaceslenr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 08:24:00 by thberrid          #+#    #+#             */
/*   Updated: 2020/02/09 08:24:02 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_spaceslenr(char *str, int len)
{
	int		spaces;

	spaces = 0;
	while (len)
	{
		if (ft_isspace(str[len - 1]))
			spaces += 1;
		else
			break ;
		len -= 1;
	}
	return (spaces);
}