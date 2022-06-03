/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:46:25 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 02:39:54 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// changes the value of an existing variable on the list
void	change_in_list(t_vars *lst, char *var_name, char *var_value)
{
	printf("\n[--------------------------]\n");
	printf("--LIST_TOOLS_TWO.C---->[change_in_list]\n");
	if (lst != 0x0)
	{
		while (lst)
		{
			if (ft_strcmp(var_name, lst->var_name) == 0)
			{
				free(lst->var_value);
				lst->var_value = ft_strdup(var_value);
				printf("\n[------ saida [change_in_list]-------------------]\n");
				return ;
			}
			lst = lst->next;
		}
	}
	printf("[------ saida [change_in_list]-------------------]\n");
}

// deletes an item in list
void	delete_in_list(char *var_name, t_vars **vars)
{
	printf("--LIST_TOOLS_TWO.C---->[delete_in_list]\n");
	t_vars	*temp;
	t_vars	*prev;

	temp = *vars;
	prev = temp;
	if (temp && !ft_strcmp(var_name, temp->var_name))
	{
		*vars = temp->next;
		free(temp->var_name);
		free(temp->var_value);
		free(temp);
		printf("[------ saida [delete_in_list]-------------------]\n");
		return ;
	}
	while (temp && ft_strcmp(var_name, temp->var_name))
	{
		prev = temp;
		temp = temp->next;
	}
	if (!temp)
	{
		printf("[------ saida [delete_in_list]-------------------]\n");
		return ;
	}
		
	prev->next = temp->next;
	free(temp->var_name);
	free(temp->var_value);
	free(temp);
	printf("[------ saida [delete_in_list]-------------------]\n");
}

// updates the envp index in a list item
void	upd_idx_in_list(t_vars *lst, char *var_name, int pos)
{
	printf("--LIST_TOOLS_TWO.C---->[upd_idx_in_list]\n");
	if (lst != 0x0)
	{
		while (lst)
		{
			if (ft_strcmp(var_name, lst->var_name) == 0)
			{
				lst->env = pos;
				printf("[------ saida [upd_idx_in_list]-------------------]\n");
				return ;
			}
			lst = lst->next;
		}
	}
	printf("[------ saida [upd_idx_in_list]-------------------]\n");
}
