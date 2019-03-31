/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:38:09 by calamber          #+#    #+#             */
/*   Updated: 2019/03/24 10:20:15 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int				strchr_int(const char *s, int c)
{
	int			i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

int				read_and_combine(const int fd, char **files)
{
	char		*temp;
	char		*old;

	temp = ft_strdup(files[fd]);
	free(files[fd]);
	files[fd] = (char*)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	if (read(fd, files[fd], BUFF_SIZE) == 0)
	{
		free(files[fd]);
		files[fd] = ft_strdup(temp);
		return (0);
	}
	old = ft_strjoin(temp, files[fd]);
	free(temp);
	free(files[fd]);
	files[fd] = ft_strdup(old);
	free(old);
	return (1);
}

int				takefrombuffer(const int fd, int n, char **files, char **line)
{
	char		*swap2;

	if (n >= 0)
	{
		*line = ft_strndup(files[fd], n);
		swap2 = ft_strsub(files[fd], n + 1, (ft_strlen(files[fd]) - n));
		free(files[fd]);
		files[fd] = swap2;
		return (1);
	}
	return (0);
}

int				firstread(const int fd, char **line, char **files)
{
	int			n;

	files[fd] = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	if (read(fd, files[fd], BUFF_SIZE) < 1)
	{
		free(files[fd]);
		if (read(fd, files[fd], 0) < 0)
			return (-1);
		return (0);
	}
	n = strchr_int(files[fd], 10);
	if (n >= 0)
		return (takefrombuffer(fd, n, files, line));
	else
	{
		while (read_and_combine(fd, files) == 1)
		{
			n = strchr_int(files[fd], 10);
			if (takefrombuffer(fd, n, files, line) == 1)
				return (1);
		}
		if ((read_and_combine(fd, files) == 0) && (ft_strlen(files[fd]) > 0))
			return (takefrombuffer(fd, ft_strlen(files[fd]), files, line));
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*files[256];
	int			n;

	if (fd < 0 || fd > 256)
		return (-1);
	if (files[fd])
	{
		n = strchr_int(files[fd], 10);
		if (takefrombuffer(fd, n, files, line) == 1)
			return (1);
		else
		{
			while (read_and_combine(fd, files) == 1)
			{
				n = strchr_int(files[fd], 10);
				if (takefrombuffer(fd, n, files, line) == 1)
					return (1);
			}
			if ((read_and_combine(fd, files) == 0) &&
					(ft_strlen(files[fd]) > 0))
				return (takefrombuffer(fd, ft_strlen(files[fd]), files, line));
		}
	}
	return (firstread(fd, line, files));
}
*/


int		ft_new_line(char **s, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		tmp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[255];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_new_line(s, line, fd, ret));
}
