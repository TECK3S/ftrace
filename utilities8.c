/*
** utilities8.c for <FTrace> in /home/barrau_a//c_avancee/ftrace
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:12:10 2011 adrien barrau
** Last update Fri Jun 24 16:12:11 2011 adrien barrau
*/

#include <sys/types.h>
#include <stdio.h>

char * p_chown_flag(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Chown Flag>");
}

char * p_stat_flag(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Stat Flag>");
}

char * p_link_flag(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Link Flag>");
}

char * p_chmod_mode(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Chmod Mode>");
}

char * p_chmod_flag(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Chmod Flag>");
}
