/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:30:01 by aalannys          #+#    #+#             */
/*   Updated: 2022/01/29 19:32:37 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*free_char_arr(char **arr, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static	int	find_word_qty(char const *s, char del)
{
	int	qty;
	int	i;

	qty = 0;
	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == del)
			i++;
		if (i == 0 && s[i] != del)
			qty++;
		if (i > 0 && s[i] && s[i - 1] == del)
			qty++;
		if (s[i])
			i++;
	}
	return (qty);
}

static	size_t	word_len(char const *s, char del)
{
	size_t	w_len;

	w_len = 0;
	while (*s == del)
		s++;
	while (*s != '\0' && *s != del)
	{
		w_len++;
		s++;
	}
	return (w_len);
}

static	char	*copy_str(const char *s, size_t len)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = malloc(len + 1);
	while (i < len)
	{
		copy[i] = *s++;
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	size_t	str_qty;
	char	**char_arr;
	size_t	len;
	size_t	i;

	str_qty = find_word_qty(s, c);
	char_arr = (char **) malloc(sizeof(char *) * (str_qty + 1));
	if (!char_arr)
		return (NULL);
	char_arr[str_qty] = NULL;
	i = 0;
	while (i < str_qty)
	{
		while (*s == c && *s)
			s++;
		len = word_len(s, c);
		char_arr[i] = copy_str(s, len);
		if (!(char_arr[i]))
			return (free_char_arr(char_arr, i));
		s += len;
		i++;
	}
	return (char_arr);
}
