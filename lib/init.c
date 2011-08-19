#include	<stdlib.h>
#include	<malloc.h>
#include	"noleak.h"

__attribute__((constructor)) void noleak_ctor(void)
{
  __malloc_hook = &noleak_malloc;
  __free_hook = &noleak_free;
}
