/*
** init_dot_file.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Wed Jun 29 23:11:26 2011 arnaud1 tessa
** Last update Wed Jun 29 23:21:24 2011 arnaud1 tessa
*/

#include	<fcntl.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"dot.h"

int		init_dot_file()
{
  int		fd;

  fd = open("graph.dot", O_CREAT | O_RDWR, S_IRWXU);
  if (fd == -1)
    {
      printf("ERROR : cannot create file graph.dot\n");
      exit(EXIT_FAILURE);
    }
  print_file(fd, "digraph ftrace {\n");
  return (fd);
}

/*
int		main()
{
  init_dot_file();
}
*/
