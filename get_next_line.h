/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:24:31 by nam               #+#    #+#             */
/*   Updated: 2020/04/03 20:41:00 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s1, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);

void			ft_free(char **buf);

int				get_next_line(int fd, char **line);

#endif
