/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozbakir <yozbakir@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:35:43 by yozbakir          #+#    #+#             */
/*   Updated: 2023/10/22 13:08:05 by yozbakir          ###   ########.tr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**zero_list(void)
{
	char	**result;

	result = (char **)malloc(sizeof(char *));
	if (!result)
		return (0);
	*result = 0;
	return (result);
}

size_t	dlm_count(char const *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		count += *str != 0;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

size_t	strlenchr(char const *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	size_t	el_size;
	char	**result;

	if (!s || !*s)
		return (zero_list());
	result = (char **)malloc(sizeof(char *) * (dlm_count(s, c) + 1));
	if (!result)
		return (result);
	index = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		el_size = strlenchr(s, c);
		if (el_size)
		{
			result[index++] = ft_substr(s, 0, el_size);
			if (!result[index - 1])
				return (0);
		}
		s += el_size;
	}
	result[index] = 0;
	return (result);
}
