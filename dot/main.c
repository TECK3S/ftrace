/*
** main.c for  in /home/souman_a//Desktop/my_project/test_graph
** 
** Made by abd-el-moxine soumanou
** Login   <souman_a@epitech.net>
** 
** Started on  Wed Jun 29 12:04:02 2011 abd-el-moxine soumanou
** Last update Wed Jun 29 23:33:02 2011 arnaud1 tessa
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "ftrace.h"
#include "libelf.h"
#include "list.h"
#include "dot.h"

int			main()
{
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

  generate_dot_file(addr_s);

  return (EXIT_SUCCESS);
}

