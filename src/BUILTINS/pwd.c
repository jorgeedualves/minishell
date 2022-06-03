/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:37:12 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 17:12:52 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(void)
{
	printf("\n[--------------------------]\n");
	printf("--PWD.C---->[pwd]\n");
	char	*dir;

	dir = getcwd(NULL, 0);
	if (dir)
		printf("%s\n", dir);
	free(dir);
	printf("[------ saida [pwd]------free(dir);-------------]\n");
}
