/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:03:35 by baguiar-          #+#    #+#             */
/*   Updated: 2024/09/18 10:54:15 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static void *single_philo(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    set_long(&philo->philo_mutex, &philo->t_last_meal,
            get_time(MILLISEC));
    print_status(TAKE_FIRST_FORK, philo);
    while (!verify_sim_end(philo->data))
        ft_usleep(100, philo->data);
    return (NULL);
}

void    *philo_cycle(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->data->n_philos == 1)
        single_philo(philo);
    if (philo->philo_id % 2 == 0)
    {
        print_status(THINKING, philo);
        ft_usleep(philo->data->t_eat / 2, philo->data);
    }
    philo_routine(philo);
    return (NULL);
}

