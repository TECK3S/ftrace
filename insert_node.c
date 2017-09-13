/*
** insert_node.c for <FTrace> in /home/barrau_a//c_avancee/ftrace_de_pneu
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sun Jul  3 22:14:07 2011 adrien barrau
** Last update Sun Jul  3 22:25:15 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/user.h>
#include "ftrace.h"

void	insert_node(t_symbol_graph * graph,
		    t_symbol_table symtab,
		    int addr,
		    enum eSymbolType type,
		    char * debug)
{
  extern int		symbol_id;
  t_symbol_graph *	node_gr = NULL;

  node_gr = malloc(sizeof(*node_gr));
  node_gr->id = symbol_id++;
  node_gr->symbol_addr = addr;
  node_gr->symbol_name = get_sym_with_addr(node_gr->symbol_addr, symtab);
  node_gr->symbol_type = type;
  node_gr->debug_info = debug;
  node_gr->sub_symbols = EMPTY;
  list_push_back(&graph->sub_symbols, node_gr);
}
