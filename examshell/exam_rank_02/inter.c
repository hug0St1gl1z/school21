/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:28:15 by cblanca           #+#    #+#             */
/*   Updated: 2021/12/11 11:31:25 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}

void ft_inter(char *s1, char *s2)
{
	int i, j;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(s2, s1[i]) == 1)
		{
			j = i - 1;
			while (j >= -1)
			{
				if (s1[i] == s1[j])
					break ;
				else if (j == -1)
					write(1, &s1[i], 1);
				j--;
			}
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
}
