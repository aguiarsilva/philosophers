/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:55:26 by baguiar-          #+#    #+#             */
/*   Updated: 2024/09/04 23:55:26 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     running(t_data *data)
{
    pthread_mutex_lock(&data->running);
    if (data->run)
    {
        pthread_mutex_unlock(&data->running);
        return (1);
    }
    pthread_mutex_unlock(&data->running);
    return (0);
}

void    action_print(t_data *data, t_philo *philo, int sig)
{
    pthread_mutex_lock(&data->print);
    if (sig == PHILO_FORK)
        printf("%i %i has taken a fork\n", time_diff(&data->t_start), philo->id);
    else if (sig == PHILO_EATING)
        printf("%i %i is eating\n", time_diff(&data->t_start), philo->id);
    else if (sig == PHILO_SLEEPING)
        printf("%i %i is sleeping\n", time_diff(&data->t_start), philo->id);
    else if (sig == PHILO_THINKING)
        printf("%d %d is thinking\n", time_diff(&data->t_start), philo->id);
    else if (sig == PHILO_DIED)
        printf("%d %d died\n", time_diff(&data->t_start), philo->id);
    pthread_mutex_unlock(&data->print);
}

static void     treat_philo_eating(t_data *data, t_philo *philo)
{
    action_print(data, philo, PHILO_EATING);
    pthread_mutex_lock(&philo->t_last_meal_mutex);
    gettimeofday(&philo->t_last_meal, NULL);
    pthread_mutex_unlock(&philo->t_last_meal_mutex);
    pthread_mutex_lock(&philo->protection);
    philo->eated++;
    pthread_mutex_unlock(&philo->protection);
    msleep(philo->data->t_eat, data);
}

void    treat_action(t_data *data, t_philo *philo, int sig)
{
    if (!running(data))
        return ;
    if (sig == PHILO_FORK && running(data))
        action_print(data, philo, PHILO_FORK);
    if (sig == PHILO_EATING && running(data))
        treat_philo_eating(data, philo);
    else if (sig == PHILO_SLEEPING && running(data))
    {
        action_print(data, philo, PHILO_SLEEPING);
        msleep(data->t_sleep, data);
    }
    else if (sig == PHILO_THINKING && running(data))
    {
        action_print(data, philo, PHILO_THINKING);
        msleep(((data->t_die - time_diff(&philo->t_last_meal) \
                    - data->t_eat) * 0.5), data);
    }
    else if (sig == PHILO_DIED && running(data))
        action_print(data, philo, PHILO_DIED);
    return ((void) EXIT_SUCCESS);
}

void    *routine_philo(void *pt_philo)
{
    t_philo *philo;

    philo = pt_philo;
    if (philo->data->n_philo == 1)
    {
        pthread_mutex_lock(philo->fork_left);
        treat_action(philo->data, philo, PHILO_FORK);
        return (NULL);
    }
    if (philo->id % 2 == 0)
        treat_action(philo->data, philo, PHILO_THINKING);
    while (running(philo->data))
    {
        pthread_mutex_lock(philo->fork_left);
        treat_action(philo->data, philo, PHILO_FORK);
        pthread_mutex_lock(philo->fork_right);
        treat_action(philo->data, philo, PHILO_FORK);
        treat_action(philo->data, philo, PHILO_EATING);
        pthread_mutex_unlock(philo->fork_left);
        pthread_mutex_unlock(philo->fork_right);
        treat_action(philo->data, philo, PHILO_SLEEPING);
        treat_action(philo->data, philo, PHILO_THINKING);
    }
    return ((void *)EXIT_SUCCESS);
}
