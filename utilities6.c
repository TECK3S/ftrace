/*
** utilities6.c for <FTrace> in /home/barrau_a//c_avancee/ftrace
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:12:28 2011 adrien barrau
** Last update Fri Jun 24 16:12:28 2011 adrien barrau
*/

#include <sys/types.h>
#include <stdio.h>

char * p_struct_array_itimerval(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Itimerval>");
}

char * p_bind_mode(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Bind Mode>");
}

char * p_bind_flag(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Bind Flag>");
}

char * p_set_mempolicy_flags(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Set_Mempolicy_flags>");
}

char * p_set_mempolicy_mode(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Set_Mempolicy_mode>");
}
