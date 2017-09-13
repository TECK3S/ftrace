/*
** utilities11.c for <FTrace> in /home/barrau_a//c_avancee/ftrace
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:28:35 2011 adrien barrau
** Last update Fri Jun 24 16:28:35 2011 adrien barrau
*/

#include <sys/types.h>
#include <stdio.h>

char * p_recvmsg_flag(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<recvmsg_flag>");
}

char * p_vmsplice_flag(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<vmsplice_flag>");
}

char * p_move_pages_flag(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<move_pages_flag>");
}

char * p_struct_array_epoll_event(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<epoll_event>");
}

char * p_utimensat_flag(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<utimensat_flag>");
}
