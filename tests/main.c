#include	<stdlib.h>
#include	<stdio.h>
#include	"noleak.h"
#define		ITERATIONS	20000

int		main(int ac, __attribute__((unused))char **av)
{
  char		*s[ITERATIONS];
  int		i;

  if (ac == 2)
    {
      printf("Testing with LibNoLeak\n");
      for (i = 0; i < ITERATIONS; i++) 
	s[i] = xmalloc(10); 
      for (i = 0; i < ITERATIONS; i++)
	xfree(s[i]); 
    }
  else
    {
      printf("Testing normally\n");
      for (i = 0; i < ITERATIONS; i++) 
	s[i] = malloc(10); 
      for (i = 0; i < ITERATIONS; i++) 
	free(s[i]); 
    }  
  return (0);
}
