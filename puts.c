// SPDX-License-Identifier: BSD-3-Clause

#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>

int puts(const char *str)
{
    const char *ptr = str;
    int str_len = 0;

    while (*ptr != '\0') {
        str_len++;
        ptr++;
    }

    ssize_t ret = write(1, str, str_len);
    write(1, "\n", 1);

    if (ret == (ssize_t)(str_len)) {
        return str_len;
    }

    return -1;
}
