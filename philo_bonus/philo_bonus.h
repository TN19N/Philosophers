/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:41:57 by mannouao          #+#    #+#             */
/*   Updated: 2022/01/04 16:37:01 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H

# define PHILO_BONUS_H

# include <sys/time.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>

typedef struct	v_data
{
	unsigned long	start_time;
	int				num_philo;
	int				tm_die;
	unsigned long	tm_eat;
	unsigned long	tm_sleep;
	int				count_eat;
}				t_data;

void			print_error(char *str);
size_t			ft_strlen(char *str);
void			fill(t_data *data, int ac, char **av);
int				ft_atoi(const char *str);
void			print_error(char *str);
unsigned long	get_time(void);

#endif