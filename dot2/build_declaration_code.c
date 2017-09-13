/*
** build_declaration_code.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Sun Jul  3 17:22:28 2011 arnaud1 tessa
** Last update Sun Jul  3 20:04:14 2011 arnaud1 tessa
*/

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	"dot.h"

int		get_declaration_len(t_dot_attributes *attr)
{
  int		len;
 
  len = strlen(attr->symbol_name) 
    + strlen(attr->label_name)
    + strlen(attr->label_params)
    + strlen(attr->shape)
    + strlen(attr->color)
    + 25;
  return (len);
}

void		fill_declaration(char *declaration,
				 t_dot_attributes *attr)
{
  strcpy(declaration, "\t");
  strcat(declaration, attr->symbol_name);
  strcat(declaration, "[");
  if (attr->label_name != NULL)
    {
      strcat(declaration, "label=");
      strcat(declaration, attr->label_name);
    }
  if (attr->shape != NULL)
    {
      strcat(declaration, ",shape=");
      strcat(declaration, attr->shape);
    }
  if (attr->color != NULL)
    {
      strcat(declaration, ",color=");
      strcat(declaration, attr->color);
    }
  strcat(declaration, "];\n");
}

char		*build_declaration_code(t_dot_attributes *attr)
{
  char		*declaration;
  int		len;

  len = get_declaration_len(attr);
  declaration = allocate_declaration(len);
  fill_declaration(declaration, attr);
  return (declaration);
}

/* 
int		main()
{
  t_dot_attributes	t;
  char			*res;

  res = malloc(1024);
  bzero(res, 1024);
  t.symbol_name = "s42";
  t.label_name = "b";
  t.label_params = "c";
  t.shape = "d";
  t.color = "e";
  fill_declaration(res, &t);
  printf("%s\n", res);
}
*/
