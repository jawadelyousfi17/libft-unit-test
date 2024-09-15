#include <string.h>
#include "libft.h"


size_t ft_strlcat(char *dst, const char *src, size_t dstsize) {
    size_t dst_len = ft_strlen(dst);
    size_t src_len = ft_strlen(src);
    size_t i;

    if (dstsize <= dst_len) {
        return (dstsize + src_len);  // Not enough space in dst
    }
    i = 0;
    while (i < (dstsize - dst_len - 1) && src[i] != '\0') {
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0';  // Null-terminate the result

    return (dst_len + src_len);
}
