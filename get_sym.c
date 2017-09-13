/*
** get_sym.c for <FTrace> in /home/barrau_a//c_avancee/ftrace_de_pneu
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sun Jul  3 13:43:47 2011 adrien barrau
** Last update Sun Jul  3 19:50:12 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/user.h>
#include "ftrace.h"

static bool	find_addr(const content_t cont1, const content_t cont2)
{
  int *		addr = (int *)cont1;
  t_symbol *	sym = (t_symbol *)cont2;

  if (*addr == sym->addr)
    return (true);
  return (false);
}

char *		get_sym_with_addr(int addr,
				  t_symbol_table symtab)
{
  t_symbol *	sym;

  sym = list_find(symtab, &addr, &find_addr);
  if (sym)
    return (sym->name);
  return (NULL);
}
