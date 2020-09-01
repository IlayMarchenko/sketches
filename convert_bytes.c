#include "header.h"

char *convert_bytes(int size) {
    char *result = NULL;
    char *temp = NULL;
    if (size < 0 || size > 2147483647) {
        return result;
    }
    else if (size > 0 && size <= 1024) {
        return result;
    }
    else if (size > 1024 && size <= 1048576) {
        size /= 1024;
        result = mx_strnew(mx_intlen(size) + 1);
        temp = mx_itoa(size);
        result = mx_strcpy(result, temp);
        result = mx_strcat(result, "K");
    }
    else if (size > 1048576 && size <= 1073741824) {
        size /= 1048576;
        result = mx_strnew(mx_intlen(size) + 1);
        temp = mx_itoa(size);
        result = mx_strcpy(result, temp);
        result = mx_strcat(result, "M");
    }
    else {
        size /= 1073741824;
        result = mx_strnew(mx_intlen(size) + 1);
        temp = mx_itoa(size);
        result = mx_strcpy(result, temp);
        result = mx_strcat(result, "G");
    }
    mx_strdel(&temp);
    return result;
}