/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:41:54 by mannouao          #+#    #+#             */
/*   Updated: 2022/01/04 15:46:52 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	int i;
	int pid[200];
	t_data table;

	i = -1;
	if (ac < 5 || ac > 6)
		print_error("Error! : invalid number of arguments (4 or 5)\n");
	fill(&table, ac, av);
	table.start_time = get_time();
	while (++i < table.num_philo)
	{
		pid[i] = fork();
		if (pid[i] = -1)
			print_error("Error! : forking procces faild\n");
		if (!pid[i])
			start(table);
	}
	i = -1;
	while (++i < table.num_philo)
		waitpid(pid[i], NULL, NULL);
	return (0);
}