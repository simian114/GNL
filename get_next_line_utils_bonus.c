/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:13:55 by nam               #+#    #+#             */
/*   Updated: 2020/04/03 20:40:33 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(const char *s)
{
	int			i;
	size_t		len;
	char		*ret;
	char		*cp;

	i = -1;
	cp = (char *)s;
	len = ft_strlen(cp);
	if (len == 0)
		return (0);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	while (cp[++i])
		ret[i] = cp[i];
	ret[i] = 0;
	return (ret);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*ret;
	char		*cp;
	size_t		len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ret[len] = 0;
	cp = ret;
	while (*s1)
		*cp++ = *s1++;
	while (*s2)
		*cp++ = *s2++;
	return (ret);
}

char		*ft_strchr(const char *s1, int c)
{
	char	*cp;

	cp = (char *)s1;
	while (*cp && *cp != c)
		cp++;
	if (*cp == c)
		return (cp);
	return (0);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	char			*cp;
	char			*cp2;
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (i <= start || len == 0 || !(*s))
	{
		*ret = 0;
		return (ret);
	}
	cp = ret;
	cp2 = (char *)&s[start];
	while (*cp2 && len--)
		*cp++ = *cp2++;
	*cp = 0;
	return (ret);
}
