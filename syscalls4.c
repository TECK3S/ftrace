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

void	tr_chmod(struct user_regs_struct * reg,
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
      sym->symbol_name = "chmod";
      sym->symbol_addr = 0x00000000;
      sym->symbol_type = SYSCALLS;
      sym->debug_info = malloc(MAX_SYSCALLS_CHAR * sizeof(*sym->debug_info));
      nbChars = sprintf(sym->debug_info, "Parameters (%s, %s",
        p_string(reg->ebx, pid),
        p_open_mode(reg->ecx, pid));
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

void	tr_lchown(struct user_regs_struct * reg,
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
      sym->symbol_name = "lchown";
      sym->symbol_addr = 0x00000000;
      sym->symbol_type = SYSCALLS;
      sym->debug_info = malloc(MAX_SYSCALLS_CHAR * sizeof(*sym->debug_info));
      nbChars = sprintf(sym->debug_info, "Parameters (%s, %i, %i",
        p_string(reg->ebx, pid),
        (int)reg->ecx,
        (int)reg->edx);
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

void	tr_break(struct user_regs_struct * reg,
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
      sym->symbol_name = "break";
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

void	tr_oldstat(struct user_regs_struct * reg,
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
      sym->symbol_name = "oldstat";
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

void	tr_lseek(struct user_regs_struct * reg,
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
      sym->symbol_name = "lseek";
      sym->symbol_addr = 0x00000000;
      sym->symbol_type = SYSCALLS;
      sym->debug_info = malloc(MAX_SYSCALLS_CHAR * sizeof(*sym->debug_info));
      nbChars = sprintf(sym->debug_info, "Parameters (%i, %u, %s",
        (int)reg->ebx,
        (unsigned int)reg->ecx,
        p_seek_whence(reg->edx, pid));
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

