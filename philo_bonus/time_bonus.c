/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:41:32 by mannouao          #+#    #+#             */
/*   Updated: 2022/01/07 16:46:36 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

unsigned long	get_time_last_eat(t_data *table)
{
	return (get_time_pass(table->start_time) - table->last_eat);
}

unsigned long	get_time_pass(unsigned long start_time)
{
	return (get_time() - start_time);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
