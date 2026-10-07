#include <stdlib.h>
#include <unistd.h>
#include "header_02.h"

int	ft_write_three_digits(char *str_num, char **str_dig_grp, int len)
{
	int	i;
	int	j;
        int	k;

	i = 2;
	j = 0;
	while (len > 0)
	{
		if (!(str_dig_grp[j] = malloc(sizeof(char) * 4)))
			return (0);
		k = 0;
	while (i >= 0)
	{
	if (len - 1 - i >= 0)
		str_dig_grp[j][k] = str_num[len - 1 - i];
	else
		str_dig_grp[j][k] = '0';
	i--;
	k++;
	}
	str_dig_grp[j][k] = '\0';
	j++;
	len = len - 3;
	i = 2;
		
	}
	str_dig_grp[j] = NULL;
	return (1);
}

int	ft_get_length(char *str_num)
{
	int	i;

	i = 0;
	while (str_num[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	if (str)
		write(1, str, ft_get_length(str));
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_get_dict_val(t_dict *dict, char *key)
{
	int	i;

	i = 0;
	while (dict[i].key)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
			return (dict[i].value);
		i++;
	}
	return (0);
}