/*
** utilities14.c for <FTrace> in /home/barrau_a//c_avancee/ftrace
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:28:00 2011 adrien barrau
** Last update Wed Jun 29 18:09:26 2011 rahman-serdar aysan
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/user.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <errno.h>
#include "ftrace.h"

char * p_vm86old_struct(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<vm86old_struct>");
}

char * p_clone_flag(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Clone flag>");
}

static t_mprot_prot	mprot_prot[]=
  {
    {PROT_READ,      "PROT_READ",      ""},
    {PROT_WRITE,     "PROT_WRITE",     ""},
    {PROT_EXEC,      "PROT_EXEC",      ""},
    {PROT_NONE,      "PROT_NONE",      ""}
  };

char 		*p_mprotect_prot(int reg, pid_t pid)
{
  static char	buffer[NB_MPROT_PROT * 4];
  int		c = 0;
  int		nchars = 0;

  (void)pid;
  while (c < NB_MPROT_PROT)
    {
      if ((reg & mprot_prot[c].num) == mprot_prot[c].num)
	{
	  if (nchars)
	    nchars += sprintf(&(buffer[nchars]), "|");
	  nchars += sprintf(&(buffer[nchars]), "%s", mprot_prot[c].name);
	}
      c++;
    }
  return (buffer);
}

char * p_procmask_how(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<ProcMask How>");
}

char * p_quota_cmd(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Quota Cmd>");
}
