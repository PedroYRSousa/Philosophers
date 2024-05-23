/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:46:24 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/24 16:19:14 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# ifndef N_PHILOS
#  define N_PHILOS 1
# endif

# ifndef T_DIE
#  define T_DIE 2
# endif

# ifndef T_EAT
#  define T_EAT 3
# endif

# ifndef T_SLEEP
#  define T_SLEEP 4
# endif

# ifndef N_EAT
#  define N_EAT 5
# endif

typedef struct s_input
{
	int				n_eat;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	n_philos;
	unsigned int	start_time;
	char			to_continue;
}	t_input;

t_input	*input_instance(void);
char	input_valid_and_load(int argc, char **argv);

#endif