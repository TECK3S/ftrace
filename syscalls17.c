/*
** syscalls1.c for <Ftrace> in /u/all/barrau_a/public/ftrace
**
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
**
** Started on  Wed May 11 19:58:13 2011 eugene-valentin ngontang-tchiadjie
** ast update Thu May 12 20:06:11 2011 eugene-valentin ngontang-tchiadjie
*/

#include <sys/types.h>
#include <sys/user.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "ftrace.h"
#include "list.h"

void	tr_getgroups(struct user_regs_struct * reg,
      enum mode the_mode,
      pid_t pid,
      t_symbol_graph * graph)
{
  static int nbChars = 0;
  t_symbol_graph * sym = NULL;
  extern int symbol_id;

  (void)pid;
  (void)reg;
  if (the_mode == PARAM)
    {
      sym = malloc(sizeof(*sym));
      sym->id = symbol_id++;
      sym->symbol_name = "getgroups";
      sym->symbol_addr = 0x00000000;
      sym->symbol_type = SYSCALLS;
      sym->debug_info = malloc(MAX_SYSCALLS_CHAR * sizeof(*sym->debug_info));
      nbChars = sprintf(sym->debug_info, "Parameters (%i, %p",
        (int)reg->ebx,
        (void *)reg->ecx);
      sym->sub_symbols = EMPTY;
      list_push_back(&graph->sub_symbols, sym);
    }
  else
    {
      sym = list_back(graph->sub_symbols);
      nbChars += sprintf(&(sym->debug_info[nbChars]), ")\nReturn");
      ((int)reg->eax <= -1 ?
        sprintf(&(sym->debug_info[nbChars]), "%s", p_error(reg->eax, pid))
       : sprintf(&(sym->debug_info[nbChars]), " (%i)", (int)reg->eax));
    }
}

void	tr_setgroups(struct user_regs_struct * reg,
      enum mode the_mode,
      pid_t pid,
      t_symbol_graph * graph)
{
  static int nbChars = 0;
  t_symbol_graph * sym = NULL;
  extern int symbol_id;

  (void)pid;
  (void)reg;
  if (the_mode == PARAM)
    {
      sym = malloc(sizeof(*sym));
      sym->id = symbol_id++;
      sym->symbol_name = "setgroups";
      sym->symbol_addr = 0x00000000;
      sym->symbol_type = SYSCALLS;
      sym->debug_info = malloc(MAX_SYSCALLS_CHAR * sizeof(*sym->debug_info));
      nbChars = sprintf(sym->debug_info, "Parameters (%u, %p",
        (size_t)reg->ebx,
        (void *)reg->ecx);
      sym->sub_symbols = EMPTY;
      list_push_back(&graph->sub_symbols, sym);
    }
  else
    {
      sym = list_back(graph->sub_symbols);
      nbChars += sprintf(&(sym->debug_info[nbChars]), ")\nReturn");
      ((int)reg->eax <= -1 ?
        sprintf(&(sym->debug_info[nbChars]), "%s", p_error(reg->eax, pid))
       : sprintf(&(sym->debug_info[nbChars]), " (%i)", (int)reg->eax));
    }
}

void	tr_select(struct user_regs_struct * reg,
      enum mode the_mode,
      pid_t pid,
      t_symbol_graph * graph)
{
  static int nbChars = 0;
  t_symbol_graph * sym = NULL;
  extern int symbol_id;

  (void)pid;
  (void)reg;
  if (the_mode == PARAM)
    {
      sym = malloc(sizeof(*sym));
      sym->id = symbol_id++;
      sym->symbol_name = "select";
      sym->symbol_addr = 0x00000000;
      sym->symbol_type = SYSCALLS;
      sym->debug_info = malloc(MAX_SYSCALLS_CHAR * sizeof(*sym->debug_info));
      nbChars = sprintf(sym->debug_info, "Parameters (%i, %s, %s, %s",
        (int)reg->ebx,
        p_struct_array_fd_set(reg->ecx, pid),
        p_struct_array_fd_set(reg->edx, pid),
        p_struct_array_timeval(reg->esi, pid));
      sym->sub_symbols = EMPTY;
      list_push_back(&graph->sub_symbols, sym);
    }
  else
    {
      sym = list_back(graph->sub_symbols);
      nbChars += sprintf(&(sym->debug_info[nbChars]), ")\nReturn");
      ((int)reg->eax <= -1 ?
        sprintf(&(sym->debug_info[nbChars]), "%s", p_error(reg->eax, pid))
       : sprintf(&(sym->debug_info[nbChars]), " (%i)", (int)reg->eax));
    }
}

void	tr_symlink(struct user_regs_struct * reg,
      enum mode the_mode,
      pid_t pid,
      t_symbol_graph * graph)
{
  static int nbChars = 0;
  t_symbol_graph * sym = NULL;
  extern int symbol_id;

  (void)pid;
  (void)reg;
  if (the_mode == PARAM)
    {
      sym = malloc(sizeof(*sym));
      sym->id = symbol_id++;
      sym->symbol_name = "symlink";
      sym->symbol_addr = 0x00000000;
      sym->symbol_type = SYSCALLS;
      sym->debug_info = malloc(MAX_SYSCALLS_CHAR * sizeof(*sym->debug_info));
      nbChars = sprintf(sym->debug_info, "Parameters (%s, %s",
        p_string(reg->ebx, pid),
        p_string(reg->ecx, pid));
      sym->sub_symbols = EMPTY;
      list_push_back(&graph->sub_symbols, sym);
    }
  else
    {
      sym = list_back(graph->sub_symbols);
      nbChars += sprintf(&(sym->debug_info[nbChars]), ")\nReturn");
      ((int)reg->eax <= -1 ?
        sprintf(&(sym->debug_info[nbChars]), "%s", p_error(reg->eax, pid))
       : sprintf(&(sym->debug_info[nbChars]), " (%i)", (int)reg->eax));
    }
}

void	tr_oldlstat(struct user_regs_struct * reg,
      enum mode the_mode,
      pid_t pid,
      t_symbol_graph * graph)
{
  static int nbChars = 0;
  t_symbol_graph * sym = NULL;
  extern int symbol_id;

  (void)pid;
  (void)reg;
  if (the_mode == PARAM)
    {
      sym = malloc(sizeof(*sym));
      sym->id = symbol_id++;
      sym->symbol_name = "oldlstat";
      sym->symbol_addr = 0x00000000;
      sym->symbol_type = SYSCALLS;
      sym->debug_info = malloc(MAX_SYSCALLS_CHAR * sizeof(*sym->debug_info));
      nbChars = sprintf(sym->debug_info, "Parameters (%s, %p",
        p_string(reg->ebx, pid),
        (void *)reg->ecx);
      sym->sub_symbols = EMPTY;
      list_push_back(&graph->sub_symbols, sym);
    }
  else
    {
      sym = list_back(graph->sub_symbols);
      nbChars += sprintf(&(sym->debug_info[nbChars]), ")\nReturn");
      ((int)reg->eax <= -1 ?
        sprintf(&(sym->debug_info[nbChars]), "%s", p_error(reg->eax, pid))
       : sprintf(&(sym->debug_info[nbChars]), " (%i)", (int)reg->eax));
    }
}

