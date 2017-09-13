/*
** build_declaration.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Sun Jul  3 12:11:43 2011 arnaud1 tessa
** Last update Sun Jul  3 23:29:00 2011 arnaud1 tessa
*/

#include	<string.h>
#include	<stdlib.h>
#include	<strings.h>
#include	"dot.h"
#include	"ftrace.h"

char		*build_declaration(t_symbol_graph *head)
{
  t_dot_attributes	attr;
  char			*declaration;

  set_declaration_attributes(&attr, head);
  /*declaration = build_declaration_code(&attr);*/
  declaration = strdup("\0");
  return (declaration);
}
