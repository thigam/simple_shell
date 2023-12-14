#include "main.h"

void path_handler(char *input)
{
    char holder[10];
    char standard[70] = "/bin/";
    int i = 0;
    while (i < 5)
    {
        holder[i] = input[i];
        i++;
    }
    holder[i] = '\0';

    if (_strcmp(standard, holder) == 0) 
        return;
    else
    {
        _strcat(standard, input);
        _strcpy(input, standard); 
    }
}
