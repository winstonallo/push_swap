/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:44:38 by codespace         #+#    #+#             */
/*   Updated: 2023/10/01 11:17:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//check for duplicates
static int	dups(char **arr, int argc)
{
	int		i;
	int		j;
	long	temp;

	i = -1;
	if (argc > 2)
		i++;
	while (arr[++i])
	{
		temp = ft_atoi(arr[i]);
		if (temp == 0 && arr[i][0] != '0')
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
		j = i;
		while (arr[++j])
		{
			if (temp == ft_atoi(arr[j]))
				return (ft_putendl_fd("Error", 2), 1);
		}
	}
	return (0);
}

//check for non digit characters/if there is at least one number (ex: ./push_swap "    ")
static int	d(char **a, int argc)
{
	int	i;
	int	j;
	int	digit;

	if (!a || *a == NULL)
		return (ft_putendl_fd("Error", 2), 1);
	digit = 1;
	i = -1;
	if (argc > 2)
		i++;
	while (a[++i])
	{
		j = -1;
		while (a[i][++j])
		{
			if (!ft_isdigit(a[i][j]) && a[i][j] != '-' && a[i][j] != '+')
			{
				digit = 0;
				break ;
			}
		}
	}
	if (digit == 0)
		return (ft_putendl_fd("Error", 2), 1);
	return (0);
}

//check for invalid -/+ positioning
static int	signcheck(char **a)
{
	int	i;
	int	j;

	i = -1;
	while (a[++i])
	{
		j = -1;
		while (a[i][++j])
		{
			if (a[i][j] != ' '
					&& ((a[i][j + 1]) == '+' || (a[i][j + 1]) == '-'))
			{
				ft_putendl_fd("Error", 2);
				return (1);
			}
			if ((a[i][j] == '-' || a[i][j] == '+') && !ft_isdigit(a[i][j + 1]))
			{
				ft_putendl_fd("Error", 2);
				return (1);
			}
		}
	}
	return (0);
}

//check for integer overflow
static int	ofcheck(char **arr)
{
	long	temp;
	int		i;

	i = -1;
	while (arr[++i])
	{
		temp = ft_atoi(arr[i]);
		if (temp > 2147483647 || temp < -2147483648)
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
		if (!arr[i][0])
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
	}
	return (0);
}

void	ft_check_input(char **argv, int argc)
{
	char	**arr;

	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (!arr)
			return ;
	}
	else
		arr = argv;
	if (signcheck(arr) || d(arr, argc) || dups(arr, argc) || ofcheck(arr))
	{
		if (argc == 2)
			ft_free_array(arr);
		exit (1);
	}
	if (argc == 2)
		ft_free_array(arr);
}
