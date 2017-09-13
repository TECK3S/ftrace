/*
** set_symbol_name.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Sun Jul  3 12:28:55 2011 arnaud1 tessa
** Last update Sun Jul  3 20:03:48 2011 arnaud1 tessa
*/

#include	<stdio.h>
#include	"dot.h"

void		set_symbol_name(t_dot_attributes *attr,
				t_symbol_graph *head)
{
  attr->symbol_name = build_symbol_name(head);
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
  set_symbol_name(&attr, &head);
  printf("%s\n", attr.symbol_name);
}
*/

/*
** cc build_symbol_name.c int_to_str.c allocate_symbol_name.c fill_symbol_name.c set_symbol_name.c
*/
