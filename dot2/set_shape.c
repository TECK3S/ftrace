/*
** set_shape.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Sun Jul  3 14:21:09 2011 arnaud1 tessa
** Last update Sun Jul  3 20:06:11 2011 arnaud1 tessa
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"dot.h"

void		set_shape(t_dot_attributes *attr,
			  t_symbol_graph *head)
{
  if (head->symbol_type == SYSCALLS)
    {
      attr->shape = strdup("doublecircle");
    }
  else if (head->symbol_type == LOCAL_SYM)
    {
      attr->shape = strdup("ellipse");
    }
  else if (head->symbol_type == DYN_SYM)
    {
      attr->shape = strdup("egg");
    }
  else if (head->symbol_type == SIGNAL_SENT)
    {
      attr->shape = strdup("rectangle");
    }
  else if (head->symbol_type == SIGNAL_REC)
    {
      attr->shape = strdup("hexagon");
    }
  else if (head->symbol_type == KILLED)
    {
      attr->shape = strdup("tripleoctagon");
    }
  else
    {
      attr->shape = strdup("none");
    }
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
  head.symbol_type = atoi(av[1]);
  set_shape(&attr, &head);
  printf("%s\n", attr.shape);
  return (0);
}
*/
