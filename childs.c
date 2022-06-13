/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:38:41 by ssadiki           #+#    #+#             */
/*   Updated: 2022/05/24 23:23:43 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(t_pipex *p, char **argv, char **envp)
{
	int	r;
	int	i;

	i = -1;
	dup2(p->fd1, 0);
	dup2(p->end[1], 1);
	close(p->end[0]);
	p->cmdargs = ft_split(argv[2], ' ');
	while (p->paths[++i])
	{
		p->cmd = ft_strjoin(p->paths[i], p->cmdargs[0]);
		r = access(p->cmd, F_OK) + access(p->cmd, X_OK);
		if (r == 0)
			break ;
	}
	if (r != 0)
	{
		free_child(p);
		error("Error cmd1 does not exist or not executable!");
	}
	execve(p->cmd, p->cmdargs, envp);
}

void	child2(t_pipex *p, char **argv, char **envp)
{
	int	r;
	int	i;

	i = -1;
	dup2(p->end[0], 0);
	close(p->end[1]);
	dup2(p->fd2, 1);
	p->cmdargs = ft_split(argv[3], ' ');
	while (p->paths[++i])
	{
		p->cmd = ft_strjoin(p->paths[i], p->cmdargs[0]);
		r = access(p->cmd, F_OK) + access(p->cmd, X_OK);
		if (r == 0)
			break ;
	}
	if (r != 0)
	{
		free_child(p);
		error("Error cmd2 does not exist or is not executable!");
	}
	execve(p->cmd, p->cmdargs, envp);
}
