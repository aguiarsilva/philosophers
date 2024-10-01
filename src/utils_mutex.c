/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:37:13 by baguiar-          #+#    #+#             */
/*   Updated: 2024/10/01 11:17:50 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

bool	get_bool(t_mtx *mutex, bool *val)
{
	bool	res;

	pthread_mutex_lock(mutex);
	res = *val;
	pthread_mutex_unlock(mutex);
	return (res);
}

long	get_long(t_mtx *mutex, long *val)
{
	long	res;

	pthread_mutex_lock(mutex);
	res = *val;
	pthread_mutex_unlock(mutex);
	return (res);
}

void	set_bool(t_mtx *mutex, bool *dest, bool val)
{
	pthread_mutex_lock(mutex);
	*dest = val;
	pthread_mutex_unlock(mutex);
}

void	set_long(t_mtx *mutex, long *dest, long val)
{
	pthread_mutex_lock(mutex);
	*dest = val;
	pthread_mutex_unlock(mutex);
}

