/*
** utilities12.c for <FTrace> in /home/barrau_a//c_avancee/ftrace
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:28:22 2011 adrien barrau
** Last update Fri Jun 24 16:28:23 2011 adrien barrau
*/

#include <sys/types.h>
#include <stdio.h>

char * p_signalfd_flag(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Signalfd flag>");
}

char * p_timerfd_create_flag(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Timerfd_create flag>");
}

char * p_eventfd_flag(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Eventfd flag>");
}

char * p_timerfd_settime_flag(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Timerfd_settime flag>");
}

char * p_struct_array_itimerspec(int reg, pid_t pid)
{
  (void)(reg);
  (void)(pid);
  return ("<Itimerspec>");
}
