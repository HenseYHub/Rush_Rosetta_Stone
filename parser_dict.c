#include "header_02.h"
#include <stdlib.h>

int ft_separator(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        if (str[i] == ':')
            return (i);
        
        i++;
    }

    return (-1);
}

char *ft_get_key(char *str)
{
    int i;
    int separator;
    int key_len;
    int start;
    char *key;
    
    separator = ft_separator(str);
    if (separator == -1)
        return (NULL);  
    start = 0;
    while(str[start] ==  ' ' || str[start] == '\t')
	    start++;

    key_len = separator;
    while (key_len > start && (str[key_len - 1] == ' ' || str[key_len - 1] == '\t' ))
        key_len--;
    key = malloc(key_len - start + 1);
    if (key == NULL)
        return (NULL);
    
    i = 0;
    while(start < key_len)
    {
        key[i] = str[start];
        i++;
	start++;
    }
    key[i] = '\0';
    return(key);
}

char *ft_get_value(char *str)
{
	int i;
	int start;
	int len;
	int separator;
	char *value;

	separator = ft_separator(str);
	if (separator == -1)
		return (NULL);
	start = separator + 1;
	while(str[start] == ' ' || str[start] == '\t')
		start++;
	len = 0;
	while (str[start + len] && str[start + len] != '\n')
		len++;
	while (len > 0 && (str[start + len - 1] == ' ' || str[start + len - 1] == '\t'))
	len--;
	value = malloc(len + 1);
	if (value == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		value[i] = str[start + i];
		i++;
	}
	value[i] = '\0';
	return (value);
}