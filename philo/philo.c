/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:07:10 by mannouao          #+#    #+#             */
/*   Updated: 2022/01/04 13:13:08 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

void	end_all(t_data *table)
{
	int	i;

	i = -1;
	while (++i < table->num_philo)
		pthread_join(table->threads[i], NULL);
	pthread_mutex_destroy(&table->mtx_output);
	i = -1;
	while (++i < table->num_philo)
		pthread_mutex_destroy(&table->mtx_forks[i]);
}

void	look(t_data *table)
{
	int	i;
	int	j;

	while (1)
	{
		i = -1;
		j = 0;
		while (++i < table->num_philo)
		{
			if (table->philos[i].num_eat < table->count_eat)
					j++;
			if (get_time_last_eat(table, i) >= table->tm_die && \
			!table->philos[i].eating)
			{
				print_to_screen(table, i + 1, "died");
				table->stop = 1;
				return ;
			}
		}
		if (table->count_eat != -1 && !j)
		{
			table->stop = 1;
			return ;
		}
	}
}

int	start(t_data *table)
{
	int	i;

	i = -1;
	while (++i < table->num_philo)
		if (pthread_mutex_init(&table->mtx_forks[i], NULL))
			return (1);
	if (pthread_mutex_init(&table->mtx_output, NULL))
		return (1);
	i = -1;
	table->start_time = get_time();
	while (++i < table->num_philo)
	{
		if (pthread_create(&table->threads[i], NULL, &life, &table->philos[i]))
			return (1);
	}
	look(table);
	end_all(table);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	table;

	if (ac < 5 || ac > 6)
		return (ft_error("Error! : invalid number of arguments (4 or 5)\n"));
	if (check(ac, av))
		return (ft_error("Error! : invalid arg (just >= 0 && =< MAX_INT)\n"));
	if (fill(&table, ac, av))
		return (ft_error("Error! : max limit 200 (>= 60)\n"));
	if (start(&table))
		return (ft_error("Error! : some pthread function faild\n"));
	else
		return (0);
}
