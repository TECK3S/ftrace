/*
** display_graph.c for <FTrace> in /home/barrau_a//c_avancee/ftrace_de_pneu
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Wed Jun 29 19:31:54 2011 adrien barrau
** Last update Sun Jul  3 21:25:48 2011 arnaud1 tessa
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
#include "dot/dot.h"

/*static void		dump_sym(content_t * cont, param_t param)
{
  t_symbol_graph *	g = (t_symbol_graph *)*cont;
  int *			space = (int *)param;
  int			i = 0;

  for (i = 0; i < *space; ++i)
    printf(" ");
  printf("[%s]\n", g->symbol_name);
  if (!list_empty(g->sub_symbols))
    {
      *space += 1;
      list_iter(&g->sub_symbols, space, &dump_sym);
      *space -= 1;
    }
}
*/

void	display_graph(t_symbol_graph * graph)
{
  //int	space = 0;

  generate_dot_file(graph);
  //list_iter(&graph->sub_symbols, &space, &dump_sym);  
}
