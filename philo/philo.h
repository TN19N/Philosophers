/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:05:01 by mannouao          #+#    #+#             */
/*   Updated: 2022/01/04 15:37:28 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_data;

typedef struct s_philo
{
	int				id;
	unsigned long	last_eat;
	int				num_eat;
	int				wright_fork;
	int				left_fork;
	int				eating;
	struct s_data	*table;
}				t_philo;

typedef struct s_data
{
	t_philo			philos[200];
	pthread_t		threads[200];
	pthread_mutex_t	mtx_forks[200];
	pthread_mutex_t	mtx_output;
	unsigned long	start_time;
	int				num_philo;
	unsigned long	tm_sleep;
	unsigned long	tm_eat;
	unsigned long	tm_die;
	int				count_eat;
	int				stop;
}				t_data;

size_t			ft_strlen(const char *s);
int				ft_error(char *str);
int				ft_atoi(const char *str);
void			free_all(t_data *table);
int				free_all_error(t_data *table);
int				check(int ac, char **av);
int				fill(t_data *table, int ac, char **av);
void			*life(void *tmp);
unsigned long	get_time(void);
unsigned long	get_time_pass(unsigned long start_time);
unsigned long	get_time_last_eat(t_data *table, int i);
void			print_to_screen(t_data *table, int id, char *str);

#endif
