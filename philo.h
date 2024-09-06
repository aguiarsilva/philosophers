/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:49:57 by baguiar-          #+#    #+#             */
/*   Updated: 2024/09/03 14:49:57 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <limits.h> // INT_MAX INT_MIN
#include <unistd.h> //write usleep
#include <stdlib.h> //malloc free EXIT_SUCCESS EXIT_FAILURE
#include <sys/time.h> // gettimeofday
#include <pthread.h> //mutex: init destroy lock unlock && threads: create join detach

# define PHILO_FORK 1
# define PHILO_EATING 2
# define PHILO_SLEEPING 3
# define PHILO_THINKING 4
# define PHILO_DIED 5

typedef struct  s_philo
{
    int                 id;
    int                 eated;
    pthread_t           thread;
    pthread_mutex_t     protection;
    pthread_mutex_t     *fork_right;
    pthread_mutex_t     *fork_left;
    struct s_data       *data;
    struct timeval      t_last_meal;
    pthread_mutex_t     t_last_meal_mutex;
}   t_philo;

typedef struct s_data
{
    t_philo             *philos;
    pthread_mutex_t     *forks;
    pthread_mutex_t     print;
    pthread_mutex_t     running;
    int                 n_philo;
    int                 t_die;
    int                 t_eat;
    int                 t_sleep;
    int                 n_must_eat;
    int                 run;
    struct  timeval     t_start;
}   t_data;

time_t  get_time_ms(void);
int     time_diff(struct timeval *begin);
void    msleep(long ms, t_data *data);
int     ft_atoi(char *str);
int     valid_argcv(int argc, char **argv);
void    monitor_philo(t_data *data);
void    treat_action(t_data *data, t_philo *philo, int sig);
int     args_initialize(t_data *data, int argc, char **argv);
int     running(t_data *data);
void    action_print(t_data *data, t_philo *philo, int sig);
void    *routine_philo(void *pt_philo);
int     philos_initialize(t_data *data);
int     free_data(t_data *data);
int     free_forks(pthread_mutex_t *forks, int n);
int     free_philos(t_philo *philos, int n);
int     free_data_mutexes(t_data *data);








#endif