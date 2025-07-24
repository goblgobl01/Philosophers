/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:35:47 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/07/22 23:00:46 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (str[i] == '+' || str[i] == '-')
			return(0);
	}
	while(str[i])
	{
		if(!ft_isdigit(str[i]))
			return(0);
		i++;
	}
	return (1);
}

int	check_number(char *str)
{
	long long	res;

	if (!is_number(str))
		return (0);
	res = ft_atoi(str);
	if (res < 0 || res == LONG_MAX)
		return (0);
	return (res);
}

int	check_parameter(int ac, char **av, t_parameters *param)
{
	if (ac == 6)
	{
		if (!check_number(av[5]))
		{
			free(param);
			return (0);
		}
	}
	if (!check_number(av[1]) || !check_number(av[2]) || !check_number(av[3]) || !check_number(av[4]))
	{
		free(param);
		return (0);
	}
	return (1);
}

void	initialize_parameters(int ac, char **av, t_parameters *param)
{
	param->ac = ac;
	param->av = av;
	param->number_of_philosophers = ft_atoi(av[1]);
	param->time_to_die = ft_atoi(av[2]);
	param->time_to_eat = ft_atoi(av[3]);
	param->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		param->must_eat = ft_atoi(av[5]);
	else
		param->must_eat = -1;
}
