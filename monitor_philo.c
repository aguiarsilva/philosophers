/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:06:05 by baguiar-          #+#    #+#             */
/*   Updated: 2024/09/04 23:06:05 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int      is_dead(t_data *data, t_philo *philo)
{
    long    time;

    pthread_mutex_lock(&philo->t_last_meal_mutex);
    time = time_diff(&philo->t_last_meal);
    pthread_mutex_unlock(&philo->t_last_meal_mutex);
    if (time >= data->t_die)
    {
        pthread_mutex_lock(&data->running);
        data->run = 0;
        pthread_mutex_unlock(&data->running);
        action_print(data, philo, PHILO_DIED);
        return (1);
    }
    return (0);
}

static int      philo_filled(t_data *data, int i)
{
    return (data->n_must_eat != -1 
            && data->philos[i].eated >= data->n_must_eat);    
}

void    monitor_philo(t_data *data)
{
    int     i;
    int     n_philos_filled;

    while (1)
    {
        i = 0;
        n_philos_filled = 0;
        while (i < data->n_philo)
        {
            pthread_mutex_lock(&data->philos[i].protection);
            if (philo_filled(data, i))
                n_philos_filled++;
            pthread_mutex_unlock(&data->philos[i].protection);
            if (is_dead(data, &data->philos[i])
                    || n_philos_filled == data->n_philo)
            {
                pthread_mutex_lock(&data->running);
                data->run = 0;
                pthread_mutex_unlock(&data->running);
                return ;
            }
            i++;
        }
        usleep(100);
    }
}
