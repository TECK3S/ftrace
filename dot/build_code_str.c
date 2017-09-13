/*
** build_code_str.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Wed Jun 29 18:48:55 2011 arnaud1 tessa
** Last update Wed Jun 29 19:26:19 2011 arnaud1 tessa
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"dot.h"

char		*build_code_str(char *head, char *sym)
{
  char		*code;
  int		len_head;
  int		len_sym;

  len_head = strlen(head);
  len_sym = strlen(sym);
  code = allocate_code_str(len_head + len_sym + 6);
  fill_dot_str(code, head, sym);
  return (code);
}

/*
int		main(int ac, char **av)
{
  char		*code;

  if (ac != 3)
    {
      printf("bad params\n");
      return (EXIT_FAILURE);
    }
  code = build_code_str(av[1], av[2]);
  printf("%s", code);
  return (EXIT_SUCCESS);
}
*/
