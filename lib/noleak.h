#ifndef		__NO_LEAK_H__
#define		__NO_LEAK_H__

/**
 * Data formatting: PREV_DATA_PTR : NEXT_DATA_PTR : YOUR_REAL_DATA
 */
void		*xmalloc(int size);
void		xfree(void *data);
#endif
