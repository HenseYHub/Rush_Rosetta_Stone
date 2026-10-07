#include "header_02.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_get_count(char **str_grp)
{
	int	i;

	i = 0;
	while (str_grp[i])
		i++;
	return (i);
}

void	ft_process_numbers(char **str_grp, t_dict *dict)
{
	int	i;
	int	grp_count;
	char	*scale_key;

	if (str_grp[0][3] == '0' && str_grp[0][1] == '0' && str_grp[0][2] == '0'
			&& !str_grp[1])
        {
                ft_print_word(ft_get_dict_val(dict, "0"));
                return;
        }

    grp_count = ft_get_count(str_grp);
	i = grp_count - 1;
	while (str_grp[i] && i >= 0)
	{
		if (str_grp[i][0] != '0' || str_grp[i][1] != '0'
				|| str_grp[i][2] != '0')
		{
			ft_print_three_digits(str_grp[i], dict);
			if (i > 0)
			{
				scale_key = ft_scale_key((i) * 3);
				ft_print_word(ft_get_dict_val(dict, scale_key));
				free(scale_key);
			}
		}
		i--;
    }
}

void	ft_print_three_digits(char *str, t_dict *dict)
{
	int	n1;
	int	n2;
	int	n3;
	char	c1[2];
	char	c2[3];
	char	c3[2];

	n1 = (str[0] > '0') ? str[0] - '0' : 0;
	n2 = (str[1] > '0') ? str[1] - '0' : 0;
	n3 = (str[2] > '0') ? str[2] - '0' : 0;
//write Hundreds
	if (n1 > 0)
	{
		c1[0] = n1 + '0';
		c1[1] = '\0';
		ft_print_word(ft_get_dict_val(dict, c1));
		ft_print_word(ft_get_dict_val(dict, "100"));
	}
	if (n2 == 1)
	{
		c2[0] = n2 + '0';
		c2[1] = n3 + '0';
		c2[2] = '\0';
		ft_print_word(ft_get_dict_val(dict, c2));
	}
	else
	{
		if (n2 > 1)
		{
			c2[0] = n2 + '0';
			c2[1] = '0';
			c2[2] = '\0';
			ft_print_word(ft_get_dict_val(dict, c2));
		}
        if (n3 > 0)
		{
			c3[0] = n3 + '0';
			c3[1] = '\0';
			ft_print_word(ft_get_dict_val(dict, c3));
		}
	}
}
void	ft_print_word(char *name)
{
	if (!name)
		return;
	ft_putstr(name);
	write(1, " ", 1);
}

char	*ft_scale_key(int num_zero)
{
	char	*key;
	int	i;

	if (!(key = malloc(sizeof(char) * (num_zero + 2))))
		return(0);
	key[0] = '1';
	i = 1;
	while (i <= num_zero)
	{
		key[i] = '0';
		i++;
	}
	key[num_zero + 1] = '\0';
	return (key);
}
