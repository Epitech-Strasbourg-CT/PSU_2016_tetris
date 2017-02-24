/*
** sort.c for tetris in /home/cedric/delivery/PSU/PSU_2016_tetris/parse/tertrimino
** 
** Made by 
** Login   <cedric.thomas@epitech.eu>
** 
** Started on  Fri Feb 24 21:05:11 2017 
** Last update Fri Feb 24 21:30:38 2017 
*/
#include <stdlib.h>
#include "tetris.h"
#include "my.h"

static void	swap_tetri(t_tetrimino **shape_list, int index1, int index2)
{
  t_tetrimino	temp;

  temp = (*shape_list)[index1];
  (*shape_list)[index1] = (*shape_list)[index2];
  (*shape_list)[index2] = temp;
}

void	sort_tetri(t_tetrimino **shape_list)
{
  int	i;
  int	action;

  action = 1;
  while (action)
    {
      i = 0;
      action = 0;
      while ((*shape_list)[++i].name != NULL)
	{
	  if (my_strcmp((*shape_list)[i - 1].name, (*shape_list)[i].name) > 0)
	    {
	      action = 1;
	      swap_tetri(shape_list, i - 1, i);
	    }
	}
    }
}