/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:30:41 by aalannys          #+#    #+#             */
/*   Updated: 2021/10/12 16:34:53 by aalannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	*start;
	char	temp;

	start = str;
	len = 0;
	i = 0;
	while (*str)
	{
		len++;
		str++;
	}
	str--;
	while (i < (len / 2))
	{
		temp = start[i];
		start[i] = (*str);
		start[len - 1 - i] = temp;
		i++;
		str--;
	}
	return (start);
}
