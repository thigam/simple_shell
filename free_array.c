#include "main.h"

void free_array(char **a)
{
    int i = 0;

    for (i = 0; a[i] != NULL; i++)
    {
        free(a[i]);
    }

    free(a);
}
