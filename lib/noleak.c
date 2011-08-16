#include	<stdlib.h>
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

void		xfree(void *data)
{
  static void	*prev;
  static void	*next;

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
}

void		*xmalloc(int size)
{
  void		*r;

  r = malloc(size + sizeof(void *) * 2);
  if (!r)
    exit(-1);
  *(void **)(r) = noleak_get_last_item();
  *(void **)(r + sizeof(void *)) = NULL;

  if (noleak_get_last_item())
    *(void **)(noleak_get_last_item() + sizeof(void *)) = r;
  noleak_set_last_item(r, 1);
  return (r + sizeof(void *) * 2);
}

void		__attribute__((destructor))noleak_dtor(void)
{
  void		*last;
  void		*cpy;

  for (last = noleak_get_last_item(); last; last = cpy)
    {
      cpy = *(void **)last;
      free(last);
    }
}
