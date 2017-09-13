/*
** set_color.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Sun Jul  3 16:53:19 2011 arnaud1 tessa
** Last update Sun Jul  3 21:50:42 2011 arnaud1 tessa
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"dot.h"

void		set_color(t_dot_attributes *attr,
			  t_symbol_graph *head)
{
  if (head->symbol_type == SYSCALLS)
    {
      attr->color = strdup("grey");
    }
  else if (head->symbol_type == LOCAL_SYM)
    {
      attr->color = strdup("green");
    }
  else if (head->symbol_type == DYN_SYM)
    {
      attr->color = strdup("blue");
    }
  else if (head->symbol_type == SIGNAL_SENT)
    {
      attr->color = strdup("brown");
    }
  else if (head->symbol_type == SIGNAL_REC)
    {
      attr->color = strdup("orange");
    }
  else if (head->symbol_type == KILLED)
    {
      attr->color = strdup("red");
    }
  else
    {
      attr->color = strdup("white");
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
  set_color(&attr, &head);
  printf("%s\n", attr.color);
  return (0);
}
*/
