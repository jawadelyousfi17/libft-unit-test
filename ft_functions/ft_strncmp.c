#include <string.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t index;

    index = 0;
    while (s1[index] && s2[index] == s1[index] && index < n - 1)
    {
        index++;
    }
    return (s1[index] - s2[index]);
}
