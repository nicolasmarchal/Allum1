#include "alum.h"

void	reprint_menu(void)
{
  char	*menu[7];

  fill_menu(menu);
  print_menu(menu, glo_si->pos, -1, 5);
}

void	reprint_option(void)
{
  char	*menu[6];

  fill_option(menu);
  print_menu(menu, glo_si->pos, glo_si->level, 4);
}

void	reprint_rules(void)
{
  char	*menu[9];

  fill_rules(menu);
  print_menu(menu, 7, -1, 7);
}

void	reprint_alum(void)
{
  put_mode(glo_si->alum, glo_si->size, glo_si->pos);
}

void	reprint_asksize(void)
{
  struct winsize ws;

  print_ask_for_size(&ws);
}
