/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:42:48 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 02:31:55 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	unmask_dollar_and_space(t_data *data, int id);
static void	save_vars(t_data *data, int id, int i, char *var_value);
static char	*pull_var_value(char *s[0], t_vars *vars);
static char	*ret_full_value(char **s, int offset, t_vdt *vdt, int i);

void	expander(t_data *data)
{
	printf("\n[--------------------------]\n");
	printf("--EXPAND_VARIABLES.C---->[expander]\n");
	int		i;
	int		id;
	char	*var_value;

	id = -1;
	while (data->argve[++id])
	{
		while (find_vars(data->argve[id]) != -1)
		{
			i = find_vars(data->argve[id]);
			var_value = pull_var_value(data->argve[id] + i, data->vars);
			if (!var_value || !*var_value)
			{
				if (!*var_value)
					ft_super_free((void **)&var_value);
				free(data->argve[id][i]);
				move_ptrs_back(&data->argve[id][i]);
				continue ;
			}
			save_vars(data, id, i, var_value);
		}
		unmask_dollar_and_space(data, id);
	}
	printf("[------ saida [expander]-------------------]\n");
}

static void	unmask_dollar_and_space(t_data *data, int id)
{
	printf("--EXPAND_VARIABLES.C---->[unmask_dollar_and_space]\n");
	int	i;

	i = 0;
	while (data->argve[id][i])
	{
		unmask_character(data->argve[id][i], 7, '$');
		unmask_character(data->argve[id][i++], 1, ' ');
	}
	printf("[------ saida [unmask_dollar_and_space]-------------------]\n");
}

static void	save_vars(t_data *data, int id, int i, char *var_value)
{
	printf("--EXPAND_VARIABLES.C---->[save_vars]\n");
	char	**cmdstr;

	cmdstr = new_argve(var_value, data, id);
	if (ft_strchr(var_value, ' '))
		insert_new_args(data, cmdstr, i, id);
	else
	{
		free(data->argve[id][i]);
		data->argve[id][i] = ft_strdup(var_value);
	}
	double_free((void ***)&cmdstr);
	ft_super_free((void **)&var_value);
	printf("[------ saida [save_vars]-------------------]\n");
}

static char	*pull_var_value(char **s, t_vars *vars)
{
	printf("--EXPAND_VARIABLES.C---->[pull_var_value]\n");
	char	*var_name;
	int		offset;
	int		i;
	t_vdt	vdt;

	offset = 0;
	while (s[0][offset] != '$')
		offset++;
	i = offset + 1;
	while ((ft_isalnum(s[0][i]) || s[0][i] == '_') && s[0][i])
		i++;
	if (s[0][i] == '?' && i == offset + 1) // colocar no projeto 
		i++;
	var_name = ft_substr(s[0], offset, i - offset);
	vdt = find_in_list(var_name, vars);
	free(var_name);
	printf("[------ saida [pull_var_value]-------------------]\n");
	return (ret_full_value(s, offset, &vdt, i));
}

static char	*ret_full_value(char **s, int offset, t_vdt *vdt, int i)
{
	printf("--EXPAND_VARIABLES.C---->[ret_full_value]\n");
	char	*ret;
	char	*prefix;

	if (!vdt->value)
	{
		ft_strcut(s, offset, i);
		return (ft_strdup(*s));
	}
	else
	{
		prefix = ft_substr(*s, 0, offset);
		ret = ft_mult_join(3, prefix, vdt->value, *s + i);
		if (vdt->is_allocated)
			free(vdt->value);
		free(prefix);
	}
	printf("[------ saida [ret_full_value]-------------------]\n");
	return (ret);
}
