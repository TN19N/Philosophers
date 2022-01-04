/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:43:38 by mannouao          #+#    #+#             */
/*   Updated: 2022/01/04 11:30:21 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_to_screen(t_data *table, int id, char *str)
{
	pthread_mutex_lock(&table->mtx_output);
	if (!table->stop)
		printf("%lu %d %s\n", get_time_pass(table->start_time), id, str);
	pthread_mutex_unlock(&table->mtx_output);
}

void	smart_sleep(unsigned long time)
{
	unsigned long	i;

	i = get_time();
	while (1)
	{
		if ((get_time() - i) * 1000 >= time)
			break ;
		usleep(50);
	}
}

void	eat(t_philo *philo)
{
	philo->eating = 1;
	print_to_screen(philo->table, philo->id, "is eating");
	philo->last_eat = get_time_pass(philo->table->start_time);
	smart_sleep(philo->table->tm_eat);
	philo->eating = 0;
	philo->num_eat++;
	pthread_mutex_unlock(&philo->table->mtx_forks[philo->wright_fork]);
	pthread_mutex_unlock(&philo->table->mtx_forks[philo->left_fork]);
}

void	*life(void *tmp)
{
	t_philo	*philo;

	philo = (t_philo *)tmp;
	if (!(philo->id % 2))
		usleep(1500);
	while (!philo->table->stop)
	{
		pthread_mutex_lock(&philo->table->mtx_forks[philo->wright_fork]);
		print_to_screen(philo->table, philo->id, "has taken a fork");
		if (philo->left_fork == philo->wright_fork)
		{
			pthread_mutex_unlock(&philo->table->mtx_forks[philo->wright_fork]);
			break ;
		}
		pthread_mutex_lock(&philo->table->mtx_forks[philo->left_fork]);
		print_to_screen(philo->table, philo->id, "has taken a fork");
		eat(philo);
		if (philo->num_eat == philo->table->count_eat)
			break ;
		print_to_screen(philo->table, philo->id, "is sleeping");
		smart_sleep(philo->table->tm_sleep);
		print_to_screen(philo->table, philo->id, "is thinking");
	}
	return (NULL);
}
