/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:25:02 by ssadiki           #+#    #+#             */
/*   Updated: 2022/05/24 23:27:04 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_parent(t_pipex *p)
{
	int	i;

	i = -1;
	close(p->fd1);
	close(p->fd2);
	while (p->paths[++i])
		free(p->paths[i]);
	free(p->paths);
}

void	free_child(t_pipex *p)
{
	int	i;

	i = -1;
	while (p->cmdargs[++i])
		free(p->cmdargs[i]);
	free(p->cmdargs);
	free(p->cmd);
}
