/*
** build_symbol_name.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Sun Jul  3 12:32:11 2011 arnaud1 tessa
** Last update Sun Jul  3 14:02:43 2011 arnaud1 tessa
*/

#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"ftrace.h"
#include	"dot.h"

char		*build_symbol_name(t_symbol_graph *sym)
{
  char		*symbol_name;
  char		*nbr;
  int		id;

  id = sym->id;
  nbr = int_to_str(id);
  symbol_name = allocate_symbol_name(strlen(nbr) + 2);
  fill_symbol_name(symbol_name, nbr);
  free(nbr);
  return (symbol_name);
}

/*
int		main(int ac, char **av)
{
  t_symbol_graph	t;
  char			*symbol_name;

  if (ac != 2)
    {
      printf("bad params\n");
      return (1);
    }
  t.id = atoi(av[1]);
  symbol_name = build_symbol_name(&t);
  printf("%s\n", symbol_name);
}
*/

 /*
 ** cc build_symbol_name.c int_to_str.c allocate_symbol_name.c fill_symbol_name.c
 */
