/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 08:12:13 by baguiar-          #+#    #+#             */
/*   Updated: 2024/10/01 11:17:01 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}

void	save_args(int argc, char **argv, t_data *data)
{
	data->n_philos = ft_atol(argv[1]);
	data->t_die = ft_atol(argv[2]);
	data->t_eat = ft_atol(argv[3]);
	data->t_sleep = ft_atol(argv[4]);
	if (argc == 6)
		data->min_meals = ft_atol(argv[5]);
	else
		data->min_meals = INT_MAX;
}

int	check_args(t_data *data)
{
	if (data->n_philos > PHILO_MAX || data->n_philos <= 0)
		return (ft_error("Number of Philosophers must be an int up to 200.\n"));
	if (data->t_die <= 0)
		return (ft_error("Time to die must be a positive integer.\n"));
	if (data->t_eat <= 0)
		return (ft_error("Time to eat must be a positive integer.\n"));
	if (data->t_sleep <= 0)
		return (ft_error("Time to sleep must be a positive integer.\n"));
	if (data->min_meals <= 0)
		return (ft_error("Number of meals must be a positive integer.\n"));
	return (0);
}
