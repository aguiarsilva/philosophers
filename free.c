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

