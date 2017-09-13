/*
** utilities15.c for <FTrace> in /home/barrau_a//c_avancee/ftrace
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:27:53 2011 adrien barrau
** Last update Wed Jun 29 18:38:53 2011 rahman-serdar aysan
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

char * p_nmap_flag(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Nmap Flag >");
}

char * p_clock_flag(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Clock Flag>");
}

static t_mmap2_prot	mmap2_prot[]=
  {
    {PROT_READ,      "PROT_READ",      ""},
    {PROT_WRITE,     "PROT_WRITE",     ""},
    {PROT_EXEC,      "PROT_EXEC",      ""},
    {PROT_NONE,      "PROT_NONE",      ""}
  };

char 		*p_mmap2_prot(int reg, pid_t pid)
{
  static char	buffer[NB_MMAP2_PROT * 4];
  int		c = 0;
  int		nchars = 0;

  (void)pid;
  while (c < NB_MMAP2_PROT)
    {
      if ((reg & mmap2_prot[c].num) == mmap2_prot[c].num)
	{
	  if (nchars)
	    nchars += sprintf(&(buffer[nchars]), "|");
	  nchars += sprintf(&(buffer[nchars]), "%s", mmap2_prot[c].name);
	}
      c++;
    }
  return (buffer);
}

static t_mmap2_map	mmap2_map[]=
  {
    {MAP_ANONYMOUS,  "MAP_ANONYMOUS",  ""},
    {MAP_SHARED,     "MAP_SHARED",     ""},
    {MAP_PRIVATE,    "MAP_PRIVATE",    ""},
    {MAP_FIXED,      "MAP_FIXED",      ""},
    {MAP_ANON,       "MAP_ANON",       ""},
    {MAP_DENYWRITE,  "MAP_DENYWRITE",  ""},
    {MAP_FILE,       "MAP_FILE",       ""},
    {MAP_GROWSDOWN,  "MAP_GROWSDOWN",  ""},
    {MAP_LOCKED,     "MAP_LOCKED",     ""},
    {MAP_NONBLOCK,   "MAP_NONBLOCK",   ""},
    {MAP_POPULATE,   "MAP_POPULATE",   ""},
    {MAP_NORESERVE,  "MAP_NORESERVE",  ""},
    {MAP_STACK,      "MAP_STACK",      ""}
  };

char 		*p_mmap2_map(int reg, pid_t pid)
{
  static char	buffer[NB_MMAP2_MAP * 13];
  int		c = 0;
  int		nchars = 0;

  (void)pid;
  while (c < NB_MMAP2_MAP)
    {
      if ((reg & mmap2_map[c].num) == mmap2_map[c].num)
	{
	  if (nchars)
	    nchars += sprintf(&(buffer[nchars]), "|");
	  nchars += sprintf(&(buffer[nchars]), "%s", mmap2_map[c].name);
	}
      c++;
    }
  return (buffer);
}
