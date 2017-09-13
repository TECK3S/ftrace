/*
** set_label.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Sun Jul  3 14:06:35 2011 arnaud1 tessa
** Last update Sun Jul  3 20:05:47 2011 arnaud1 tessa
*/

#include	<stdio.h>
#include	"ftrace.h"
#include	"dot.h"

void		set_label(t_dot_attributes *attr,
			  t_symbol_graph *head)
{
  attr->label_name = head->symbol_name;
  attr->label_params = head->debug_info;
}

/*
int		main(int ac, char **av)
{
  t_dot_attributes	attr;
  t_symbol_graph	head;
  char			*symbol_name;

  if (ac != 3)
    {
      printf("bad params\n");
      return (1);
    }
  head.symbol_name = av[1];
  head.debug_info = av[2];
  set_label(&attr, &head);
  printf("%s%s", attr.label_name, attr.label_params);
  return (0);
}
*/
