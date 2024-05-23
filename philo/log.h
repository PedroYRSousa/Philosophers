/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:14:28 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/24 15:46:05 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include "philo.h"

void	log_error_input(void);

void	log_philo_eat(t_philo *philo);
void	log_philo_die(t_philo *philo);
void	log_philo_fork(t_philo *philo);
void	log_philo_sleep(t_philo *philo);
void	log_philo_think(t_philo *philo);

#endif