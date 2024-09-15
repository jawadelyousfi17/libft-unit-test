#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t index;
    size_t little_len;
    
    if (*little == '\0')
        return ((char *)big);
    little_len = ft_strlen(little);
    if (little_len > len)
        return (NULL);
    index = 0;
    while (*big && index <= len - little_len)
    {
       if (*big == *little && ft_strncmp(big, little, little_len) == 0)
            return ((char*) big);
       big++;
       index++;
    }
    return (0);
}
