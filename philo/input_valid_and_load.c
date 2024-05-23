/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid_and_load.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:06:48 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/24 16:19:33 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"
#include "util.h"
#include "input.h"

static void	set_input(char *str, int index)
{
	if (index == N_PHILOS)
		input_instance()->n_philos = util_atoi(str);
	if (index == T_DIE)
		input_instance()->t_die = util_atoi(str);
	if (index == T_EAT)
		input_instance()->t_eat = util_atoi(str);
	if (index == T_SLEEP)
		input_instance()->t_sleep = util_atoi(str);
	if (index == N_EAT)
		input_instance()->n_eat = util_atoi(str);
}

static char	valid_string(char *str)
{
	while ((*str))
	{
		if (!util_isdigit((*str)))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

char	input_valid_and_load(int argc, char **argv)
{
	int	index;

	input_instance()->n_eat = -1;
	input_instance()->start_time = 0;
	input_instance()->to_continue = TRUE;
	if (argc < 5 || argc > 6)
	{
		log_error_input();
		return (FALSE);
	}
	index = 1;
	while (index < argc)
	{
		if (!valid_string(argv[index]))
		{
			log_error_input();
			return (FALSE);
		}
		set_input(argv[index], index);
		index++;
	}
	return (TRUE);
}
