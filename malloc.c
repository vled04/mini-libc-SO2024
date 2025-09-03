// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void *ret = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (ret == MAP_FAILED) {
		return NULL;
	}

	mem_list_add(ret, size);
	return ret;
}

void *calloc(size_t nmemb, size_t size)
{
	void *ret = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (ret == MAP_FAILED) {
		return NULL;
	}

	mem_list_add(ret, nmemb * size);
	return ret;
}

void free(void *ptr)
{
	if (!ptr) {
		return;
	}

	struct mem_list *struc = mem_list_find(ptr);

	if (!struc) {
		return;
	}

	munmap(struc->start, struc->len);
	mem_list_del(struc->start);
}

void *realloc(void *ptr, size_t size)
{
    void *ret = malloc(size);
    if (ret == NULL) {
        return NULL;
    }
    if (ptr != NULL) {
        memcpy(ret, ptr, size);
        free(ptr);
    }
    mem_list_add(ret, size);
    return ret;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    size_t total_size = nmemb * size;
    void *ret = malloc(total_size);
    if (ret == NULL) {
        return NULL;
    }
    if (ptr != NULL) {
        memcpy(ret, ptr, total_size);
        free(ptr);
    }
    mem_list_add(ret, total_size);
    return ret;
}
