/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:41:54 by mannouao          #+#    #+#             */
/*   Updated: 2022/01/07 17:13:03 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	close_all(t_data *table)
{
	sem_close(table->sem_output);
	sem_close(table->sem_forks);
	sem_unlink("/forks");
	sem_unlink("/output");
}

void	end_all(t_data *table, pid_t *pid)
{
	int	i;
	int	returned;

	i = -1;
	while (++i < table->num_philo)
	{
		waitpid(-1, &returned, 0);
		if (returned != 0)
		{
			i = -1;
			while (++i < table->num_philo)
				kill(pid[i], SIGKILL);
			break ;
		}
	}
	free(pid);
	close_all(table);
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	*pid;
	t_data	table;

	i = -1;
	if (ac < 5 || ac > 6)
		print_error("Error! : invalid number of arguments (4 or 5)\n");
	fill(&table, ac, av);
	pid = malloc(sizeof(pid_t) * table.num_philo);
	if (!pid)
	{
		close_all(&table);
		print_error("Error! : allocation faild (4 or 5)\n");
	}
	while (++i < table.num_philo)
	{
		table.id = i + 1;
		pid[i] = fork();
		if (pid[i] == -1)
			print_error("Error! : forking procces faild\n");
		if (!pid[i])
			start(&table);
	}
	end_all(&table, pid);
	return (0);
}
