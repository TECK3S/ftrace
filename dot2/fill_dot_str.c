/*
** fill_dot_str.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Wed Jun 29 19:20:04 2011 arnaud1 tessa
** Last update Wed Jun 29 19:22:34 2011 arnaud1 tessa
*/

#include	<string.h>

void		fill_dot_str(char *code, char *head, char *sym)
{
  code[0] = '\0';
  strcat(code, "\t");
  strcat(code, head);
  strcat(code, "->");
  strcat(code, sym);
  strcat(code, ";\n");
}
