int custom_strcmp(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) {
        return str1 == str2 ? 0 : str1 ? 1 : -1;
    }

    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }

    return *str1 - *str2;
}