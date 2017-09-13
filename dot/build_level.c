/*
** build_level.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Wed Jun 29 20:50:24 2011 arnaud1 tessa
** Last update Wed Jun 29 21:59:53 2011 arnaud1 tessa
*/

#include	<unistd.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	"ftrace.h"
#include	"dot.h"

void		build_level(t_symbol_graph *tree, int *fd)
{
  list_iter2(&tree->sub_symbols, tree, (void *) fd, &build_and_print_file);
}

/*
int			main()
{
  int			fd;
  t_symbol_graph	s;
  t_symbol_graph	s1;
  t_symbol_graph	s2;
  t_symbol_graph	s3;
  t_symbol_graph	s4;
  t_list		list;

  s.symbol_name = "start";
  s.symbol_addr = 0x80f;
  s.symbol_type = SYSCALLS;
  s.debug_info = NULL;
  s.sub_symbols = NULL;
  
  s1.symbol_name = "read";
  s1.symbol_addr = 0x80f;
  s1.symbol_type = SYSCALLS;
  s1.debug_info = NULL;
  s1.sub_symbols = NULL;

  s2.symbol_name = "write";
  s2.symbol_addr = 0x80f;
  s2.symbol_type = SYSCALLS;
  s2.debug_info = NULL;
  s2.sub_symbols = NULL;

  s3.symbol_name = "strlen";
  s3.symbol_addr = 0x80f;
  s3.symbol_type = SYSCALLS;
  s3.debug_info = NULL;
  s3.sub_symbols = NULL;

  s4.symbol_name = "open";
  s4.symbol_addr = 0x80f;
  s4.symbol_type = SYSCALLS;
  s4.debug_info = NULL;
  s4.sub_symbols = NULL;

  list = NULL;

  list_push_back(&list, (void*)&s1);
  list_push_back(&list, (void*)&s2);
  list_push_back(&list, (void*)&s3);
  list_push_back(&list, (void*)&s4);

  s.sub_symbols = list;

  fd = open("graph.dot", O_CREAT | O_RDWR);
  build_level(&s, &fd);
  close(fd);

  return (EXIT_SUCCESS);
}
*/
