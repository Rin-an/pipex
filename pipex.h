/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:34:15 by ssadiki           #+#    #+#             */
/*   Updated: 2022/05/24 23:34:21 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		end[2];
	int		fd1;
	int		fd2;
	char	*cmd;
	char	**cmdargs;
	char	*path;
	char	**paths;
	pid_t	child1;
	pid_t	child2;
}	t_pipex;

void	child1(t_pipex *p, char **argv, char **envp);
void	child2(t_pipex *p, char **argv, char **envp);
void	find_path(t_pipex *p, char **envp);
void	close_pipe(t_pipex *p);
void	free_parent(t_pipex *p);
void	free_child(t_pipex *p);
void	error(char *msg);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
#endif
