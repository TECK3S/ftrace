/*
** utilities5.c for <FTrace> in /home/barrau_a//c_avancee/ftrace
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:12:37 2011 adrien barrau
** Last update Fri Jun 24 16:12:37 2011 adrien barrau
*/

#include <sys/types.h>
#include <stdio.h>

char *	p_ustat_dev(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Ustat Dev>");
}

char *	p_umask_mod(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Umask Mod>");
}

char *	p_struct_array_fd_set(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Struct fd_set>");
}

char *	p_struct_array_timeval(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Timeval>");
}

char *	p_fchmod_mod(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Fchmod>");
}
