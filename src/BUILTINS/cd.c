/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:35:06 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 17:13:03 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	too_many_arguments(char **str);
static int	chdir_to_oldpwd(t_vars *vars);
static int	chdir_to_home(char *cwd, t_vars *vars);
static void	update_paths(t_data *data, char *old_dir);

int	cd(t_data *data, int id)
{
	printf("\n[--------------------------]\n");
	printf("--CD.C---->[cd]\n");
	char	*new_dir;
	char	*old_dir;
	int		status;

	status = 0;
	if (too_many_arguments(data->argve[id]))
		return (EXIT_FAILURE);
	new_dir = data->argve[id][1];
	old_dir = getcwd(NULL, 0);
	if (!new_dir || *new_dir == '~')
		status = chdir_to_home(data->argve[id][1], data->vars);
	else if (!ft_strcmp("-", new_dir))
		status = chdir_to_oldpwd(data->vars);
	else if (chdir(new_dir))
	{
		ft_printf(STDERR, "Minishell: cd: %s: %s\n", new_dir, strerror(errno));
		ft_super_free((void **)&old_dir);
		g_status_code = 1;
		return (EXIT_FAILURE);
	}
	update_paths(data, old_dir);
	ft_super_free((void **)&old_dir);
	printf("[------ saida [cd]-------------------]\n");
	return (status);
}

static int	too_many_arguments(char **str)
{
	printf("--CD.C---->[too_many_arguments]\n");
	if (ft_str_count(str) > 2)
	{
		ft_putendl_fd("Minishell: cd: too many arguments", 2);
		g_status_code = 1;
		printf("[------ saida [cd]-EXIT_FAILURE----------------]\n");
		return (EXIT_FAILURE);
	}
	printf("[------ saida [cd]-EXIT_SUCCESS----------------]\n");
	return (EXIT_SUCCESS);
}

static int	chdir_to_home(char *cwd, t_vars *vars)
{
	printf("--CD.C---->[chdir_to_home]\n");
	t_vdt	vdt;
	char	*new_cwd;

	vdt = find_in_list("HOME", vars);
	if (!vdt.value)
	{
		ft_printf(STDERR, "Minishell: cd: HOME not set\n");
		printf("[------ saida [chdir_to_home]-FAILURE-----------------]\n");
		return (FAILURE);
	}
	if (!cwd)
		new_cwd = ft_strdup(vdt.value);
	else
		new_cwd = ft_strjoin(vdt.value, ++cwd);
	if (chdir(new_cwd))
	{
		g_status_code = 1;
		ft_printf(STDERR, "Minishell: cd: %s: %s\n", new_cwd, strerror(errno));
		free(new_cwd);
		printf("[------ saida [chdir_to_home]----FAILURE---------------]\n");
		return (FAILURE);
	}
	free(new_cwd);
	printf("[------ saida [chdir_to_home]----SUCCESS-----------]\n");
	return (SUCCESS);
}

static int	chdir_to_oldpwd(t_vars *vars)
{
	printf("--CD.C---->[chdir_to_oldpwd]\n");
	t_vdt	vdt;

	vdt = find_in_list("OLDPWD", vars);
	if (!vdt.value)
	{
		ft_printf(STDERR, "Minishell: cd: OLDPWD not set\n");
		printf("[------ saida [chdir_to_oldpwd]----FAILURE-----------]\n");
		return (FAILURE);
	}
	ft_printf(STDOUT, "%s\n", vdt.value);
	if (chdir(vdt.value))
	{
		g_status_code = 1;
		ft_printf(STDERR, "Minishell: cd: %s: %s\n", vdt.value, strerror(errno));
		printf("[------ saida [chdir_to_oldpwd]-EXIT_FAILURE---------]\n");
		return (EXIT_FAILURE);
	}
	printf("[------ saida [chdir_to_oldpwd]-EXIT_SUCCESS-------------]\n");
	return (EXIT_SUCCESS);
}

static void	update_paths(t_data *data, char *old_dir)
{
	printf("--CD.C---->[update_paths]\n");
	char	*curr_dir;
	t_vdt	vdt;

	curr_dir = getcwd(NULL, 0);
	vdt = find_in_list("OLDPWD", data->vars);
	update_envp(data, "OLDPWD", old_dir, vdt);
	change_in_list(data->vars, "OLDPWD", old_dir);
	vdt = find_in_list("PWD", data->vars);
	update_envp(data, "PWD", curr_dir, vdt);
	change_in_list(data->vars, "PWD", curr_dir);
	ft_super_free((void *)&curr_dir);
	printf("[------ saida [update_paths]-------------------]\n");
}
