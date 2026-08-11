/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:41:49 by marvin            #+#    #+#             */
/*   Updated: 2026/05/04 12:41:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	ft_free(char **str, size_t j)
{
	while (j > 0)
	{
		j--;
		free(str[j]);
	}
	free(str);
}

static char	*ft_fillword(char const *s, char c, size_t *i)
{
	char	*word;
	size_t	len;
	size_t	k;

	while (s[*i] && s[*i] == c)
		(*i)++;
	len = ft_wordlen(s + *i, c);
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	k = 0;
	while (k < len)
		word[k++] = s[(*i)++];
	word[k] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	count;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	count = ft_wordcount(s, c);
	str = (char **)malloc((count + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count)
	{
		str[j] = ft_fillword(s, c, &i);
		if (!str[j])
		{
			ft_free(str, j);
			return (NULL);
		}
		j++;
	}
	str[j] = NULL;
	return (str);
}
/*
 1. split the string 's' into an array of strings using the character 'c'
  as a delimiter
 2. the array must end with a NULL pointer
 3. return the array of strings resulting from the split operation
 4. if the allocation fails, the function returns NULL
 */
/* #include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	**result;
	int		i;

	result = ft_split("hello world foo", ' ');
	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}	*/