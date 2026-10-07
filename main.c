#include "header_02.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_get_length(char *str);
int	ft_write_three_digits(char *str, char **str_dig_grp, int len);

int	ft_parse_string_three_digits(char *str_num, char ***str_dig_grp)
{
	int	len;

	len = ft_get_length(str_num);
	if (!(*str_dig_grp = malloc(sizeof(char *) * (len + 1))))
		return (0);
	if (!ft_write_three_digits(str_num, *str_dig_grp, len))
		return (0);
	return (1);
}

void	ft_write_str_num(char *in_str, char *str_num, int start, int end)
{
	int	i;

	i = 0;
	while (in_str[start] && start < end)
	{
		str_num[i] = in_str[start];
		i++;
		start++;
	}
	str_num[i] = '\0';
}

int	ft_atoi(char *in_str, char **str_num)
{
	int	i;
	int	len;
	int	start;

	i = 0;
	len = 0;
	while (in_str[i] && (in_str[i] == ' ' || (in_str[i] >= 9 && in_str[i] <=13)))
		i++;
	if (in_str[i] == '-')
		return (0);
	if (in_str[i] == '+')
		i++;
	start = i;
	while (in_str[i] && (in_str[i] >= '0' && in_str[i] <= '9'))
	{
		i++;
		len++;
	}
	if (!(*str_num = malloc(sizeof(char) * (len + 1))))
                        return (0);
	if (i > start)
	{
		ft_write_str_num(in_str, *str_num, start, i);
	}
	else
		return (0);
	return (1);
}

int	ft_check_input(int argc, char **argv, char **str_num, char **file_name)
{
	if (argc == 2)
	{
		if (!ft_atoi(argv[1], str_num))
		{	
			write (1, "Error\n", 6);
			return (0);
		}
		*file_name = "numbers.dict";
	}
	else if (argc == 3)
	{
		if (!ft_atoi(argv[2], str_num))
		{	
			write (1, "Error\n", 6);
			return (0);
		}
		*file_name = argv[1];
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*str_num;
	char	**str_dig_grp;
	char	*file_name;
	char	*dict_buffer;
	t_dict	*dict;

	if (!(argc > 1 && argc < 4))
	    write(1, "Error\n", 6);
	if (!ft_check_input(argc, argv, &str_num, &file_name))
		return (0);
	if (!ft_parse_string_three_digits(str_num, &str_dig_grp))
       		return (0);	
	dict_buffer = ft_read_file(file_name);
	if (!dict_buffer)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	dict = ft_create_dict(dict_buffer);
	free(dict_buffer);
	ft_process_numbers(str_dig_grp, dict);
	write(1, "\n", 1);
	free(dict);
	return (0);
}