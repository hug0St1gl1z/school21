/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:28:23 by cblanca           #+#    #+#             */
/*   Updated: 2021/10/18 10:59:18 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* принимает массив и разделяет на массивы слова разделеные пробелами - 
выполняется с применением вспомогательных функций */

static size_t	ft_nbr(char const *s, char c)
{
	size_t	i;
	size_t	substr_len;
	size_t	counter;

	substr_len = 0;
	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && substr_len != 0)
		{
			++counter;
			substr_len = 0;
		}
		else if (s[i] != c)
		{
			++substr_len;
		}
		++i;
	}
	if (substr_len != 0)
		++counter;
	return (counter);
}

static char	**ft_free_all(char **result, size_t n)
{
	++n;
	while (n > 0)
	{
		--n;
		free(result[n]);
	}
	free(result);
	return (NULL);
}

static void	ft_string_writer(char const *s, char **result, char c)
{
	size_t	len;
	size_t	str_counter;
	size_t	i;

	i = 0;
	len = 0;
	str_counter = 0;
	while (s[i])
	{
		if (s[i] == c && len != 0)
		{
			result[str_counter][len] = 0;
			++str_counter;
			len = 0;
		}
		else if (s[i] != c)
		{
			result[str_counter][len] = s[i];
			++len;
			if (s[i + 1] == 0)
				result[str_counter][len] = 0;
		}
		++i;
	}
}

static char	**ft_arr_alloc(char const *s, char c)
{
	size_t	substr_nbr;
	char	**result;

	substr_nbr = ft_nbr(s, c);
	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (substr_nbr + 1));
	if (result == NULL)
		return (NULL);
	result[substr_nbr] = (char *)0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	str_counter;
	char	**result;

	i = 0;
	len = 0;
	str_counter = 0;
	result = ft_arr_alloc(s, c);
	if (!s || !result)
		return (NULL);
	while (s[i])
	{
		if ((s[i] == c && len != 0) || (s[i] != c && ++len && s[i + 1] == 0))
		{
			result[str_counter] = (char *)malloc(sizeof(char) * (len + 1));
			if (result[str_counter] == NULL)
				return (ft_free_all(result, str_counter));
			len = 0;
			++str_counter;
		}
		++i;
	}
	ft_string_writer(s, result, c);
	return (result);
}
