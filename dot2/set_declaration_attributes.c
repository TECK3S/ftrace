/*
** set_declaration_attributes.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Sun Jul  3 12:23:49 2011 arnaud1 tessa
** Last update Sun Jul  3 20:03:15 2011 arnaud1 tessa
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"dot.h"

void		set_declaration_attributes(t_dot_attributes *attr,
					   t_symbol_graph *head)
{
  set_symbol_name(attr, head);
  set_label(attr, head);
  set_shape(attr, head);
  set_color(attr, head);
}

/*
int		main(int ac, char **av)
{
  t_dot_attributes	attr;
  t_symbol_graph	head;
  char			*symbol_name;

  if (ac != 2)
    {
      printf("bad params\n");
      return (1);
    }
  head.id = atoi(av[1]);  
  head.symbol_name = "printf";
  head.symbol_type = SYSCALLS;
  head.debug_info = "toto titi tata";
  set_declaration_attributes(&attr, &head);
  return (0);
}
*/
 /*
 ** cc set* build_symbol_name.c int_to_str.c allocate_symbol_name.c fill_symbol_name.c
 */
