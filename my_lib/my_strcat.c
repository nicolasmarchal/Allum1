#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  j = -1;
  i = my_strlen(dest) - 1;
  while (src[++j])
    dest[++i] = src[j];
  dest[i + 1] = 0;
  return (dest);
}
