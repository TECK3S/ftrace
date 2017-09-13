/*
** utilities7.c for <FTrace> in /home/barrau_a//c_avancee/ftrace
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:12:17 2011 adrien barrau
** Last update Fri Jun 24 16:12:18 2011 adrien barrau
*/

#include <sys/types.h>
#include <stdio.h>

char * p_struct_array_timespec(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Timespec>");
}

char * p_struct_array_sigevent(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<SigEvent>");
}

char * p_struct_array_mq_attr(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Mq_ATTR>");
}

char * p_kexec_load_flag(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<kexec_load_flag>");
}

char * p_mkdir_mode(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Mkdir mode>");
}
