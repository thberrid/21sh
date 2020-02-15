/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twentyonesh.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 23:11:15 by thberrid          #+#    #+#             */
/*   Updated: 2020/02/03 23:12:41 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWENTYONESH_H
# define TWENTYONESH_H

# include <libft.h>

# define DEBUG 1
# define LEAKS 0

# define PROMPT "\e[36m# \e[0m"

int		prompt_loop(char **env);

#endif
