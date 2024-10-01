/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:04:35 by baguiar-          #+#    #+#             */
/*   Updated: 2024/09/18 10:54:13 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	philos_init(t_data *data)
{
	int	    i;
    t_philo *philo;

    i = -1;
    while (++i < data->n_philos)
    {
        philo = data->philos + i;
        philo->philo_id = i + 1;
        philo->satt = false;
        philo->n_meals = 0;
        philo->data = data;
        philo->t_last_meal = get_time(MILLISEC);
        pthread_mutex_init(&philo->philo_mutex, NULL);
        dist_forks(philo, data->forks, i);
    }
}

bool    init_data(t_data *data)
{
    int i;

    i = 0;
    data->finish_sim = false;
    data->philos = malloc(data->n_philos * sizeof(t_philo));
    data->forks = malloc(data->n_philos * sizeof(t_fork));
    if (!data->philos || !data->forks)
        return (printf("Failed to allocate memory!\n"), false);
    pthread_mutex_init(&data->dt_mutex, NULL);
    pthread_mutex_init(&data->print_mutex, NULL);
    while (i < data->n_philos)
    {
        pthread_mutex_init(&data->forks[i].fork, NULL);
        data->forks->fork_id = i;
        i++;
    }
    philos_init(data);
	return (true);
}

