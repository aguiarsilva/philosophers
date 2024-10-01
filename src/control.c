/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:53:41 by baguiar-          #+#    #+#             */
/*   Updated: 2024/10/01 11:10:14 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	ist_forks(t_philo *philo, t_fork *forks, int philo_pos)
{
	int	num_philo;

	num_philo = philo->data->n_philos;
	philo->fork_first = &forks[(philo_pos + 1) % num_philo];
	philo->fork_second = &forks[philo_pos];
	if (philo->philo_id % 2 == 0)
	{
		philo->fork_first = &forks[philo_pos];
		philo->fork_second = &forks[(philo_pos + 1) % num_philo];
	}
}

bool	verify_sim_end(t_data *data)
{
	return (get_bool(&data->dt_mutex, &data->finish_sim));
}

static bool	philo_died(t_philo *philo)
{
	long	passed;
	long	time_to_die;

	if (get_bool(&philo->philo_mutex, &philo->satt))
		return (false);
	passed = get_time(MILLISEC) - get_long(&philo->philo_mutex,
			&philo->t_last_meal);
	time_to_die = philo->data->t_die - 1;
	if (passed > time_to_die)
		return (true);
	return (false);
}

void	*monitor_sim(void *data)
{
	int		i;
	t_data	*table;

	table = (t_data *)data;
	while (!verify_sim_end(table))
	{
		i = 0;
		while (i < table->n_philos && !verify_sim_end(table))
		{
			if (philo_died(table->philos + i))
			{
				set_bool(&table->dt_mutex, &table->finish_sim, true);
				print_status(DIED, table->philos + i);
			}
			i++;
		}
	}
	return (NULL);
}
