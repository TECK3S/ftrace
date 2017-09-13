/*
** close_dot_file.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Wed Jun 29 23:21:46 2011 arnaud1 tessa
** Last update Wed Jun 29 23:27:47 2011 arnaud1 tessa
*/

#include	<unistd.h>
#include	"dot.h"

void		close_dot_file(int fd)
{
  print_file(fd, "}\n");
  close(fd);
}

/*
int		main()
{
  int		fd;
  
  fd = init_dot_file();
  close_dot_file(fd);
}
*/
