/*
** utilities3.c for <FTrace> in /home/barrau_a//c_avancee/ftrace
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:12:57 2011 adrien barrau
** Last update Fri Jun 24 16:13:02 2011 adrien barrau
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/user.h>
#include <sys/ptrace.h>
#include <utime.h>
#include "ftrace.h"

static t_ptrace_req	p_req[]=
  {
    {PTRACE_TRACEME, "PTRACE_TRACEME", ""},
    {PTRACE_PEEKTEXT, "PTRACE_PEEKTEXT", ""},
    {PTRACE_PEEKDATA, "PTRACE_PEEKDATA", ""},
    {PTRACE_PEEKUSER, "PTRACE_PEEKUSER", ""},
    {PTRACE_POKETEXT, "PTRACE_POKETEXT", ""},
    {PTRACE_POKEDATA, "PTRACE_POKEDATA", ""},
    {PTRACE_POKEUSER, "PTRACE_POKEUSER", ""},
    {PTRACE_GETREGS, "PTRACE_GETREGS", ""},
    {PTRACE_GETFPREGS, "PTRACE_GETFPREGS", ""},
    {PTRACE_GETSIGINFO, "PTRACE_GETSIGINFO", ""},
    {PTRACE_SETREGS, "PTRACE_SETREGS", ""},
    {PTRACE_SETFPREGS, "PTRACE_SETFPREGS", ""},
    {PTRACE_SETSIGINFO, "PTRACE_SETSIGINFO", ""},
    {PTRACE_SETOPTIONS, "PTRACE_SETOPTIONS", ""},
    {PTRACE_GETEVENTMSG, "PTRACE_GETEVENTMSG", ""},
    {PTRACE_CONT, "PTRACE_CONT", ""},
    {PTRACE_SYSCALL, "PTRACE_SYSCALL", ""},
    {PTRACE_SINGLESTEP, "PTRACE_SINGLESTEP", ""},
    {PTRACE_KILL, "PTRACE_KILL", ""},
    {PTRACE_ATTACH, "PTRACE_ATTACH", ""},
    {PTRACE_DETACH, "PTRACE_DETACH", ""}
  };

char *	p_ptrace_req(int reg, pid_t pid)
{
  static char	buffer[NB_PTRACE_REQ * 15];
  int		c = 0;
  int		nchars = 0;

  (void)pid;
  while (c < NB_PTRACE_REQ)
    {
      if ((reg & p_req[c].num) == p_req[c].num)
	{
	  if (nchars)
	    nchars += sprintf(&(buffer[nchars]), "|");
	  nchars += sprintf(&(buffer[nchars]), "%s", p_req[c].name);
	}
      c++;
    }
  if (!nchars)
    nchars += sprintf(&(buffer[nchars]), "0");
  return (buffer);
}

char * p_struct_utime(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Utime Struct>");
}

static t_access_mode	a_mod[]=
  {
    {F_OK, "F_OK", ""},
    {R_OK, "R_OK", ""},
    {W_OK, "W_OK", ""},
    {X_OK, "X_OK", ""}
  };

char * p_access_mode(int reg, pid_t pid)
{
  static char	buffer[NB_ACCESS_MODE * 15];
  int		c = 0;
  int		nchars = 0;

  (void)pid;
  while (c < NB_ACCESS_MODE)
    {
      if ((reg & a_mod[c].num) == a_mod[c].num)
	{
	  if (nchars)
	    nchars += sprintf(&(buffer[nchars]), "|");
	  nchars += sprintf(&(buffer[nchars]), "%s", a_mod[c].name);
	}
      c++;
    }
  if (!nchars)
    nchars += sprintf(&(buffer[nchars]), "0");
  return (buffer);
}

char * p_signal(int reg, pid_t pid)
{
  extern t_signals all_signals[];
  static char	buffer[NB_ACCESS_MODE * 15];
  int		c = 0;
  int		nchars = 0;

  (void)pid;
  while (c < NB_SIGNALS)
    {
      if (reg == all_signals[c].num)
	{
	  if (nchars)
	    nchars += sprintf(&(buffer[nchars]), "|");
	  nchars += sprintf(&(buffer[nchars]), "%s", all_signals[c].name);
	}
      c++;
    }
  if (!nchars)
    nchars += sprintf(&(buffer[nchars]), "0");
  return (buffer);
}

char *	p_double_int_tab(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Int Tab>");
}
