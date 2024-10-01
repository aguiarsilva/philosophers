/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:11:18 by baguiar-          #+#    #+#             */
/*   Updated: 2024/09/18 11:17:30 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>

#ifndef PHILO_MAX
# define PHILO_MAX 200
#endif

# define GREEN "\e[38;5;84m"
# define BLUE   "\e[38;5;104m"
# define ORANGE "\e[38;5;226m"
# define YELLOW "\e[38;5;129m"
# define PURPLE "\e[38;5;160m"
# define RED    "\e[38;5;160m"
# define WHITE "\e[38;5;15m"
# define LIGHT_BLUE "\e[38;5;117m"

typedef pthread_mutex_t t_mtx;
typedef struct s_data   t_data;

typedef enum e_status
{
    EATING,
    SLEEPING,
    THINKING,
    TAKE_FIRST_FORK,
    TAKE_SECOND_FORK,
    DIED,
}   t_philo_status;

typedef enum time_cd
{
    SECOND,
    MILLISEC,
    MICROSEC,
}   t_time_cd;

typedef struct s_fork
{
    t_mtx   fork;
    int     fork_id;
}   t_fork;

typedef struct s_philo
{
    int                     philo_id;
    long                    n_meals;
    bool                    satt;
    long                    t_last_meal;
	t_fork                  *fork_first;
	t_fork      			*fork_second;
	pthread_t               thread;
	t_data			        *data;
    t_mtx                   philo_mutex;
}	t_philo;

typedef struct s_data
{
	long		n_philos;
	long		t_die;
	long		t_eat;
	long		t_sleep;
	long		min_meals;
    bool        finish_sim;
    t_fork      *forks;
	t_philo     *philos;
    t_mtx       dt_mutex;
    t_mtx       print_mutex;
    pthread_t   monitor;
}	t_data;

/*control.c*/
void    dist_forks(t_philo *philo, t_fork *forks, int philo_pos);
bool    verify_sim_end(t_data *data);
void    *monitor_sim(void *data);

/*philo_cycle.c*/
void    *philo_cycle(void *arg);

/*philos_init.c*/
void	philos_init(t_data *data);
bool    init_data(t_data *data);

/*routine.c*/
void    think_routine(t_philo *philo, bool pre_sim);
void    *philo_routine(t_philo *philo);

/*simulation.c*/
void    stop_sim(t_data *data);
void    dinner_simulation(t_data *data);

/*utils_args.c*/
int     ft_error(char *str);
void    save_args(int argc, char **argv, t_data *data);
int     check_args(t_data *data);

/*utils_mutex.c*/
bool    get_bool(t_mtx *mutex, bool *val);
long    get_long(t_mtx *mutex, long *val);
void    set_bool(t_mtx *mutex, bool *dest, bool val);
void    set_long(t_mtx *mutex, long *dest, long val);

/*utils_routine.c*/
void    free_data(t_data *data);
void    print_status(t_philo_status status, t_philo *philo);

/*utils.c*/
int     ft_putstr_fd(char *str, int fd);
long    ft_atol(const char *nptr);
int     ft_is_digit(char c);
long    get_time(int time_cd);
void    ft_usleep(long msec, t_data *data);


#endif