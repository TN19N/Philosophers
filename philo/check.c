/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:48:46 by mannouao          #+#    #+#             */
/*   Updated: 2022/01/04 09:00:05 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < 5)
	{
		if (ft_atoi(av[i]) == -1)
			return (1);
	}
	if (ac == 6)
		if (ft_atoi(av[5]) == -1)
			return (1);
	return (0);
}

int	check_limits(t_data *table)
{
	if (table->num_philo <= 0 || table->num_philo > 200)
		return (1);
	if (table->tm_die < 60 || table->tm_eat < 60000)
		return (1);
	if (table->tm_sleep < 60000)
		return (1);
	return (0);
}

int	fill(t_data *table, int ac, char **av)
{
	int	i;

	i = -1;
	table->num_philo = ft_atoi(av[1]);
	table->tm_die = ft_atoi(av[2]);
	table->tm_eat = ft_atoi(av[3]) * 1000;
	table->tm_sleep = ft_atoi(av[4]) * 1000;
	table->stop = 0;
	if (ac == 6)
		table->count_eat = ft_atoi(av[5]);
	else
		table->count_eat = -1;
	if (check_limits(table))
		return (1);
	while (++i < table->num_philo)
	{
		table->philos[i].id = i + 1;
		table->philos[i].last_eat = 0;
		table->philos[i].num_eat = 0;
		table->philos[i].eating = 0;
		table->philos[i].wright_fork = i;
		table->philos[i].left_fork = (i + 1) % table->num_philo;
		table->philos[i].table = table;
	}
	return (0);
}
