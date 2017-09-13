/*
** build_dot.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Wed Jun 29 21:44:49 2011 arnaud1 tessa
** Last update Sun Jul  3 23:30:25 2011 arnaud1 tessa
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	"list.h"
#include	"ftrace.h"
#include	"dot.h"

void		build_dot(content_t * cont, 
			      param_t param1)
{
  int			fd;
  t_symbol_graph	*tree;
  char			*declaration;

  fd = *((int*) param1);
  tree = *((t_symbol_graph **) cont);
  declaration = build_declaration(tree);
  /*print_file(fd, declaration);
    free(declaration);*/
  if (tree != NULL)
    {
      build_level(tree, &fd);
      build_sub_levels(&(tree->sub_symbols), &fd);
    }
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
  t_symbol_graph	*addr_s;
  t_list		list;
  t_list		list1;
  t_list		list2;

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
  list1 = NULL;
  list2 = NULL;
  
  list_push_back(&list, (void*)&s1);
  list_push_back(&list, (void*)&s2);
  list_push_back(&list, (void*)&s4);
  list_push_back(&list1, (void*)&s3);
  list_push_back(&list2, (void*)&s3);

  s.sub_symbols = list;
  s1.sub_symbols = list1;
  s2.sub_symbols = list2;
  
  addr_s = &s;

  fd = open("graph.dot", O_CREAT | O_RDWR);
  build_dot((void **)&addr_s, &fd);
  close(fd);

  return (EXIT_SUCCESS);
}
*/
