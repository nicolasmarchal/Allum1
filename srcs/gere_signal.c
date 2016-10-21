#include "alum.h"

void	reprint_score(void)
{
  char *menu[4];

  fill_score(menu);
  print_menu(menu, glo_si->pos, -1, -2);
  print_score(glo_si);
}

void	check_si(int UNUSED a)
{
  void	(*ptf[6])(void);

  clear_scr();
  ptf[0] = reprint_menu;
  ptf[1] = reprint_option;
  ptf[2] = reprint_rules;
  ptf[3] = reprint_alum;
  ptf[4] = reprint_asksize;
  ptf[5] = reprint_score;
  (ptf[glo_si->which_display])();
}
