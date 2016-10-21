#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define SIZE 4096

void	buf_init(char *str, int taille);
char	*my_realloc(char *str, int taille);
int	still_tmp(char *tmp, char *buf, int i, int ret);
char	*read_line(const int fd, char *str, char *tmp, int j);
char	*get_next_line(const int fd);

# endif /* !GET_NEXT_LINE_H_ */
