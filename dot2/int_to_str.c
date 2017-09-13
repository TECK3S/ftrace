/*
** int_to_str.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Sun Jul  3 13:14:41 2011 arnaud1 tessa
** Last update Sun Jul  3 20:00:48 2011 arnaud1 tessa
*/

#include	<stdlib.h>
#include	<stdio.h>

char		*int_to_str(int symbol_num)
{
  char		*nbr;

  nbr = malloc(11 * sizeof(*nbr));
  if (nbr == NULL)
    {
      printf("malloc failed in function int_to_str");
      exit(EXIT_FAILURE);
    }
  snprintf(nbr, 11, "%d", symbol_num);
  return (nbr);
}

/*
int		main(int ac, char **av)
{
  char		*res;
  
  if (ac != 2)
    {
      printf("bad Params\n");
      return (1);
    }
  res = int_to_str(atoi(av[1]));
  printf("%s\n", res);
}
*/
