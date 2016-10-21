#ifndef ALUM_H_
# define ALUM_H_

#include <termios.h>
#include <sys/ioctl.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <term.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include  "my.h"

# define SIZE 3
# define SIZE_MAX_ 4096
# define UNUSED __attribute__((unused))

typedef struct s_game
{
  int		size;
  char		*alum;
  char		level;
  int		stat[8];
  int		pos;
  int		which_display;
  char		key[7][4];
}		t_game;

t_game	*glo_si;

int	clear_scr(void);
void	check_si(int);
void	put_underline(char, int, int, char);
int	biggest_line(char *);
int	put_mode(char *, int, int);
char	*get_name(char **);
int	raw_mode(struct termios *);
int	reactive_can(struct termios *);
int	init_env(struct termios *, char *);
int	exec_left(char *, int);
int	exec_right(char *, int);
int	exec_space(char *, int);
int	check_for_sel(char *);
int	exec_q_key(char *, int);
int	exec_s_key(char *, int);
int	check_key(char *, char *, char key[8][4], int *);
int	delete_space(char *, int);
int	player_turn(t_game *);
char	print_result(char);
char	play_the_game(t_game *);
int	init_data(t_game *, struct termios *, char **);
char	*fill_the_game(int);
int	len_nb(int);
void	print_nb_is_to_big(struct winsize *, int *);
int	verif_size(char *, int *, struct winsize *);
int	print_ask_for_size(struct winsize *);
int	ask_for_size(t_game *);
int	are_you_ready_to_play_the_game(t_game *);
int	init_game(char **);
void	put_under_inverse(char *, char, char, int);
int	biggest_len_of_tab(char **);
int	size_tab(char **);
int	print_menu(char **, int, char, int);
void	fill_menu(char **);
int	press_key(char **, char *, char key[8][4], int pos);
int	gere_select(t_game *, int);
int	gere_menu(t_game *);
void	fill_option(char **);
int	gere_option(t_game *);
void	reprint_menu(void);
void	reprint_option(void);
void	reprint_rules(void);
void	reprint_alum(void);
void	reprint_asksize(void);
void	reprint_score(void);
void	fill_right_left(char key[8][4]);
void	fill_up_down(char key[8][4]);
void	fill_key(char key[8][4]);
int	return_for_play(t_game *);
void	fill_rules(char **);
int	gere_rules(t_game *);
void	fill_score(char **);
void	print_stat(t_game *, int, int , int);
int	init_score(int *);
void	fill_score2(char **);
int	print_score(t_game *);
int	reset_stat(t_game *);
int	gere_score(t_game *);
int	gere_exit(t_game *);
int	check_left(char *, int);
int	check_right(char *, int);
int	check_next_line(char *, int, int);
int	exec_down(char *, int);
int	check_particular2(char *, int, int);
int	check_particular(char *, int, int);
int	check_next_line2(char *, int, int);
int	exec_up(char *, int);
int	parse_stat(char *, int *);
void	my_putchar_fd(char, int);
void	my_putnbr_fd(int, int);
int	re_write(int *);
int	fill_stat(t_game *);
int	calc_xor(char *, int);
void	buf_init(char *, int);
int	clean_game(char *, int, int);
int	nb_line(char *, int);
int	add_nb_alum(char *, int);
int	check_nb_alum_one_line(char *, int, int);
int	exeption1(char *, int, int, char);
int	pick_alum(char *, char *, int, char);
void	count_nb_alum_on_line(char *, char *);
int	ia_hard(char *, int, int);
int	ia_medium(char *, int, int);
int	ia_easy(char *, int, int);
int	check_who_play_the_first_for_hard(t_game *);
int	algo_easy(char *, char *, int);

#endif /* !ALUM_H_ */
