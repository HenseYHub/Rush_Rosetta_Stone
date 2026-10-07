#ifndef HEADER_02_H
# define HEADER_02_H

typedef struct	s_dict
{
	char	*key;
	char	*value;
} t_dict;

char *ft_get_key(char *str);
int     ft_get_length(char *str);
int     ft_write_three_digits(char *str, char **str_dig_grp, int len);
char	*ft_read_file(char *file_name);
void	ft_process_numbers(char **str_dig_grp, t_dict *dict);
char    *ft_scale_key(int num_zero);
void    ft_print_word(char *name);
void	ft_putstr(char *name);
char	*ft_get_dict_val(t_dict *dict, char *key);
void    ft_print_three_digits(char *str, t_dict *dict);
t_dict	*ft_create_dict(char *buffer);
char	*ft_get_key(char *str);
char	*ft_get_value(char *str);
int	ft_count_lines(char *buffer);
#endif
