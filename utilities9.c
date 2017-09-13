/*
** utilities9.c for <FTrace> in /home/barrau_a//c_avancee/ftrace
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:11:54 2011 adrien barrau
** Last update Fri Jun 24 16:11:55 2011 adrien barrau
*/

#include <sys/types.h>
#include <stdio.h>

char * p_access_flag(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Access Flag>");
}

char * p_struct_array_fdset(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Fdset>");
}

char * p_struct_array_sigset_t(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Sigset_t>");
}

char * p_struct_array_pollfd(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Pollfd>");
}

char * p_unshare_flag(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Unshare Flag>");
}
