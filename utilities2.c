/*
** utilities2.c for <FTrace> in /home/barrau_a//c_avancee/ftrace
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:13:15 2011 adrien barrau
** Last update Fri Jun 24 16:13:21 2011 adrien barrau
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/mount.h>
#include "ftrace.h"

char *	p_argv(int reg, pid_t pid)
{
  static char		buffer[20 * 1024];
  int			c = 1;
  int			nchars = 0;
  int			ptr = 0;

  ptr = ptrace(PTRACE_PEEKDATA, pid, (reg), NULL);
  nchars += sprintf(&(buffer[nchars]), "[");
  while (ptr != 0 && ptr != -1 && c < 17)
    {
      if (nchars > 1)
	nchars += sprintf(&(buffer[nchars]), ", ");
      nchars += sprintf(&(buffer[nchars]), "%s", p_string(ptr, pid));
      ptr = ptrace(PTRACE_PEEKDATA, pid, (reg + (4 * c)), NULL);
      c++;
    }
  if (c == 17)
    nchars += sprintf(&(buffer[nchars]), ", ...");
  nchars += sprintf(&(buffer[nchars]), "]");
  return (buffer);
}

char * p_env(int reg, pid_t pid)
{
  static char		buffer[100];
  int			c = 1;
  int			nchars = 0;
  int			ptr = 0;

  ptr = ptrace(PTRACE_PEEKDATA, pid, (reg), NULL);
  while (ptr != 0 && ptr != -1)
    {
      ptr = ptrace(PTRACE_PEEKDATA, pid, (reg + (4 * c)), NULL);
      c++;
    }
  if (c == 2)
    nchars += sprintf(&(buffer[nchars]), VAR_SING, c - 1);
  else
    nchars += sprintf(&(buffer[nchars]), VAR_PLU, c - 1);
  return (buffer);
}

static t_mknod_mode	mk_mod[]=
  {
    {S_IFREG,  "S_IFREG",  ""},
    {S_IFCHR,  "S_IFCHR",  ""},
    {S_IFBLK,  "S_IFBLK",  ""},
    {S_IFIFO,  "S_IFIFO",  ""},
    {S_IFSOCK, "S_IFSOCK", ""},
  };

char * p_mknod_mode(int reg, pid_t pid)
{
  static char	buffer[NB_MKNOD_MODE * 15];
  int		c = 0;
  int		nchars = 0;

  (void)pid;
  while (c < NB_MKNOD_MODE)
    {
      if ((reg & mk_mod[c].num) == mk_mod[c].num)
	{
	  if (nchars)
	    nchars += sprintf(&(buffer[nchars]), "|");
	  nchars += sprintf(&(buffer[nchars]), "%s", mk_mod[c].name);
	}
      c++;
    }
  if (!nchars)
    nchars += sprintf(&(buffer[nchars]), "0");
  return (buffer);
}

static t_whence		whence[]=
  {
    {SEEK_SET, "SEEK_SET", ""},
    {SEEK_CUR, "SEEK_CUR", ""},
    {SEEK_END, "SEEK_END", ""}
  };

char * p_seek_whence(int reg, pid_t pid)
{
  static char	buffer[NB_WHENCE * 15];
  int		c = 0;
  int		nchars = 0;

  (void)pid;
  while (c < NB_WHENCE)
    {
      if ((reg & whence[c].num) == whence[c].num)
	{
	  if (nchars)
	    nchars += sprintf(&(buffer[nchars]), "|");
	  nchars += sprintf(&(buffer[nchars]), "%s", whence[c].name);
	}
      c++;
    }
  if (!nchars)
    nchars += sprintf(&(buffer[nchars]), "0");
  return (buffer);
}

static t_mount_flag	m_flags[]=
  {
    {MS_BIND, "MS_BIND", ""},
    {MS_DIRSYNC, "MS_DIRSYNC", ""},
    {MS_MANDLOCK, "MS_MANDLOCK", ""},
    {MS_MOVE, "MS_MOVE", ""},
    {MS_NOATIME, "MS_NOATIME", ""},
    {MS_NODEV, "MS_NODEV", ""},
    {MS_NODIRATIME, "MS_NODIRATIME", ""},
    {MS_NOEXEC, "MS_NOEXEC", ""},
    {MS_NOSUID, "MS_NOSUID", ""},
    {MS_RDONLY, "MS_RDONLY", ""},
    {MS_RELATIME, "MS_RELATIME", ""},
    {MS_REMOUNT, "MS_REMOUNT", ""},
    {MS_SILENT, "MS_SILENT", ""},
    {MS_STRICTATIME, "MS_STRICTATIME", ""},
    {MS_SYNCHRONOUS, "MS_SYNCHRONOUS", ""}
  };

char *	p_mount_flags(int reg, pid_t pid)
{
  static char	buffer[NB_MOUNT_FLAG * 15];
  int		c = 0;
  int		nchars = 0;

  (void)pid;
  while (c < NB_MOUNT_FLAG)
    {
      if ((reg & m_flags[c].num) == m_flags[c].num)
	{
	  if (nchars)
	    nchars += sprintf(&(buffer[nchars]), "|");
	  nchars += sprintf(&(buffer[nchars]), "%s", m_flags[c].name);
	}
      c++;
    }
  if (!nchars)
    nchars += sprintf(&(buffer[nchars]), "0");
  return (buffer);
}
