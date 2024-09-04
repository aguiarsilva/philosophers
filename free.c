/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:06:10 by baguiar-          #+#    #+#             */
/*   Updated: 2024/09/04 14:06:10 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     free_data_mutexes(t_data *data)
{
    pthread_mutex_destroy(&data->print);
    pthread_mutex_destroy(&data->running);
    return (EXIT_FAILURE);
}

int     free_philos(t_philo *philos, int n)
{
    int     i;

    i = 0;
    while (i < n)
    {
        pthread_mutex_destroy(&philos[i].t_last_meal_mutex);
        pthread_mutex_destroy(&philos[i].protection);
        i++;
    }
    free(philos);
    return (EXIT_FAILURE);
}

int     free_forks(pthread_mutex_t *forks, int n)
{
    int     i;

    i = 0;
    while (i < n)
    {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
    free(forks);
    return (EXIT_FAILURE);
}

int     free_data(t_data *data)
{
    free_data_mutexes(data);
    if (data->philos)
        free_philos(data->philos, data->n_philo);
    if (data->forks)
        free_forks(data->forks, data->n_philo);
    return (EXIT_FAILURE);
}
