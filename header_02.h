#ifndef HEADER_02_H
# define HEADER_02_H

typedef struct s_dict
{
    char *key;
    char *value;
} t_dict;

char *ft_get_key(char *str);

#endif