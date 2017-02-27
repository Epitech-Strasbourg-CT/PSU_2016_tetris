/*
** events.c for tetris in /home/cedric/delivery/PSU/PSU_2016_tetris
**
** Made by
** Login   <cedric.thomas@epitech.eu>
**
** Started on  Sat Feb 25 19:37:10 2017
** Last update Mon Feb 27 12:50:23 2017 Maxime Jenny
*/
#include <ncurses.h>
#include "tetris.h"

void	my_pause(t_tetris *tetris)
{
  mvprintw(0, 0, "pause");
  (tetris->status = 1) ? (tetris->status = 0) : (tetris->status = 1);
}

void	my_quit(t_tetris *tetris)
{
  mvprintw(0, 0, "quit");
  tetris->status = 2;
}