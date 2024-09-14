#include <stdlib.h>

int _len(const char *s)
{
    int size;

    size = 0;
    while (s[size])
    {
        size++;
    }
    return size;
    
}
 char *ft_strdup(const char *s)
 {
    int size;
    int index;
    char *new_s;

    size = _len(s);
    new_s = (char*)malloc((sizeof(char) * (size + 1)));
    if (!new_s)
    {
        return (0);
    }
    index = 0;
    while (index < size )
    {
        new_s[index] = s[index];
        index++;
    }
    new_s[index] = '\0';
    return (new_s);
 }