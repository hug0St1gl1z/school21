/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:58:09 by cblanca           #+#    #+#             */
/*   Updated: 2021/10/15 12:00:11 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* применяет функцию f к каждому символу строки s, переданной в качестве 
аргумента, указав ее индекс в качестве первого аргумента, чтобы создать 
«свежую» новую строку (с malloc), полученную в результате последовательного 
применения f. ft_strequ */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rtn;

	i = 0;
	if (!s || (!s && !f))
		return (0);
	else if (!f)
		return (ft_strdup(s));
	rtn = ft_strdup(s);
	if (!rtn)
		return (rtn = NULL);
	while (s[i])
	{
		rtn[i] = f(i, (char)s[i]);
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
