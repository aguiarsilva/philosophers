/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:46:12 by baguiar-          #+#    #+#             */
/*   Updated: 2024/09/04 14:46:12 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     args_initialize(t_data *data, int argc, char **argv)
{
    data->n_philo = ft_atoi(argv[1]);
    data->t_die = ft_atoi(argv[2]);
    data->t_eat = ft_atoi(argv[3]);
    data->t_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        data->n_must_eat = ft_atoi(argv[5]);
    else
        data->n_must_eat = -1;
    if (data->n_philo < 1 || data->t_die < 1 
            || data->t_eat < 1 || data->t_sleep < 1)
        return (EXIT_FAILURE);
    pthread_mutex_init(&data->print, NULL);
    pthread_mutex_init(&data->running, NULL);
    return (EXIT_SUCCESS);
}
