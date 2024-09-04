/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:24:14 by baguiar-          #+#    #+#             */
/*   Updated: 2024/09/04 22:24:14 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t  get_time_ms(void)
{
    struct timeval  val;

    gettimeofday(&val, NULL);
    return ((val.tv_sec * 1000) + (val.tv_usec / 1000));
}

int     time_diff(struct timeval *begin)
{
    struct timeval      now;
    int                 time;

    gettimeofday(&now, NULL);
    time = (now.tv_sec - begin->tv_sec) * 1000 + \
            (now.tv_usec - begin->tv_usec) / 1000;
    return (time);
}

void  msleep(long ms, t_data *data)
{
    struct timeval      begin;
    long                res;

    gettimeofday(&begin, NULL);
    res = 0;
    while (res < ms)
    {
        pthread_mutex_lock(&data->running);
        if (!data->run)
        {
            pthread_mutex_unlock(&data->running);
            return ;
        }
        pthread_mutex_unlock(&data->running);
        usleep(100);
        res = time_diff(&begin);
    }
}
