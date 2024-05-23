/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:46:24 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/24 17:31:16 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

int				util_isdigit(int c);
int				util_atoi(const char *nptr);
void			util_sleep(unsigned int time);
unsigned int	util_gettime(unsigned int s_time);
char			util_consume_time(unsigned int time, long *life);

#endif