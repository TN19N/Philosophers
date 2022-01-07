/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:42:02 by mannouao          #+#    #+#             */
/*   Updated: 2022/01/07 16:43:28 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	print_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(0);
}

int	ft_atoi(const char *str)
{
	long	num;

	num = -1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (num == -1)
			num = 0;
		num = (num * 10) + (*str - '0');
		if (num > 2147483647)
			print_error("Error! : invalid args (just <= MAX_INT numbers)\n");
		str++;
	}
	if (num == -1)
		print_error("Error! : invalid arguments (just >= 0 numbers)\n");
	return (num);
}

void	fill(t_data *table, int ac, char **av)
{
	table->num_philo = ft_atoi(av[1]);
	table->tm_die = ft_atoi(av[2]);
	table->tm_eat = ft_atoi(av[3]) * 1000;
	table->tm_sleep = ft_atoi(av[4]) * 1000;
	table->live = 1;
	table->eating = 0;
	table->num_eat = 0;
	table->last_eat = 0;
	if (ac == 6)
		table->count_eat = ft_atoi(av[5]);
	else
		table->count_eat = -1;
	sem_unlink("/forks");
	sem_unlink("/output");
	table->sem_forks = sem_open("/forks", 0xA00, 0644, table->num_philo);
	if (table->sem_forks == SEM_FAILED)
		print_error("Error! : open semaphore for forks faild\n");
	table->sem_output = sem_open("/output", O_CREAT | O_EXCL, 0644, 1);
	if (table->sem_output == SEM_FAILED)
		print_error("Error! : open semaphore for output faild\n");
}
