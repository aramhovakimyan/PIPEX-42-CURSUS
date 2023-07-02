/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:10:46 by ahovakim          #+#    #+#             */
/*   Updated: 2023/06/25 17:10:10 by ahovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	num_words(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			n++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n);
}

static int	word_len(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s == c)
		s++;
	while (*s && *s != c)
	{
		cnt++;
		s++;
	}
	return (cnt);
}

static char	**helper(char **res, char const *s, char c)
{
	int	i;
	int	j;
	int	k;
	int	n;

	i = -1;
	j = 0;
	n = num_words(s, c);
	while (++i < n)
	{	
		k = 0;
		res[i] = (char *)malloc(word_len(&s[j], c) + 1);
		if (!res[i])
			res[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			res[i][k++] = s[j++];
		res[i][k] = '\0';
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (num_words(s, c) + 1));
	if (!res)
		return (NULL);
	return (helper(res, s, c));
}
