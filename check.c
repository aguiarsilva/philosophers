/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:21 by baguiar-          #+#    #+#             */
/*   Updated: 2024/09/04 14:08:21 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int      valid_argc(int argc)
{
    if (argc != 5 && argc != 6)
    {
        write(1, "Error! Usage: ", 14);
        write(1, "[num_of_philos] ", 16);
        write(1, "[time_to_die] ", 14);
        write(1, "[eat_time] ", 11);
        write(1, "[sleep_time] ", 13);
        write(1, "[num_of_times_philos_must_eat] ", 31);
        return(EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

static int      valid_argv(char **argv)
{
    int i;
    int j;

    i = 1;
    while (argv[i])
    {
        j = 0;
        while(argv[i][j])
        {
            if (argv[i][j] >= '0' && argv[i][j] <= '9')
                j++;
            else
            {
                write(1, "Enter a valid number\n", 21);
                return (EXIT_FAILURE);
            }
        }
        if (ft_atoi(argv[i]) == -1)
        {
            write(1, "Enter number between MIN_INT - MAX_INT\n", 39);
            return (EXIT_FAILURE);
        }
        i++;
    }
    return (EXIT_SUCCESS);
}

int     valid_args(int argc, char **argv)
{
    if (valid_argc(argc) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (valid_argv(argv) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
