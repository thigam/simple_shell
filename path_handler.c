#include "main.h"

void path_handler(char *input)
{
    char holder[70];
    char standard[70] = "/bin/";
    int i = 0;
    while (i < 5)
    {
        holder[i] = input[i];
        i++;
    }
    holder[i] = '\0';

    if (strcmp(standard, holder) == 0)
        return;
    else
    {
        strcat(standard, input);
        strcpy(input, standard);
    }
}
