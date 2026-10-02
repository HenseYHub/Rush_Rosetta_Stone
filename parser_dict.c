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
    char *key;
    
    separator = ft_separator(str);
    if (separator == -1)
        return (NULL);    
    key_len = separator;
    while(key_len > 0 && str[key_len - 1] == ' ')
    {
        key_len--;
    }
    key = malloc(key_len + 1);
    if(key == NULL)
        return (NULL);
    
    i = 0;
    while(i < key_len)
    {
        key[i] = str[i];
        i++;
    }
    key[i] = '\0';
    return(key);
}