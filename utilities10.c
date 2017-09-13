/*
** utilities10.c for <FTrace> in /home/barrau_a//c_avancee/ftrace
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:28:45 2011 adrien barrau
** Last update Fri Jun 24 16:28:45 2011 adrien barrau
*/

#include <sys/types.h>
#include <stdio.h>

char * p_struct_array_robust_list_head(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Robust_list_head>");
}

char * p_splice_flag(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Splice Flag>");
}

char * p_sunc_file_range_flag(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Sunc_file_range Flag>");
}

char * p_tee_flag(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Tee Flag>");
}

char * p_struct_array_iovec(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Iovec>");
}
