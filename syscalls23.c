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

void	tr_iopl(struct user_regs_struct * reg,
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
      sym->symbol_name = "iopl";
      sym->symbol_addr = 0x00000000;
      sym->symbol_type = SYSCALLS;
      sym->debug_info = malloc(MAX_SYSCALLS_CHAR * sizeof(*sym->debug_info));
      nbChars = sprintf(sym->debug_info, "Parameters (%i",
        (int)reg->ebx);
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

void	tr_vhangup(struct user_regs_struct * reg,
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
      sym->symbol_name = "vhangup";
      sym->symbol_addr = 0x00000000;
      sym->symbol_type = SYSCALLS;
      sym->debug_info = malloc(MAX_SYSCALLS_CHAR * sizeof(*sym->debug_info));
      nbChars = sprintf(sym->debug_info, "Parameters (");
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

void	tr_idle(struct user_regs_struct * reg,
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
      sym->symbol_name = "idle";
      sym->symbol_addr = 0x00000000;
      sym->symbol_type = SYSCALLS;
      sym->debug_info = malloc(MAX_SYSCALLS_CHAR * sizeof(*sym->debug_info));
      nbChars = sprintf(sym->debug_info, "Parameters (");
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

void	tr_vm86old(struct user_regs_struct * reg,
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
      sym->symbol_name = "vm86old";
      sym->symbol_addr = 0x00000000;
      sym->symbol_type = SYSCALLS;
      sym->debug_info = malloc(MAX_SYSCALLS_CHAR * sizeof(*sym->debug_info));
      nbChars = sprintf(sym->debug_info, "Parameters (%s",
        p_vm86old_struct(reg->ebx, pid));
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

void	tr_wait4(struct user_regs_struct * reg,
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
      sym->symbol_name = "wait4";
      sym->symbol_addr = 0x00000000;
      sym->symbol_type = SYSCALLS;
      sym->debug_info = malloc(MAX_SYSCALLS_CHAR * sizeof(*sym->debug_info));
      nbChars = sprintf(sym->debug_info, "Parameters (%i, %p, %s, %p",
        (int)reg->ebx,
        (void *)reg->ecx,
        p_waitpid_option(reg->edx, pid),
        (void *)reg->esi);
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

