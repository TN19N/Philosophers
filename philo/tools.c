/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:16:20 by mannouao          #+#    #+#             */
/*   Updated: 2022/01/04 11:17:05 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			return (-1);
		str++;
	}
	return (num);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

unsigned long	get_time_last_eat(t_data *table, int i)
{
	return (get_time_pass(table->start_time) - table->philos[i].last_eat);
}

unsigned long	get_time_pass(unsigned long start_time)
{
	return (get_time() - start_time);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
