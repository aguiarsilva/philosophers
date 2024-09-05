/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:59:33 by baguiar-          #+#    #+#             */
/*   Updated: 2024/09/04 13:59:33 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_data      data;
    int         i;

    i = 0;
    data.philos = NULL;
    data.forks = NULL;
    if (valid_args(argc, argv) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (args_initialize(&data, argc, argv) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (philos_initialize(&data) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    while (i < data.n_philo && !pthread_join(data.philos[i].thread, NULL))
        i++;
    free_data(&data);
    return (EXIT_SUCCESS);
}
