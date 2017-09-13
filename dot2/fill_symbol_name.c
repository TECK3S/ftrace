/*
** fill_symbol_name.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Sun Jul  3 13:31:24 2011 arnaud1 tessa
** Last update Sun Jul  3 20:06:57 2011 arnaud1 tessa
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<strings.h>
#include	<string.h>

void		fill_symbol_name(char *symbol_name,
				 char *nbr)
{
  symbol_name[0] = 's';
  symbol_name[1] = '\0';
  strcat(symbol_name, nbr);
}

/*
int		main(int ac, char **av)
{
  char		name[128];
  
  if (ac != 2)
    {
      printf("bad params\n");
      exit(EXIT_FAILURE);
    }
  bzero(name, 128);
  fill_symbol_name(name, av[1]);
  printf("%s\n", name);
}
*/
