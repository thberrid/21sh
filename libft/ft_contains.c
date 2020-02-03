/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 20:42:21 by smoreno-          #+#    #+#             */
/*   Updated: 2018/11/24 02:51:42 by smoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_contains(const char c, register const char *str)
{
	while (str && *str)
		if (c == *str++)
			return (1);
	return (0);
}
