/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:46:24 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/24 17:53:13 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_philo
{
	unsigned int	id;
	pthread_mutex_t	fork;
	struct s_philo	*prev;
	struct s_philo	*next;
	int				n_eat;
	char			checked;
	unsigned int	last_eat;
	pthread_t		thread;
}	t_philo;

void	philo_load(void);
void	philo_join(void);
void	*philo_life(void *arg);
t_philo	**philo_instance(void);

#endif