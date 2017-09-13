/*
** call_mgr.c for <FTrace> in /home/barrau_a//c_avancee/ftrace_de_pneu
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Tue Jun 28 18:41:29 2011 adrien barrau
** Last update Sun Jul  3 22:59:31 2011 adrien barrau
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

int	has_returned(struct user_regs_struct * regs,
		     pid_t pid)
{
  union char_disturbed	eip;

  eip._char = ptrace(PTRACE_PEEKDATA, pid, regs->eip, NULL);
  if (eip._disturbed[0] == 0xc3 || eip._disturbed[0] == 0xcb
      || eip._disturbed[0] == 0xc2 || eip._disturbed[0] == 0xca)
    return (1);
  else
    return (0);
}

static void	call_e8_mgr(struct user_regs_struct * regs,
			    pid_t pid,
			    t_symbol_graph * graph,
			    t_symbol_table symtab,
			    union char_disturbed eip)
{
  union char_disturbed	offset;

  offset._disturbed[0] = eip._disturbed[1];
  offset._disturbed[1] = eip._disturbed[2];
  offset._disturbed[2] = eip._disturbed[3];
  eip._char = ptrace(PTRACE_PEEKDATA, pid, regs->eip + 4);
  offset._disturbed[3] = eip._disturbed[0];
  insert_node(graph, symtab, regs->eip + 5 + offset._char, LOCAL_SYM, "");
}

int	call_mgr(struct user_regs_struct * regs,
		 pid_t pid,
		 t_symbol_graph * graph,
		 t_symbol_table symtab)
{
  union char_disturbed	eip;
  //  bool			call = true;
  //  t_symbol_graph *	last = NULL;

  eip._char = ptrace(PTRACE_PEEKDATA, pid, regs->eip, NULL);
  if (eip._disturbed[0] == 0xe8)
    call_e8_mgr(regs, pid, graph, symtab, eip);
  else if (eip._disturbed[0] == 0xff)
    choose_ff_mgr(regs, pid, graph, symtab, eip);
  //  else
    //    call = false;
  //  if (call && (last = list_back(graph)) != NULL)
  //    trace_call(pid, last->sub_symbols, symtab);
  return (0);
}
