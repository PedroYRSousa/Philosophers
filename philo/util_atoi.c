/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:34:49 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/24 12:10:57 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <stdlib.h>

static const char	*get_final_ptr(const char *nptr)
{
	char	was_found;

	if (!nptr)
		return (NULL);
	was_found = FALSE;
	while (util_isdigit(*nptr))
	{
		nptr++;
		was_found = TRUE;
	}
	if (was_found)
		return (--nptr);
	else
		return (NULL);
}

static int	str_to_number(const char *i_str, const char *f_str, int *is_neg)
{
	int					decimal;
	unsigned long long	output;

	if (!f_str || !i_str)
		return (0);
	decimal = 1;
	output = 0;
	while ((&(*i_str) - 1) != &(*f_str))
	{
		output = output + ((*(f_str--) - '0') * decimal);
		decimal = decimal * 10;
	}
	if (output > 2147483647L && !(*is_neg))
	{
		*is_neg = FALSE;
		return (-1);
	}
	if (output > 2147483648L && *is_neg)
	{
		*is_neg = FALSE;
		return (0);
	}
	return ((int)output);
}

static const char	*is_valid(const char *nptr)
{
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (util_isdigit(*nptr)
		|| (*nptr == '-' && util_isdigit(*(nptr + 1)))
		|| (*nptr == '+' && util_isdigit(*(nptr + 1))))
		return (nptr);
	else
		return (NULL);
}

int	util_atoi(const char *nptr)
{
	int	is_negative;

	if (!nptr)
		is_negative = nptr[0];
	nptr = is_valid(nptr);
	if (!nptr)
		return (0);
	is_negative = FALSE;
	if (!util_isdigit(*nptr))
	{
		if (*nptr == '-')
			is_negative = TRUE;
		nptr++;
	}
	if (is_negative)
		return (str_to_number(nptr, get_final_ptr(nptr), &is_negative) * -1);
	else
		return (str_to_number(nptr, get_final_ptr(nptr), &is_negative));
}
