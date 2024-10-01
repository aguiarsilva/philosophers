/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:58:02 by baguiar-          #+#    #+#             */
/*   Updated: 2024/10/01 11:20:27 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	ft_putstr_fd(char *str, int fd)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
	return (i);
}

long	ft_atol(const char *nptr)
{
	long int	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		num = (num * 10) + (nptr[i] - 48);
		i++;
	}
	return (num * sign);
}

int	ft_is_digit(char c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

/*need function to convert values from gettimeofday to milisecs*/
long	get_time(int time_cd)
{
	static struct timeval	begin;
	static pthread_mutex_t	begin_mutex = PTHREAD_MUTEX_INITIALIZER;
	struct timeval			present;

	(void) time_cd;
	if (gettimeofday(&present, NULL) != 0)
	{
		printf("Not possible to get time of day\n");
		return (-1);
	}
	pthread_mutex_lock(&begin_mutex);
	if (begin.tv_sec == 0 && begin.tv_usec == 0)
		begin = present;
	pthread_mutex_unlock(&begin_mutex);
	return (((present.tv_sec - begin.tv_sec) * (1000))
		+ ((present.tv_usec - begin.tv_usec) / 1000));
}

void	ft_usleep(long msec, t_data *data)
{
	long	begin_time;
	long	time_elapsed;

	begin_time = get_time(1);
	time_elapsed = begin_time;
	while ((time_elapsed - begin_time) < msec)
	{
		if (verify_sim_end(data))
			break ;
		if (msec - (time_elapsed - begin_time) > 10)
			usleep((msec - (time_elapsed - begin_time)) * 500);
		time_elapsed = get_time(1);
	}
}
