#include "header_02.h"
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    char *key;

    key = ft_get_key("100  : hundred");
    if (key == NULL)
        return (1);
    write(1, key, 3);
    write(1, "\n", 1);

    free(key);
    return (0);
}