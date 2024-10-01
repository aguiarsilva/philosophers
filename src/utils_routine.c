/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:26:59 by baguiar-          #+#    #+#             */
/*   Updated: 2024/09/18 11:18:50 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

/*need function to free memory and destroy mutexes and forks if initialized*/
void free_data(t_data *data)
{
    t_philo *philo;
    int     i;

    i = 0;
    while (i < data->n_philos)
    {
        philo = data->philos + i;
        pthread_mutex_destroy(&philo->philo_mutex);
        i++;
    }
    pthread_mutex_destroy(&data->print_mutex);
    pthread_mutex_destroy(&data->dt_mutex);
    free(data->philos);
    free(data->forks); 
}

/*Proteciton for messages printed. Messages should be printed only
 * no philo has died, except fo message announcing the death of
 * the philo and if all philos are not done eating*/
void print_status(t_philo_status status, t_philo *philo)
{
    long    t_passed;

    if (philo->satt)
        return ;
    pthread_mutex_lock(&philo->data->print_mutex);
    t_passed = get_time(MILLISEC);
    if ((!verify_sim_end(philo->data)) && (TAKE_FIRST_FORK == status
            || TAKE_SECOND_FORK == status))
        printf("%s%ld %d has taken a fork\n", GREEN, t_passed, philo->philo_id);
    else if (EATING == status && !verify_sim_end(philo->data))
        printf("%s%ld %d is eating\n", WHITE, t_passed, philo->philo_id);
    else if (SLEEPING == status && !verify_sim_end(philo->data))
        printf("%s%ld %d is sleeping\n", PURPLE, t_passed, philo->philo_id);
    else if (THINKING == status && !verify_sim_end(philo->data))
        printf("%s%ld %d is thinking\n", YELLOW, t_passed, philo->philo_id);
    else if (DIED == status && verify_sim_end(philo->data))
        printf("%s%ld %d is dead\n", RED, t_passed, philo->philo_id);
    pthread_mutex_unlock(&philo->data->print_mutex);
}
