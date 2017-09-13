/*
** build_code.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Wed Jun 29 19:27:10 2011 arnaud1 tessa
** Last update Sun Jul  3 22:45:24 2011 arnaud1 tessa
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"ftrace.h"
#include	"dot.h"

char		*build_code(t_symbol_graph *head, t_symbol_graph *sym)
{
  char		*code;
  char		*head_str;
  char		*sym_str;

  head_str = build_symbol_name(head);
  sym_str = build_symbol_name(sym);
  if ((head_str != NULL)
      && (sym_str != NULL))
    {
      code = build_code_str(head_str, sym_str);
    }
  else
    {
      code = NULL;
    }
  return (code);
}

/*
int			main()
{
  char			*code;
  t_symbol_graph	s;
  t_symbol_graph	s1;

  s.symbol_name = "start";
  s.symbol_addr = 0x80f;
  s.symbol_type = SYSCALLS;
  s.debug_info = NULL;
  s.sub_symbols = NULL;
  
  s1.symbol_name = "read";
  s1.symbol_addr = 0x80f;
  s1.symbol_type = SYSCALLS;
  s1.debug_info = NULL;
  s1.sub_symbols = NULL;

  code = build_code(&s, &s1);
  printf("%s", code);

  return (EXIT_SUCCESS);
}
*/
