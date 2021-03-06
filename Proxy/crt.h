// ReSharper disable CppClangTidyReadabilityRedundantDeclaration
// ReSharper disable IdentifierTypo
/*
 * Custom implementation for common C runtime functions
 * This makes the DLL essentially freestanding on Windows without having to rely on msvcrt.dll
 */
#pragma once

HANDLE h_heap;

#define STR_LEN(str) (sizeof(str) / sizeof((str)[0]))

inline wchar_t *wmemcpy(wchar_t *dst, const wchar_t *src, size_t n) {
    wchar_t *d = dst;
    const wchar_t *s = src;
    while (n--)
        *d++ = *s++;
    return dst;
}

inline void *wmemset(wchar_t *dst, wchar_t c, size_t n) {
    wchar_t *d = dst;
    while (n--)
        *d++ = c;
    return dst;
}

extern void *memset(void *dst, int c, size_t n);
#pragma intrinsic(memset)

extern void *memcpy(void *dst, const void *src, size_t n);
#pragma intrinsic(memcpy)

extern size_t wcslen(wchar_t const *str);
#pragma intrinsic(wcslen)

extern size_t strlen(char const *str);
#pragma intrinsic(strlen)

extern void *malloc(size_t size);

extern void *calloc(size_t num, size_t size);

inline void free(void *mem) { HeapFree(h_heap, 0, mem); }
