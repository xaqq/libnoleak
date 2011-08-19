#include	<stdlib.h>
#include	<malloc.h>
#include	"noleak.h"

void	*noleak_set_last_item(void *item, int set)
{
  static void *i = NULL;
  
  if (set)
    i = item;
  return (i);
}

void	*noleak_get_last_item(void)
{
  return (noleak_set_last_item(NULL, 0));
}

void		*xmalloc(size_t n)
{
  return (noleak_malloc(n, NULL));
}

void		xfree(void *data)
{
  noleak_free(data, NULL);
}

void		noleak_free(void *data,
			    __attribute__((unused))const void *caller)
{
  static void	*prev;
  static void	*next;

  __malloc_hook = NULL;
  __free_hook = NULL;

  prev = *(void **)(data - (sizeof(void *) * 2));
  if (prev)
    {
      next = prev + sizeof(void *);
      *(int **)next = *(void **)(data - sizeof(void *));
    }
  else
    {
      next = *(void **)(data - sizeof(void *));
      noleak_set_last_item(next, 1);
      if (next)
	*(int **)next = NULL;
    }
  free(data - sizeof(void *) * 2);

  __malloc_hook = &noleak_malloc;
  __free_hook = &noleak_free;
}

void		*noleak_malloc(size_t size,
				__attribute__((unused))const void *caller)
{
  void		*r;

  __malloc_hook = NULL;
  __free_hook = NULL;

  r = malloc(size + sizeof(void *) * 2);
  if (!r)
    exit(-1);
  *(void **)(r) = noleak_get_last_item();
  *(void **)(r + sizeof(void *)) = NULL;

  if (noleak_get_last_item())
    *(void **)(noleak_get_last_item() + sizeof(void *)) = r;
  noleak_set_last_item(r, 1);
  
  __malloc_hook = &noleak_malloc;
  __free_hook = &noleak_free;

  return (r + sizeof(void *) * 2);
}

void		__attribute__((destructor))noleak_dtor(void)
{
  void		*last;
  void		*cpy;

  for (last = noleak_get_last_item(); last; last = cpy)
    {
      cpy = *(void **)last;
      xfree(last + sizeof(void *) * 2);
    }
}
