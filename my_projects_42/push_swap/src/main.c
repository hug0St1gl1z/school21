/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:38:14 by cblanca           #+#    #+#             */
/*   Updated: 2022/02/22 19:31:23 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**check_one_string(int *argc, char **argv, int *flag)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!ft_strrchr(argv[1], ' '))
	{
		*argc = 1;
		return (argv);
	}
	tmp = ft_split(argv[1], ' ');
	if (!tmp)
		return (0);
	while (tmp[i])
		i++;
	*argc = i;
	*flag = 1;
	return (tmp);
}

int	main(int argc, char **argv)
{
	int	flag;

	flag = 0;
	if (argc == 2)
		argv = check_one_string(&argc, argv, &flag);
	if (argc == 1 && !flag)
		exit(0);
	if (!flag)
	{
		argv++;
		argc--;
	}
	if (!check_args(argc, argv))
		warning(1, "Error\n");
	if (argc == 2 && check_if_not_final_sorted(argc, argv))
	{
		if (flag)
			free_mass(argc, argv);
		warning(0, "ra\n");
	}
	push_swap(argc, argv);
	if (flag)
		free_mass(argc, argv);
	return (0);
}
