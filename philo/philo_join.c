/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:58:40 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/25 10:44:53 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "philo.h"
#include <stdlib.h>
#include <pthread.h>

void	philo_join(void)
{
	unsigned int	index;
	t_philo			*philo;

	index = 0;
	philo = (*philo_instance());
	while (index < input_instance()->n_philos)
	{
		pthread_join(philo->thread, NULL);
		index++;
	}
}
