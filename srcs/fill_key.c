#include "alum.h"

void	fill_right_left(char key[8][4])
{
  key[0][0] = 27;
  key[0][1] = 91;
  key[0][2] = 67;
  key[0][3] = 0;
  key[1][0] = 27;
  key[1][1] = 91;
  key[1][2] = 68;
  key[1][3] = 0;
}

void	fill_up_down(char key[8][4])
{
  key[2][0] = 27;
  key[2][1] = 91;
  key[2][2] = 65;
  key[2][3] = 0;
  key[3][0] = 27;
  key[3][1] = 91;
  key[3][2] = 66;
  key[3][3] = 0;
}

void	fill_key(char key[8][4])
{
  fill_right_left(key);
  fill_up_down(key);
  key[4][0] = ' ';
  key[4][1] = 0;
  key[5][0] = 'q';
  key[5][1] = 0;
  key[6][0] = 's';
  key[6][1] = 0;
  key[7][0] = 0;
}
