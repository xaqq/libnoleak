#ifndef		__NO_LEAK_H__
#define		__NO_LEAK_H__

typedef struct		s_noleak
{
  void			*data;
  struct s_noleak	*next;
}			t_noleak;

void		*xmalloc(int size);
void		xfree(void *data);
#endif
