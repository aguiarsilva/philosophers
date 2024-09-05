/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:55:07 by baguiar-          #+#    #+#             */
/*   Updated: 2024/09/04 14:55:07 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int      make_forks(t_data *data, int n_philo)
{
    int     i;

    i = 0;
    data->forks = malloc(sizeof(pthread_mutex_t) * n_philo);
    if (!data->forks)
    {
        free(data->philos);
        return (free_data_mutexes(data));
    }
    while (i < n_philo)
    {
        pthread_mutex_init(&data->philos[i].t_last_meal_mutex, NULL);
        pthread_mutex_init(&data->philos[i].protection, NULL);
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    return (EXIT_SUCCESS);
}

static int      r_fork(t_data *data, int i)
{
    return ((i + data->n_philo - 1) % data->n_philo);
}

int     philos_initialize(t_data *data)
{
    int     i;

    i = 0;
    data->philos = malloc(sizeof(t_philo) * (data->n_philo));
    if (!data->philos)
        return (free_data_mutexes(data));
    if (make_forks(data, data->n_philo) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    data->run = 1;
    gettimeofday(&data->t_start, NULL);
    while (i < data->n_philo)
    {
        data->philos[i].data = data;
        data->philos[i].id = i + 1;
        data->philos[i].eated = 0;
        data->philos[i].fork_left = &data->forks[i];
        data->philos[i].fork_right = &data->forks[r_fork(data, i)];
        gettimeofday(&data->philos[i].t_last_meal, NULL);
        if (pthread_create(&data->philos[i].thread, NULL, &philo_routine,
                (void *)&data->philos[i]))
            return(free_data(data));
        i++;
    }
    monitor_philo(data);
    return (EXIT_SUCCESS);
}
