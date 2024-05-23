/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:01:16 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/24 17:56:12 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "philo.h"
#include "input.h"
#include <stdlib.h>

static t_philo	*philo_create(void)
{
	t_philo	*new_philo;

	new_philo = (t_philo *)malloc(sizeof(t_philo));
	new_philo->id = 0;
	new_philo->n_eat = 0;
	new_philo->last_eat = 0;
	new_philo->next = new_philo;
	new_philo->prev = new_philo;
	new_philo->checked = FALSE;
	pthread_mutex_init(&new_philo->fork, NULL);
	return (new_philo);
}

static void	philo_add(t_philo *new_philo)
{
	t_philo	*prev_philo;

	if (!(*philo_instance()))
	{
		(*philo_instance()) = new_philo;
		(*philo_instance())->id = 0;
	}
	else
	{
		prev_philo = (*philo_instance())->prev;
		(*philo_instance())->prev = new_philo;
		new_philo->next = prev_philo->next;
		prev_philo->next = new_philo;
		new_philo->prev = prev_philo;
		new_philo->id = prev_philo->id + 1;
	}
	pthread_create(&new_philo->thread, NULL, &philo_life, new_philo);
}

void	philo_load(void)
{
	unsigned int	index;

	index = 0;
	while (index < input_instance()->n_philos)
	{
		philo_add(philo_create());
		index++;
	}
}
