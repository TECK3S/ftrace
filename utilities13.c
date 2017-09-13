/*
** utilities13.c for <FTrace> in /home/barrau_a//c_avancee/ftrace
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:28:16 2011 adrien barrau
** Last update Fri Jun 24 16:28:16 2011 adrien barrau
*/

#include <sys/types.h>
#include <stdio.h>

char * p_epoll_create1_flag(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Epoll_create1 flag>");
}

char * p_dup3_flag(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Dup3 flag>");
}

char * p_int_array(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Int_array>");
}

char * p_pipe1_flag(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Pipe1 flag>");
}

char * p_inotify_init1_flag(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Inotify_init1 flag>");
}
