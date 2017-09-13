/*
** allocate_symbol_name.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Sun Jul  3 13:26:36 2011 arnaud1 tessa
** Last update Sun Jul  3 13:49:36 2011 arnaud1 tessa
*/

#include	<stdio.h>
#include	<stdlib.h>

char		*allocate_symbol_name(int len)
{
  char		*res;
    
  res = malloc(len);
  if (res == NULL)
    {
      printf("malloc failed in allocate_symbol_name\n");
      exit(EXIT_FAILURE);
    }
  return (res);
}

/*
** too simple to be tested
*/
