/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_error_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:28:18 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/24 12:30:49 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"
#include <stdio.h>

void	log_error_input(void)
{
	printf("Error input: Please use: ");
	printf("number_of_philosophers ");
	printf("time_to_die ");
	printf("time_to_eat ");
	printf("time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
}
