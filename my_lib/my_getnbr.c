int	my_getnbr(char *str)
{
  int	i;
  int	nb;

  i = -1;
  nb = 0;
  if (str[i + 1] == '-' || str[i + 1] == '+')
    ++i;
  while ((str[++i] >= '0' && str[i] <= '9'))
    nb = nb * 10 + (str[i] - 48);
  if (str[0] == '-')
    return (-nb);
  return (nb);
}
