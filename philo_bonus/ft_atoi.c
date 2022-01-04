/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:49:28 by mannouao          #+#    #+#             */
/*   Updated: 2022/01/04 13:08:35 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
			print_error("Error! : invalid arguments (just <= MAX_INT numbers)\n");
		str++;
	}
	if (num = -1)
		print_error("Error! : invalid arguments (just >= 0 numbers)\n");
	return (num);
}
