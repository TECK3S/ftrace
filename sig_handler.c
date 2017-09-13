/*
** sig_handler.c for <FTrace> in /home/barrau_a//c_avancee/ftrace
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:10:26 2011 adrien barrau
** Last update Fri Jul  1 12:04:58 2011 adrien barrau
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

t_signals	all_signals[]=
  {
    {SIGHUP,    "SIGHUP",    "Hangup"},
    {SIGINT,    "SIGINT",    "Interrupt"},
    {SIGQUIT,   "SIGQUIT",   "Quit"},
    {SIGILL,    "SIGILL",    "Illegal instruction"},
    {SIGABRT,   "SIGABRT",   "Aborted"},
    {SIGFPE,    "SIGFPE",    "Floating point exception"},
    {SIGKILL,   "SIGKILL",   "Killed"},
    {SIGSEGV,   "SIGSEGV",   "Segmentation fault"},
    {SIGPIPE,   "SIGPIPE",   "Broken pipe"},
    {SIGALRM,   "SIGALRM",   "Alarm clock"},
    {SIGTERM,   "SIGTERM",   "Terminated"},
    {SIGUSR1,   "SIGUSR1",   "User defined signal 1"},
    {SIGUSR2,   "SIGUSR2",   "User defined signal 2"},
    {SIGCHLD,   "SIGCHLD",   "Child exited"},
    {SIGCONT,   "SIGCONT",   "Continued"},
    {SIGSTOP,   "SIGSTOP",   "Stopped (signal)"},
    {SIGTSTP,   "SIGTSTP",   "Stopped"},
    {SIGTTIN,   "SIGTTIN",   "Stopped (tty input)"},
    {SIGTTOU,   "SIGTTOU",   "Stopped (tty output)"},
    {SIGBUS,    "SIGBUS",    "Bus error"},
    {SIGPROF,   "SIGPROF",   "Profiling timer expired"},
    {SIGURG,    "SIGURG",    "Urgent I/O condition"},
    {SIGVTALRM, "SIGVTALRM", "Virtual timer expired"},
    {SIGXCPU,   "SIGXCPU",   "CPU time limit exceeded"},
    {SIGXFSZ,   "SIGXFSZ",   "File size limit exceeded"},
    {SIGSTKFLT, "SIGSTKFLT", "Stack fault"},
    {SIGIO,     "SIGIO",     "I/O possible"},
    {SIGPWR,    "SIGPWR",    "Power failure"},
    {SIGWINCH,  "SIGWINCH",  "Window changed"},
    {SIGSYS,    "SIGSYS",    "Bad system call"}
  };

int			handle_sig(int status,
				   t_symbol_graph * graph)
{
  int			c = 0;
  t_symbol_graph *	sig = NULL;

  if (WIFSTOPPED(status) && WSTOPSIG(status) != SIGTRAP)
    {
      while (c < NB_SIGNALS)
	{
	  if (WSTOPSIG(status) == all_signals[c].num)
	    {
	      sig = malloc(sizeof(*sig));
	      sig->symbol_name = all_signals[c].name;
	      sig->symbol_addr = 0x00000000;
	      sig->symbol_type = SIGNAL_REC;
	      sig->debug_info = all_signals[c].desc;
	      sig->sub_symbols = EMPTY;
	      list_push_back(&graph->sub_symbols, sig);
	      return (all_signals[c].num);
	    }
	  c++;
	}
    }
  return (NO_SIGNAL);
}

void			are_you_killing_me(int status,
					   t_symbol_graph * graph)
{
  int			c = 0;
  t_symbol_graph *	sig = NULL;

  if (WIFSIGNALED(status))
    {
      while (c < NB_SIGNALS)
	{
	  if (WTERMSIG(status) == all_signals[c].num)
	    {
	      sig = malloc(sizeof(*sig));
	      sig->symbol_name = all_signals[c].name;
	      sig->symbol_addr = 0x00000000;
	      sig->symbol_type = KILLED;
	      sig->debug_info = all_signals[c].desc;
	      sig->sub_symbols = EMPTY;
	      list_push_back(&graph->sub_symbols, sig);
	      break;
	    }
	  c++;
	}
    }
}
