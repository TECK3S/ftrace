/*
** allocate_code_str.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Wed Jun 29 19:19:14 2011 arnaud1 tessa
** Last update Wed Jun 29 19:22:19 2011 arnaud1 tessa
*/

#include	<stdlib.h>
#include	<stdio.h>

char		*allocate_code_str(int len)
{
  char		*res;

  res = malloc(len);
  if (res == NULL)
    {
      printf("malloc failed in allocate_code_str\n");
    }
  return (res);
}
