/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:48:46 by mannouao          #+#    #+#             */
/*   Updated: 2022/01/05 13:33:41 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *table)
{
	free(table->threads);
	free(table->mtx_forks);
	free(table->philos);
}

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

int	allocation(t_data *table)
{
	table->philos = malloc(sizeof(t_philo) * table->num_philo);
	if (!table->philos)
		return (1);
	table->mtx_forks = malloc(sizeof(pthread_mutex_t) * table->num_philo);
	if (!table->mtx_forks)
	{
		free(table->philos);
		return (1);
	}
	table->threads = malloc(sizeof(pthread_t) * table->num_philo);
	if (!table->mtx_forks)
	{
		free(table->mtx_forks);
		free(table->philos);
		return (1);
	}
	return (0);
}

int	fill_check(t_data *table, int ac, char **av)
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
	if (allocation(table))
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
