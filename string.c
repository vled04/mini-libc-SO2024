// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char *dest = destination;

	for (; *source != '\0'; source++, dest++)
		*dest = *source;
	*dest = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *dest = destination;
	int i = 0;
	for (i = 0; i < (int)len; source++, dest++, i++)
		*dest = *source;

	for (; i < (int)len; dest++, i++)
		*dest = '\0';

	return destination;
}

char *strcat(char *destination, const char *source)
{
	char *ptr;
	for (ptr = destination + strlen(destination); *source != '\0'; source++, ptr++)
		*ptr = *source;
	*ptr = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *ptr;
	int i;
	for (ptr = destination + strlen(destination), i = 0; *source != '\0' && i < (int)len; source++, ptr++, i++)
		*ptr = *source;
	*ptr = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	char *d1, *d2;
	for (d1 = (char *)str1, d2 = (char *)str2; *d1 != '\0' && *d2 != '\0'; d1++, d2++) {
		if (*d1 > *d2)
			return 1;
		else if (*d1 < *d2)
			return -1;
	}
	if (*d1 == '\0' && *d2 == '\0')
		return 0;
	else if (*d1 == '\0')
			return -1;
		 else
		 	return 1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	char *d1, *d2;
	int i;
	for (d1 = (char *)str1, d2 = (char *)str2, i = 0; *d1 != '\0' && *d2 != '\0' && i < (int)len; d1++, d2++, i++) {
		if (*d1 > *d2)
			return 1;
		else if (*d1 < *d2)
			return -1;
	}
	if (i == (int)len)
		return 0;
	else if (*d1 == '\0' && *d2 == '\0')
		return 0;
	else if (*d1 == '\0')
			return -1;
		 else
		 	return 1;
}

size_t strlen(const char *str)
{
	size_t i = 0;
	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	while (*str != '\0') {
		if (*str == c)
			return (char *)str;
		str++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	char const *last = NULL;
	while (*str != '\0') {
		if (*str == c)
			last = str;
		str++;
	}
	return (char *)last;
}

char *strstr(const char *haystack, const char *needle)
{
	char *d1, *d2;
	for (d1 = (char *)haystack; *d1 != '\0'; d1++) {
		char *clone_d1 = d1;

		for (d2 = (char *)needle; *d2 != '\0'; d2++) {
			if (*clone_d1 != *d2)
				break;
			clone_d1++;
		}
		if (*d2 == '\0')
			return d1;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
    char *dest1, *dest2;
    size_t needle_len = strlen(needle);
    size_t haystack_len = strlen(haystack);

    if (needle_len == 0)
        return (char *)haystack;

    for (dest1 = (char *)haystack + haystack_len - needle_len; dest1 >= (char *)haystack; dest1--) {
        for (dest2 = (char *)needle; *dest2 != '\0'; dest2++) {
            if (*(dest1 + (dest2 - needle)) != *dest2)
                break;
        }
        if (*dest2 == '\0')
            return dest1;
    }
    return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *dest1 = (char *)destination;
	char *dest2 = (char *)source;
	for (size_t i = 0; i < num; i++){
		*dest1 = *dest2;
		dest1++;
		dest2++;
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *dest1 = (char *)destination;
	char *dest2 = (char *)source;
	for (size_t i = 0; i < num; i++){
		*dest1 = *dest2;
		dest1++;
		dest2++;
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	char *dest1 = (char *)ptr1;
	char *dest2 = (char *)ptr2;

	for (size_t i = 0; i < num; i++) {
		if (*dest1 > *dest2)
			return 1;
		else if (*dest1 < *dest2)
			return -1;
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char *dest = (char *)source;

	for (size_t i = 0; i < num; i++) {
		*dest = value;
		dest++;
	}
	return source;
}
