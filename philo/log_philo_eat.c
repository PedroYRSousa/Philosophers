/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_philo_eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:46:35 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/27 14:49:28 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "philo.h"
#include "input.h"
#include <stdio.h>

void	log_philo_eat(t_philo *philo)
{
	if (input_instance()->to_continue)
		printf("%u %u is eating\n",
			util_gettime(input_instance()->start_time), philo->id + 1);
}
