/*
** the_game.c for THE GAME IS ON in /home/Maxime/delivery/PSU/PSU_2016_tetris/game/
**
** Made by Maxime Jenny
** Login   <maxime.jenny@epitech.eu@epitech.eu>
**
** Started on  Wed Feb 22 08:50:45 2017 Maxime Jenny
** Last update Fri Feb 24 19:03:46 2017 Maxime Jenny
*/

#include <sys/ioctl.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <termio.h>
#include <stdlib.h>
#include "tetris.h"
#include "my.h"

int			my_set_term(struct termio *termios)
{
  ioctl(0, TCGETA, termios);
  termios->c_lflag &= ~(ICANON | ECHO);
  termios->c_cc[VTIME] = 0;
  termios->c_cc[VMIN] = 0;
  ioctl(0, TCSETA, termios);
}

void		my_print_map(t_tetris *tetris, struct winsize size)
{
  int		y;

  if (size.ws_col < tetris->my_rules->map.x + 3 ||
	 size.ws_row < tetris->my_rules->map.y)
    {
      mvprintw((size.ws_row / 2),
	       (size.ws_col / 2) - 13, "%s", "Please, resize your terminal.");
    }
  else
    {
      y = -1;
      while (++y < tetris->my_rules->map.y + 2)
	mvprintw((size.ws_row / 2) - (tetris->my_rules->map.y / 2) + y,
		 (size.ws_col / 2) - (tetris->my_rules->map.y / 2), "%s",
		 tetris->map[y]);
    }
}

int			the_game(t_tetris *tetris,
				 t_tetrimino *shape_list)
{
  struct winsize	size;
  struct termio		termios;
  WINDOW		*win;
  t_time		t;

  win = initscr();
  curs_set(0);
  keypad(win, 1);
  my_set_term(&termios);
  set_time(&t);
  while (1)
    {
      ioctl(0, TIOCGWINSZ, &size);
      my_print_map(tetris, size);
      refresh();
      // event(size, tetris);
      // clear();
    }
}