#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "header_02.h"

int ft_file_size(char *file_name)
{
	int fd;
	int total;
	char buff[100];
	int bytes_read;

	fd = open(file_name, O_RDONLY);
	if (fd == 1)
		return (-1);
	total = 0;
	bytes_read  = read(fd, buff, 100);
	while (bytes_read > 0)
	{
		total += bytes_read;
		bytes_read = read(fd, buff, 100);
	}
	close(fd);
	if (bytes_read == -1)
		return (-1);
	return (total);
}
char *ft_read_file(char *file_name)
{
	int fd;
	int file_size;
	int bytes_read;
	char *buffer;

	file_size = ft_file_size(file_name);
	if (file_size < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (file_size + 1));
	if (buffer == NULL)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (NULL);
	}

	bytes_read = read(fd, buffer, file_size);
	if (bytes_read < 0)
	{
		close(fd);
		free(buffer);
		return (NULL);
	}

	buffer[bytes_read] = '\0';
	close (fd);
	return(buffer);

}
int ft_count_lines(char *buffer)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(buffer[i])
	{
		if (buffer[i] == '\n')
			count ++;
	i++;
	}
	return (count);
}

t_dict *ft_create_dict(char *buffer)
{
	t_dict *dict;
	int count;
	int i;
	int line;
    count = ft_count_lines(buffer);
	dict = malloc(sizeof(t_dict) * count);
	if (dict == NULL)
		return(NULL);
	i = 0;
	line = 0;
	while (line < count)
	{
		dict[line].key = ft_get_key(&buffer[i]);
		dict[line].value = ft_get_value(&buffer[i]);
		while(buffer[i] && buffer[i] != '\n')
			i++;
		if (buffer[i] == '\n')
			i++;
		line++;
	}
	return (dict);
}
