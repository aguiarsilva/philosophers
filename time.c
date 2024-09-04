/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:24:14 by baguiar-          #+#    #+#             */
/*   Updated: 2024/09/04 22:24:14 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t  get_time_ms(void)
{
    struct timeval  val;

    gettimeofday(&val, NULL);
    return ((val.tv_sec * 1000) + (val.tv_usec / 1000));
}
