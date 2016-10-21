#ifndef MY_H_
# define MY_H_

#include <unistd.h>
#include <stdlib.h>

void	my_putchar(char);
void	my_putchar_fd(char, int);
void	my_putstr(char *);
int	my_puterror(char *);
void	my_put_nbr(int);
void	my_putnbr_fd(int, int);
int	my_strlen(char *);
int	my_getnbr(char *);
int	my_strlen(char *);
int	my_strcmp(char *, char *);
char	*get_next_line(const int);
char	*my_strdup(char *);

#endif /* !MY_H_ */
