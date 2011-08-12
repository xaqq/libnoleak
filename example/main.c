#include	<stdlib.h>
#include	"noleak.h"

int		main()
{
  char		*s = xmalloc(19);
  s = NULL;
  return (0);
}
