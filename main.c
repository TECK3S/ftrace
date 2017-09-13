/*
** main.c for <FTrace> in /home/barrau_a//c_avancee/ftrace
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:09:19 2011 adrien barrau
** Last update Sun Jul  3 21:42:02 2011 arnaud1 tessa
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

static inline int	launch_bin(char * bin, pid_t * pid)
{
  pid_t		npid = 0;
  int		errcode = 0;

  if ((npid = fork()) == 0)
    {
      if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
	fprintf(stderr, PTRACE_ERR_MSG);
      execl(bin, bin, (char *)NULL);
      fprintf(stderr, FORK_ERR_MSG);
      exit(EXIT_FAILURE);
    }
  else
    {
      if (npid != -1)
	*pid = npid;
      else
	errcode = FORK_ERR_CODE;
    }
  return (errcode);
}

static inline int	attach_to_bin(char * pid_bin, pid_t * pid)
{
  int		errcode = 0;

  *pid = atoi(pid_bin);
  if (ptrace(PTRACE_ATTACH, *pid, NULL, NULL) == -1)
    fprintf(stderr, PTRACE_ERR_MSG);
  return (errcode);
}

static inline void	init_graph(t_symbol_graph * graph)
{
  graph->id = 0; 
  graph->symbol_name = "root";
  graph->symbol_addr = 0xdeadbeef;
  graph->symbol_type = UNKNOWN;
  graph->debug_info = "root";
  graph->sub_symbols = EMPTY;
}

int	symbol_id = 1;

int			main(int ac, char ** av)
{
  int			errcode = 0;
  pid_t			pid = 0;
  t_symbol_graph	graph;
  t_symbol_table	symtab = EMPTY;

  if (ac == 2)
    {
      errcode = launch_bin(av[1], &pid);
      fill_symtab(&symtab, av[1]);
    }
  else if (ac == 3 && strcmp(av[1], OPTION_P) == 0)
    errcode = attach_to_bin(av[2], &pid);
  else
    {
      fprintf(stderr, USAGE);
      errcode = BAD_ARGS_ERR_CODE;
    }
  if (!errcode)
    {
      init_graph(&graph);
      errcode = trace_prog(pid, &graph, symtab);
      display_graph(&graph);
    }
  free_symtab(symtab);
  return (errcode);
}
