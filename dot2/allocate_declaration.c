/*
** allocate_declaration.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Sun Jul  3 11:41:40 2011 arnaud1 tessa
** Last update Sun Jul  3 19:32:54 2011 arnaud1 tessa
*/

#include	<strings.h>
#include	<stdlib.h>
#include	<stdio.h>

char		*allocate_declaration(int len)
{
  char		*res;

  res = malloc(len + 1);
  bzero(res, len + 1);
  if (res == NULL)
    {
      printf("malloc failed in allocate_declaration\n");
      exit(EXIT_FAILURE);
    }
  return (res);
}

/*
** too simple to be tested
*/
