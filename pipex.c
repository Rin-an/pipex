/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:18:04 by ssadiki           #+#    #+#             */
/*   Updated: 2022/05/24 23:27:18 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *msg)
{
	perror(msg);
	exit(1);
}

void	find_path(t_pipex *p, char **envp)
{
	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	p->path = *envp + 5;
}

void	pipex(t_pipex *p, char **argv, char **envp)
{
	if (pipe(p->end) < 0)
		error("Error in pipe!");
	p->child1 = fork();
	if (p->child1 == 0)
		child1(p, argv, envp);
	p->child2 = fork();
	if (p->child2 == 0)
		child2(p, argv, envp);
	close_pipe(p);
	waitpid(p->child1, NULL, 0);
	waitpid(p->child2, NULL, 0);
	free_parent(p);
}

void	close_pipe(t_pipex *p)
{
	close(p->end[0]);
	close(p->end[1]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*p;

	p = malloc(sizeof(t_pipex));
	if (argc != 5)
		error("Error in number of arguments!");
	p->fd1 = open(argv[1], O_RDONLY);
	if (p->fd1 < 0)
		error("Error in input file!");
	p->fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (p->fd2 < 0)
		error("Error in output file!");
	find_path(p, envp);
	p->paths = ft_split(p->path, ':');
	pipex(p, argv, envp);
	close(p->fd1);
	close(p->fd2);
	free(p);
	return (0);
}
