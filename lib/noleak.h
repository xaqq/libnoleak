#ifndef		__NO_LEAK_H__
#define		__NO_LEAK_H__

/**
 * Hooks used internally
 */
void		*noleak_malloc(size_t size, const void *caller);
void		noleak_free(void *data, const void *ptr);

/**
 * Data formatting: PREV_DATA_PTR : NEXT_DATA_PTR : YOUR_REAL_DATA
 */
void		*xmalloc(size_t size);
void		xfree(void *data);
#endif
