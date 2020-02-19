/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:10:18 by thberrid          #+#    #+#             */
/*   Updated: 2020/02/19 14:10:26 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
