/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_gettime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:02:15 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/03/24 14:15:45 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <sys/time.h>
#include <stdlib.h>

unsigned int	util_gettime(unsigned int s_time)
{
	struct timeval	date;
	unsigned int	time;

	gettimeofday(&date, NULL);
	time = (((date.tv_sec * 1000) + (date.tv_usec / 1000)) - s_time);
	return (time);
}
