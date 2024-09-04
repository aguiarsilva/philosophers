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

