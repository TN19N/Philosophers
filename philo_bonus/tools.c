/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:42:02 by mannouao          #+#    #+#             */
/*   Updated: 2022/01/04 13:42:03 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	fill(t_data *table, int ac, char **av)
{
	table->num_philo = ft_atoi(av[1]);
	table->tm_die = ft_atoi(av[2]);
	table->tm_eat = ft_atoi(av[3]) * 1000;
	table->tm_sleep = ft_atoi(av[4]) * 1000;
	if (ac == 6)
		table->count_eat = ft_atoi(av[5]);
	else
		table->count_eat = -1;
	if(check_limts(table))
		print_error("Error! : max limit 200 (>= 60)\n");
}