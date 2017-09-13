/*
** utilities4.c for <FTrace> in /home/barrau_a//c_avancee/ftrace
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:12:47 2011 adrien barrau
** Last update Fri Jun 24 16:12:47 2011 adrien barrau
*/

#include <sys/types.h>
#include <stdio.h>

char *	p_sighandler(pid_t pid)
{
  (void)pid;
  return ("<Sighandler>");
}

char * p_umount2_flag(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Umount2 Flag>");
}

char * p_ioctl_req(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Ioctl Request>");
}

char * p_fcntl_req(int reg, pid_t pid)
{
  (void)pid;
  (void)reg;
  return ("<Fcntl Request>");
}

char *  p_mknod_dev(int reg, pid_t pid)
{
  static char	buffer[50];

  (void)pid;
  sprintf(buffer, "makedev(%i, %i)", major(reg), minor(reg));
  return (buffer);
}
