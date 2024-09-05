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
    pthread_mutex_lock(&data->running)
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
    else if (sig == PHILO_THINKING)
    else if (sig == PHILO_DIED)
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
    
}