/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:18:57 by cblanca           #+#    #+#             */
/*   Updated: 2021/12/07 15:00:25 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int						i;
	static unsigned char	tab[256 + 127];

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (!tab[(unsigned char)argv[1][i]])
			{
				tab[(unsigned char)argv[1][i]] = 1;
				write(1, &argv[1][i], 1);
			}
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if (!tab[(unsigned char)argv[2][i]])
			{
				tab[(unsigned char)argv[2][i]] = 1;
				write(1, &argv[2][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}

