/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:44:23 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 02:36:37 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_var(t_data *data, char *name, char *value);

// gets and returns the name of the variable
char	*get_var_name(char *input)
{
	printf("--PARSE_VARS.C---->[get_var_name]\n");
	int		i;
	int		space;
	char	*name;

	i = 0;
	space = 0;
	while (input[i] != '=')
	{
		i++;
		if (input[i] == ' ')
			space = i;
	}
	name = (char *)malloc((i - space) * sizeof(char) + 1);
	if (space)
	{
		while (*input != ' ')
			input++;
		space++;
		input++;
	}
	ft_strlcpy(name, input, (i - space) + 1);
	printf("[------ saida [get_var_name]-------------------]\n");
	return (name);
}

// gets and returns the value of the variable
char	*get_var_value(char *input)
{
	printf("--PARSE_VARS.C---->[get_var_value]\n");
	int		i;
	char	*value;

	i = 0;
	while (*input != '=')
		input++;
	input++;
	while (input[i])
		i++;
	value = (char *)malloc(i * sizeof(char) + 1);
	ft_strlcpy(value, input, i + 1);
	printf("[------ saida [get_var_value]-------------------]\n");
	return (value);
}

void	update_envp(t_data *data, char *name, char *value, t_vdt vdt)
{
	printf("--PARSE_VARS.C---->[update_envp]\n");
	int		var_size;
	int		name_size;
	int		value_size;
	char	*new_var;

	name_size = ft_strlen(name);
	value_size = ft_strlen(value);
	var_size = name_size + value_size + 2;
	new_var = malloc(sizeof(char) * var_size);
	ft_strlcpy(new_var, name, name_size + 1);
	ft_strlcat(new_var, "=", name_size + 3);
	ft_strlcat(new_var, value, value_size + name_size + 4);
	free(data->envp[vdt.is_envp]);
	data->envp[vdt.is_envp] = new_var;
	printf("[------ saida [update_envp]-------------------]\n");
}

static void	update_var(t_data *data, char *name, char *value)
{
	printf("--PARSE_VARS.C---->[update_var]\n");
	t_vdt	vdt;

	vdt = find_in_list(name, data->vars);
	if (!vdt.value)
		add_to_list(&data->vars, name, value);
	else
	{
		if (vdt.is_envp >= 0)
			update_envp(data, name, value, vdt);
		change_in_list(data->vars, name, value);
	}
	if (ft_strcmp(name, "PATH") == 0)
		update_command_path(data);
	printf("[------ saida [update_var]-------------------]\n");
}

// checks for variables in the input string and stores them on a linked list
int	grab_vars(t_data *data, char *str)
{
	printf("--PARSE_VARS.C---->[grab_var]\n");
	char	*name;
	char	*value;

	if (!ft_strchr(str, '='))
		return (FALSE);
	if (data->number_of_pipes >= 1)
		return (TRUE);
	name = get_var_name(str);
	value = get_var_value(str);
	if (!data->vars)
		data->vars = new_node(name, value);
	else
		update_var(data, name, value);
	free(name);
	free(value);
	printf("[------ saida [grab_var]-------------------]\n");
	return (TRUE);
}
