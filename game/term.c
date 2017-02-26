/*
** events.c for events in /home/Maxime/delivery/PSU/PSU_2016_tetris/game/
**
** Made by Maxime Jenny
** Login   <maxime.jenny@epitech.eu@epitech.eu>
**
** Started on  Fri Feb 24 18:13:37 2017 Maxime Jenny
** Last update Sat Feb 25 19:36:02 2017 
*/

#include <sys/ioctl.h>
#include <ncurses.h>
#include <termio.h>
#include <curses.h>
#include <unistd.h>
#include <termio.h>
#include <stdlib.h>
#include "tetris.h"
#include "my.h"



int		event(struct winsize size, t_tetris *tetris)
{
  
  return (0);
}

int			my_set_term(struct termio *termios)
{
  ioctl(0, TCGETA, termios);
  termios->c_lflag &= ~(ICANON | ECHO);
  termios->c_cc[VTIME] = 0;
  termios->c_cc[VMIN] = 0;
  ioctl(0, TCSETA, termios);
}

int			my_reset_term(struct termio *termios)
{
  ioctl(0, TCGETA, termios);
  termios->c_lflag |= (ICANON | ECHO);
  ioctl(0, TCSETA, termios);
}