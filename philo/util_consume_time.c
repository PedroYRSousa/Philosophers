/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_consume_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:28:25 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/24 17:31:10 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

char	util_consume_time(unsigned int time, long *life)
{
	while (time > 0)
	{
		util_sleep(1);
		if ((*life) == 0)
			return (FALSE);
		(*life)--;
		time--;
	}
	return (TRUE);
}
