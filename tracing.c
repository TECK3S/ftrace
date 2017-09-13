/*
** tracing.c for <FTrace> in /home/barrau_a//c_avancee/ftrace
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:09:57 2011 adrien barrau
** Last update Sun Jul  3 12:14:29 2011 adrien barrau
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

int				trace_prog(pid_t pid,
					   t_symbol_graph * graph,
					   t_symbol_table symtab)
{
  int				status = 0;
  int				sig = 0;
  struct user_regs_struct	regs;
  int				errcode = 0;

  do
    {
      wait4(pid, &status, 0, NULL);
      sig = handle_sig(status, graph);
      if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) == -1)
	errcode = PTRACE_ERR_CODE;
      if (!syscalls_mgr(&regs, pid, graph))
	call_mgr(&regs, pid, graph, symtab);
      if (ptrace(PTRACE_SINGLESTEP, pid, NULL, sig) == -1)
	errcode = PTRACE_ERR_CODE;
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  are_you_killing_me(status, graph);
  return (errcode);
}

int				trace_call(pid_t pid,
					   t_symbol_graph * graph,
					   t_symbol_table symtab)
{
  int				status = 0;
  int				sig = 0;
  struct user_regs_struct	regs;
  int				errcode = 0;
  int				return_from_proc = 0;

  if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1)
    errcode = PTRACE_ERR_CODE;
  do
    {
      wait4(pid, &status, 0, NULL);
      sig = handle_sig(status, graph);
      if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) == -1)
	errcode = PTRACE_ERR_CODE;
      if (has_returned(&regs, pid))
	return_from_proc = 1;
      else if (!syscalls_mgr(&regs, pid, graph))
	call_mgr(&regs, pid, graph, symtab);
      if (ptrace(PTRACE_SINGLESTEP, pid, NULL, sig) == -1)
	errcode = PTRACE_ERR_CODE;
    } while (!WIFEXITED(status) && !WIFSIGNALED(status) && !return_from_proc);
  are_you_killing_me(status, graph);
  return (errcode);
}
