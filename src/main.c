/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:29:51 by baguiar-          #+#    #+#             */
/*   Updated: 2024/09/18 11:03:08 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"
/* argv[1]: n. of philos,
 * argv[2]: time until philo dies,
 * argv[3]: time philo has to eat
 * argv[4]: time philo has to sleep,
 * argv[5]: (optional) how many meals each philo eats until the 
 * end of the simulation */
int	main(int argc, char **argv)
{
	t_data  data;

    if (argc != 5 && argc != 6)
        return (ft_error("Wrong number of args: ./philo + 4 or 5 args!\n"));
    save_args(argc, argv, &data);
    if (check_args(&data) == 1)
        return (1);
    init_data(&data);
    dinner_simulation(&data);
    free_data(&data);
    return (0);
}

