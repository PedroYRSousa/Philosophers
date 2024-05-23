/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:57:06 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/27 14:53:10 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"
#include "util.h"
#include "philo.h"
#include "input.h"
#include <pthread.h>

static char	get_fork(t_philo *philo, pthread_mutex_t *fork)
{
	if (pthread_mutex_lock(fork) != 0)
		return (FALSE);
	log_philo_fork(philo);
	return (TRUE);
}

static int	eat(t_philo *philo)
{
	if (get_fork(philo, &philo->fork))
	{
		if (!input_instance()->to_continue)
		{
			pthread_mutex_unlock(&philo->fork);
			return (1);
		}
		if (input_instance()->n_philos == 1)
		{
			pthread_mutex_unlock(&philo->fork);
			return (1);
		}
		if (get_fork(philo, &philo->next->fork))
		{
			log_philo_eat(philo);
			philo->last_eat = util_gettime(0);
			philo->n_eat++;
			util_sleep(input_instance()->t_eat);
			pthread_mutex_unlock(&philo->next->fork);
		}
		pthread_mutex_unlock(&philo->fork);
	}
	return (0);
}

static void	sleep(t_philo *philo)
{
	if (!input_instance()->to_continue)
		return ;
	log_philo_sleep(philo);
	util_sleep(input_instance()->t_sleep);
}

static void	think(t_philo *philo, unsigned int s_time)
{
	if (!input_instance()->to_continue)
		return ;
	log_philo_think(philo);
	util_sleep(s_time);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (input_instance()->start_time == 0)
		;
	if (philo->id % 2 == 1)
		think(philo, input_instance()->t_eat);
	while (input_instance()->to_continue)
	{
		if (eat(philo) && input_instance()->to_continue)
			break ;
		sleep(philo);
		think(philo, 0);
	}
	pthread_detach(philo->thread);
	return (NULL);
}
