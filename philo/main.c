/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:44:38 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/27 14:53:19 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"
#include "util.h"
#include "input.h"
#include "philo.h"
#include <unistd.h>
#include <stdlib.h>

static void	clear_philo(void)
{
	unsigned int	index;
	t_philo			*philo;

	index = 0;
	while (index < input_instance()->n_philos)
	{
		philo = (*philo_instance());
		(*philo_instance()) = philo->next;
		pthread_mutex_destroy(&philo->fork);
		free(philo);
		index++;
	}
}

static void	init_last_eat(t_philo *philos)
{
	unsigned int	index;
	unsigned int	last_eat;

	index = 0;
	last_eat = util_gettime(0);
	while (index < input_instance()->n_philos)
	{
		philos->last_eat = last_eat;
		philos = philos->next;
		index++;
	}
}

static void	supervisor(void)
{
	t_philo			*philos;
	unsigned int	max_eat;

	max_eat = 0;
	philos = (*philo_instance());
	init_last_eat(philos);
	input_instance()->start_time = util_gettime(0);
	while (input_instance()->to_continue)
	{
		if (util_gettime(philos->last_eat) > input_instance()->t_die)
		{
			input_instance()->to_continue = FALSE;
			log_philo_die(philos);
		}
		if (philos->n_eat == input_instance()->n_eat
			&& input_instance()->n_eat >= 0
			&& !philos->checked)
		{
			max_eat++;
			philos->checked = TRUE;
		}
		if (max_eat == input_instance()->n_philos)
			input_instance()->to_continue = FALSE;
		philos = philos->next;
	}
}

int	main(int argc, char **argv)
{
	if (!input_valid_and_load(argc, argv))
		return (0);
	if (input_instance()->n_philos > 0)
	{
		philo_load();
		util_sleep(1 * 500);
		supervisor();
		util_sleep(1 * 500);
		philo_join();
		clear_philo();
	}
	return (0);
}
