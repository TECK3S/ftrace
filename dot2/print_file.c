/*
** print_file.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Wed Jun 29 20:05:18 2011 arnaud1 tessa
** Last update Wed Jun 29 20:41:38 2011 arnaud1 tessa
*/

#include	<stdlib.h>
#include	<fcntl.h>
#include	<string.h>
#include	<unistd.h>
#include	<stdio.h>

void		print_file(int fd, char *line)
{
  int		wc;

  wc = write(fd, line, strlen(line));
  if (wc == -1)
    {
      printf("error in function print_file, write failed\n");
    }
}

/*
int		main()
{
  int		fd;

  fd = open("graph.dot", O_CREAT | O_RDWR);
  print_file(fd, "la vie est belle\n");
  close(fd);
  return (EXIT_FAILURE);
}
*/
