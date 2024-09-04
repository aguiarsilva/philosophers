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
        pthread_mutex_init(&data->philos[i], NULL);
        i++;
    }
    return (EXIT_SUCCES);
}

static int      r_fork(t_data *data, int i)
{
    return ((i + data->n_philo - 1) % data->n_philo);
}

int     philos_initialize(t_data *data)
{
    
}