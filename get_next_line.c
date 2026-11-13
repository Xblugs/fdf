/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cczerwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:24:23 by cczerwin          #+#    #+#             */
/*   Updated: 2025/01/04 16:24:25 by cczerwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
void	*gnl_magic(char *line, char *buff, int fd, int *is_line);
void	*gnl_process(char *line, char *buff, int fd, int *is_line);
void	*gnl_newline(char *line, char *buff);
void	gnl_free(char *line, char *swap, char *buff);

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			is_line;

	line = NULL;
	is_line = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff[BUFFER_SIZE] = 0;
	line = gnl_magic(line, buff, fd, &is_line);
	return (line);
}

void	*gnl_magic(char *line, char *buff, int fd, int *is_line)
{
	if (buff[0] != 0)
	{
		if (ft_strchr((char *)buff, '\n') != 0)
		{
			line = gnl_newline(line, buff);
			if (line == NULL)
				return (NULL);
			*is_line = 1;
		}
		else
			line = ft_strdup(buff);
	}
	while (*is_line == 0)
	{
		line = gnl_process(line, buff, fd, is_line);
		if (line == NULL)
		{
			gnl_free(line, NULL, buff);
			return (NULL);
		}
		if (*is_line != 1)
			buff[0] = 0;
	}
	return (line);
}

void	*gnl_process(char *line, char *buff, int fd, int *is_line)
{
	int	count;

	count = read(fd, buff, BUFFER_SIZE);
	if (count == -1)
	{
		gnl_free(line, NULL, buff);
		return (NULL);
	}
	buff[count] = 0;
	if (count == 0)
	{
		*is_line = 1;
		return (line);
	}
	if (line == NULL && ft_strchr(buff, '\n') == 0)
		line = ft_strdup(buff);
	else if (ft_strchr(buff, '\n') != 0)
	{
		line = gnl_newline(line, buff);
		*is_line = 1;
	}
	else
		line = gnl_strjoin(line, buff, 1);
	return (line);
}

void	*gnl_newline(char *line, char *buff)
{
	char	*swap;

	swap = ft_strchr((char *)buff, '\n');
	swap = ft_strdup(&swap[1]);
	if (swap == NULL)
	{
		gnl_free(line, swap, buff);
		return (NULL);
	}
	buff[ft_strchr(buff, '\n') - buff + 1] = 0;
	if (line == NULL)
		line = ft_strdup(buff);
	else
		line = gnl_strjoin(line, buff, 1);
	if (line == NULL)
	{
		gnl_free(line, swap, buff);
		return (NULL);
	}
	ft_memcpy(buff, swap, ft_strlen(swap));
	buff[ft_strlen(swap)] = 0;
	free (swap);
	return (line);
}

void	gnl_free(char *line, char *swap, char *buff)
{
	if (line != NULL)
		free (line);
	if (swap != NULL)
		free (swap);
	buff[0] = 0;
}
/*
int	main(void)
{
	int		fd;
	char	*ret;

	//////////////////////////////////////////
	//	File			Content				//
	//////////////////////////////////////////
	//	test.txt		3 lines				//
	//	shortline.txt	3 char				//
	//	longline.txt	~20k pi decimals	//
	//	space.txt		1 space				//
	//	void.txt		empty file			//
	//	truevoid		empty file (echo -n)//
	//	test2			1 line (echo -n)	//
	//	test3			1 line 				//
	//	newline.txt		few '\n' in a row	//
	//	alternate.txt	alt '\n' and line	//
	//////////////////////////////////////////

	printf("\n-- test --\n");
	fd = open("test.txt", O_RDONLY);
	ret = get_next_line(fd);
	while (ret != NULL)
	{
		printf("%s", ret);
		free(ret);
		ret = NULL;
		ret = get_next_line(fd);
	}
	if (ret == NULL)
		printf("%s", ret);
	free(ret);
	ret = NULL;
	printf("\n-- Fin test --\n");
	close(fd);

	printf("\n-- short --\n");
	fd = open("shortline.txt", O_RDONLY);
	ret = get_next_line(fd);
	while (ret != NULL)
	{
		printf("%s", ret);
		free(ret);
		ret = get_next_line(fd);
	}
	if (ret == NULL)
		printf("%s", ret);
	free(ret);
	ret = NULL;
	printf("\n-- Fin test --\n");
	close(fd);

	printf("\n-- space --\n");
	fd = open("space.txt", O_RDONLY);
	ret = get_next_line(fd);
	while (ret != NULL)
	{
		printf("%s", ret);
		free(ret);
		ret = NULL;
		ret = get_next_line(fd);
	}
	if (ret == NULL)
		printf("%s", ret);
	free(ret);
	ret = NULL;
	printf("\n-- Fin test --\n");
	close(fd);

	printf("\n-- void --\n");
	fd = open("void.txt", O_RDONLY);
	ret = get_next_line(fd);
	while (ret != NULL)
	{
		printf("%s", ret);
		free(ret);
		ret = NULL;
		ret = get_next_line(fd);
	}
	if (ret == NULL)
		printf("%s", ret);
	free(ret);
	ret = NULL;
	printf("\n-- Fin test --\n");
	close(fd);

	printf("\n-- test2 --\n");
	fd = open("test2", O_RDONLY);
	ret = get_next_line(fd);
	while (ret != NULL)
	{
		printf("%s", ret);
		free(ret);
		ret = NULL;
		ret = get_next_line(fd);
	}
	if (ret == NULL)
		printf("%s", ret);
	free(ret);
	ret = NULL;
	printf("\n-- Fin test --\n");
	close(fd);

	printf("\n-- test3 --\n");
	fd = open("test3", O_RDONLY);
	ret = get_next_line(fd);
	while (ret != NULL)
	{
		printf("%s", ret);
		free(ret);
		ret = NULL;
		ret = get_next_line(fd);
	}
	if (ret == NULL)
		printf("%s", ret);
	free(ret);
	ret = NULL;
	printf("\n-- Fin test --\n");
	close(fd);

	printf("\n-- newline --\n");
	fd = open("newline.txt", O_RDONLY);
	ret = get_next_line(fd);
	while (ret != NULL)
	{
		printf("%s", ret);
		free(ret);
		ret = NULL;
		ret = get_next_line(fd);
	}
	if (ret == NULL)
		printf("%s", ret);
	free(ret);
	ret = NULL;
	printf("\n-- Fin test --\n");
	close(fd);

	printf("\n-- alternate --\n");
	fd = open("alternate.txt", O_RDONLY);
	ret = get_next_line(fd);
	while (ret != NULL)
	{
		printf("%s", ret);
		free(ret);
		ret = NULL;
		ret = get_next_line(fd);
	}
	if (ret == NULL)
		printf("%s", ret);
	free(ret);
	ret = NULL;
	printf("\n-- Fin test --\n");
	close(fd);

	return (0);
}*/
/*
int	main(void)
{
	int		fd;
	char	*ret;

	// longline.txt here because it's a really long line

	printf("\n-- mono test --\n");
	fd = open("longline.txt", O_RDONLY);

	ret = get_next_line(fd);
	while (ret != NULL)
	{
		printf("%s", ret);
		free(ret);
		ret = NULL;
		ret = get_next_line(fd);
	}
	if (ret == NULL)
		printf("%s", ret);
	free(ret);
	ret = NULL;

	printf("\n-- Fin test --\n");
	close(fd);

	return (0);
}*/
/*
int	main(void)
{
	int		fd;
	char	*ret;

	//////////////////////////////////////////
	//	File			Content				//
	//////////////////////////////////////////
	//	test.txt		3 lines				//
	//	shortline.txt	3 char				//
	//	longline.txt	~20k pi decimals	//
	//	space.txt		1 space				//
	//	void.txt		empty file			//
	//	truevoid		empty file (echo -n)//
	//	test2			1 line (echo -n)	//
	//	test3			1 line 				//
	//	newline.txt		few '\n' in a row	//
	//	alternate.txt	alt '\n' and line	//
	//////////////////////////////////////////

	printf("\n-- manual test --\n");
	fd = open("one_line_no_nl.txt", O_RDONLY);

	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);
	ret = NULL;

	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);
	ret = NULL;

	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);
	ret = NULL;

	printf("\n-- Fin test --\n");
	close(fd);

	return (0);
}*/
