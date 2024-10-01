/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:39:43 by baguiar-          #+#    #+#             */
/*   Updated: 2024/10/01 11:14:35 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	stop_sim(t_data *data)
{
	int	i;

	i = 0;

	while (i < data->n_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	set_bool(&data->dt_mutex, &data->finish_sim, true);
	pthread_join(data->monitor, NULL);
}

static void	begin_sim(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_create(&data->philos[i].thread, NULL, philo_cycle,
			&data->philos[i]);
		i++;
	}
	pthread_create(&data->monitor, NULL, monitor_sim, data);
}

void	dinner_simulation(t_data *data)
{
	begin_sim(data);
	stop_sim(data);
}
