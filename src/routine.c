/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:18:18 by baguiar-          #+#    #+#             */
/*   Updated: 2024/09/18 11:11:05 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void    think_routine(t_philo *philo, bool pre_sim)
{
    long    t_eat;
    long    t_think;
    long    t_sleep;

    if (!pre_sim)
        print_status(THINKING, philo);
    if (philo->data->n_philos % 2 == 0)
        return ;
    t_eat = philo->data->t_eat;
    t_sleep = philo->data->t_sleep;
    t_think = (t_eat * 2) - t_sleep;
    if (t_think < 0)
        t_think = 0;
    ft_usleep(t_think, philo->data);
}

static void     eat_routine(t_philo *philo)
{
    pthread_mutex_lock(&philo->fork_first->fork);
    print_status(TAKE_FIRST_FORK, philo);
    pthread_mutex_lock(&philo->fork_second->fork);
    print_status(TAKE_SECOND_FORK, philo);
    set_long(&philo->philo_mutex, &philo->t_last_meal,
             get_time(MILLISEC));
    philo->n_meals++;
    print_status(EATING, philo);
    ft_usleep(philo->data->t_eat, philo->data);
    if (philo->data->min_meals > 0
        && philo->n_meals == philo->data->min_meals)
        set_bool(&philo->philo_mutex, &philo->satt, true);
    pthread_mutex_unlock(&philo->fork_first->fork);
    pthread_mutex_unlock(&philo->fork_second->fork);
}

void    *philo_routine(t_philo *philo)
{
    while (!verify_sim_end(philo->data))
    {
       if (philo->satt)
            break ;
        eat_routine(philo);
        ft_usleep(philo->data->t_sleep, philo->data);
        think_routine(philo, false);
    }
    return (NULL);
}
