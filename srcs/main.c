/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 23:12:55 by thberrid          #+#    #+#             */
/*   Updated: 2020/02/03 23:13:38 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twentyonesh.h>

int		main(int ac, char **av, char **env)
{
	int		retrn;

	(void)ac;
	(void)av;
	retrn = prompt_loop(env);
	if (LEAKS)
		system("leaks 21sh");
	if (DEBUG)
		ft_printf("$? : %d\n", retrn);
	return (retrn);
}
