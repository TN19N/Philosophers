/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:45:52 by mannouao          #+#    #+#             */
/*   Updated: 2022/04/16 20:13:59 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_to_screen(t_data *table, char *str)
{
	sem_wait(table->sem_output);
	if (table->live)
		printf("%lu %d %s\n", get_time_pass(table->start_time), table->id, str);
	sem_post(table->sem_output);
}

void	smart_sleep(unsigned int time, t_data *table)
{
	unsigned long	start_time;

	start_time = get_time();
	while (table->live)
	{
		if ((get_time() - start_time) * 1000 >= time)
			break ;
		usleep(300);
	}
}

void	*managing(void *void_table)
{
	t_data	*table;

	table = (t_data *)void_table;
	usleep(1500);
	while (table->live)
	{
		if (get_time_last_eat(table) >= table->tm_die \
			&& !table->eating)
		{
			sem_wait(table->sem_output);
			printf("%lu %d died\n", get_time_pass(table->start_time), table->id);
			exit(1);
		}
	}
	return (NULL);
}

void	eat(t_data *table)
{
	table->eating = 1;
	print_to_screen(table, "is eating");
	table->last_eat = get_time_pass(table->start_time);
	smart_sleep(table->tm_eat, table);
	table->num_eat++;
	table->eating = 0;
}

void	start(t_data *table)
{
	if (pthread_create(&table->mannager, NULL, &managing, table))
		exit(1);
	pthread_detach(table->mannager);
	table->start_time = get_time();
	if (table->id % 2)
		usleep(1500);
	while (table->live)
	{
		sem_wait(table->sem_forks);
		print_to_screen(table, "has taken a fork");
		sem_wait(table->sem_forks);
		print_to_screen(table, "has taken a fork");
		eat(table);
		sem_post(table->sem_forks);
		sem_post(table->sem_forks);
		if (table->num_eat == table->count_eat)
			break ;
		print_to_screen(table, "is sleeping");
		smart_sleep(table->tm_sleep, table);
		print_to_screen(table, "is thinking");
	}
	exit(0);
}
