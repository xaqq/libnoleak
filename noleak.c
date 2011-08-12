#include	<stdlib.h>
#include	"noleak.h"

t_noleak	*noleak_set_first_item(t_noleak *item, int set)
{
  static t_noleak *i = NULL;
  
  if (set)
    i = item;
  return (i);
}

t_noleak	*noleak_get_first_item(void)
{
  return (noleak_set_first_item(NULL, 0));
}

void		xfree(void *data)
{
  t_noleak	*i;
  t_noleak	*prev;

  prev = NULL;
  for (i = noleak_get_first_item(); i; prev = i, i = i->next)
    {
      if (i->data == data)
	{
	  free(i->data);
	  if (prev)
	    prev->next = i->next;
	  else
	    noleak_set_first_item(i->next, 1);
	  free(i);
	  break;
	}
    }
}

void		*xmalloc(int size)
{
  void		*r;
  t_noleak	*new;

  r = malloc(size);
  if (!r)
    exit(-1);
  new = malloc(sizeof(t_noleak));
  if (!new)
    exit(-1);
  new->data = r;
  new->next = noleak_get_first_item();
  noleak_set_first_item(new, 1);
  return (r);
}

void		__attribute__((destructor))noleak_dtor(void)
{
  t_noleak	*i;
  t_noleak	*next;

  for (i = noleak_get_first_item(); i; i = next)
    {
      free(i->data);
      next = i->next;
      free(i);
    }
}
