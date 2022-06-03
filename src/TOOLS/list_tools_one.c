/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:46:11 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 03:02:55 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// list handling functions

// creates a new node with received values
t_vars	*new_node(char *name, char *value)
{
	printf("\n[--------------------------]\n");
	printf("--LIST_TOOLS_ONE.C---->[new_node]\n");
	t_vars	*new;

	new = (t_vars *)malloc(sizeof(t_vars));
	if (!new)
	{
		printf("[------ saida [new_node] - Falha Malloc-----]\n");
		return (NULL);
	}
	new->var_name = ft_strdup(name);
	new->var_value = ft_strdup(value);
	new->next = NULL;
	new->env = -1;
	printf("[------ saida [new_node]------Retornando NEW----------------]\n");
	return (new);
}

// finds the last node on the list
t_vars	*last_in_list(t_vars *lst)
{
	printf("--LIST_TOOLS_ONE.C---->[last_in_list]\n");
	if (!lst)
	{
		printf("[------ saida [find_in_list] lista esta vazia-------------------]\n");
		return (0);
	}
	while (lst->next)
		lst = lst->next;
	printf("[------ saida [find_in_list]-------------------]\n");
	return (lst);
}

// creates a new node on an existing list
void	add_to_list(t_vars **lst, char *name, char *value)
{
	printf("--LIST_TOOLS_ONE.C---->[add_to_list]\n");
	t_vars	*aux;
	t_vars	*new;

	new = new_node(name, value);
	if (!*lst)
	{
		*lst = new;
		printf("[------ saida [add_to_list]-------------------]\n");
		return ;
	}
	aux = last_in_list(*lst);
	aux->next = new;
	printf("[------ saida [add_to_list]-------------------]\n");
}

// clears the list and frees its memory
void	clear_list(t_vars *lst)
{
	printf("--LIST_TOOLS_ONE.C---->[clear_list]\n");
	t_vars	*aux;

	if (lst != 0x0)
	{
		while (lst)
		{
			aux = lst->next;
			free(lst->var_name);
			free(lst->var_value);
			free(lst);
			lst = aux;
		}
	}
	printf("[------ saida [clear_list]-------------------]\n");
}

// finds a variable name on a list
//char	*find_in_list(char *var_name, t_vars *lst)
t_vdt	find_in_list(char *var_name, t_vars *lst)
{
	printf("--LIST_TOOLS_ONE.C---->[find_in_list]\n");
	t_vdt	ret;

	ret = (t_vdt){0};
	if (!var_name || !lst)
		return (ret);
	if (*var_name == '$')
		var_name++;
	if (!ft_strcmp(var_name, "?"))
	{
		ret.value = ft_itoa(g_status_code);
		ret.is_allocated = 1;
		printf("[------ saida [find_in_list]-------------------]\n");
		return (ret);
	}
	while (lst)
	{
		if (ft_strcmp(var_name, lst->var_name) == 0)
		{
			ret.value = lst->var_value;
			ret.is_envp = lst->env;
			printf("[------ saida [find_in_list]-------------------]\n");
			return (ret);
		}
		lst = lst->next;
	}
	printf("[------ saida [find_in_list]-------------------]\n");
	return (ret);
}