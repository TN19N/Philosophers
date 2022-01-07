/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:41:57 by mannouao          #+#    #+#             */
/*   Updated: 2022/01/07 16:36:51 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H

# define PHILO_BONUS_H

# include <signal.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>

typedef struct v_data
{
	int				id;
	int				live;
	int				eating;
	unsigned long	last_eat;
	int				num_eat;
	pthread_t		mannager;
	unsigned long	start_time;
	int				num_philo;
	unsigned long	tm_die;
	unsigned long	tm_eat;
	unsigned long	tm_sleep;
	int				count_eat;
	sem_t			*sem_forks;
	sem_t			*sem_output;
}				t_data;

void			print_error(char *str);
size_t			ft_strlen(const char *str);
void			fill(t_data *data, int ac, char **av);
void			print_error(char *str);
unsigned long	get_time(void);
unsigned long	get_time_pass(unsigned long start_time);
unsigned long	get_time_last_eat(t_data *table);
void			end_all(t_data *table, pid_t *pid);
void			print_to_screen(t_data *table, char *str);
void			start(t_data *table);

#endif