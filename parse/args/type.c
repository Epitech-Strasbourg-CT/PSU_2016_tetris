/*
** type.c for type in /home/cedric/delivery/PSU/PSU_2016_tetris/parse/args
** 
** Made by 
** Login   <cedric.thomas@epitech.eu>
** 
** Started on  Tue Feb 21 15:00:13 2017 
** Last update Wed Feb 22 09:39:11 2017 
*/
#include <stdlib.h>
#include "my.h"
#include "tetris.h"

int	invalid_parse(t_parse *parse, char *str)
{
  my_puterror("Error : ");
  my_puterror(str);
  my_puterror(" for ");
  if (parse->short_name != NULL)
    {
      my_puterror(parse->short_name);
      my_puterror("/");
    }
  my_puterror(parse->long_name);
  my_puterror("\n");
  return (84);
}

int	parse_boolean(t_parse *parse, char *value)
{
  int	*casted;

  casted = (int *)parse->value;
  *casted = 1;
  return (0);
}

int	parse_value(t_parse *parse, char *value)
{
  int	*casted;

  casted = (int *)parse->value;
  if (is_an_int(value))
    return (invalid_parse(parse, "invalid value"));
  *casted = my_getnbr(value);
  return (0);
}

int	parse_key(t_parse *parse, char *value)
{
  char	**casted;

  casted = (char **)parse->value;
  free(*casted);
  if ((*casted = my_strdup(value)) == NULL)
    return (84);
  return (0);
}

int		parse_vector(t_parse *parse, char *value)
{
  t_vector2i	*casted;
  char		**tabvec;
  int		i;

  i = -1;
  if ((tabvec = my_split (value, ',')) == NULL)
    return (84);
  while (tabvec[++i]);
  if (i != 2)
    return (invalid_parse(parse, "invalid vector"));
  if (my_strlen(tabvec[0]) + my_strlen(tabvec[1]) + 1 != my_strlen(value))
    return (invalid_parse(parse, "invalid vector"));
  if (is_an_int(tabvec[0]) || is_an_int(tabvec[1]))
    return (invalid_parse(parse, "invalid vector value(s)"));
  casted = (t_vector2i *)parse->value;
  *casted = myvector2i(my_getnbr(tabvec[0]), my_getnbr(tabvec[1]));
  return (0);
}
