/*
** dot.h for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Wed Jun 29 19:21:24 2011 arnaud1 tessa
** Last update Sun Jul  3 20:07:03 2011 arnaud1 tessa
*/

#ifndef		__DOT_H__
#define		__DOT_H__

#include	"list.h"
#include	"ftrace.h"

typedef struct	s_label
{
  char		*name;
  char		*params;
}		t_label;

typedef struct	s_dot_attributes
{
  char		*symbol_name;
  char		*label_name;
  char		*label_params;
  char		*shape;
  char		*color;
}		t_dot_attributes;

void		fill_symbol_name(char *symbol_name,
				 char *nbr);
void		set_color(t_dot_attributes *attr,
			  t_symbol_graph *head);
void		set_shape(t_dot_attributes *attr,
			  t_symbol_graph *head);
void		set_label(t_dot_attributes *attr,
			  t_symbol_graph *head);
char		*build_declaration_code(t_dot_attributes *attr);
void		set_symbol_name(t_dot_attributes *attr,
				t_symbol_graph *head);
void		set_declaration_attributes(t_dot_attributes *attr,
					   t_symbol_graph *head);
char		*build_declaration(t_symbol_graph *head);
char		*build_code_str(char *head, char *sym);
char		*allocate_code_str(int len);
void		fill_dot_str(char *code, char *head, char *sym);
char		*build_code(t_symbol_graph *head, t_symbol_graph *sym);
void		print_file(int fd, char *line);
void		build_and_print_file(content_t* cont, 
				     param_t param1,
				     param_t param2);
void		build_dot(content_t * cont, 
			  param_t param1);
void		build_level(t_symbol_graph *tree, int *fd);
void		build_sub_levels(t_list * list, param_t p);
int		init_dot_file();
void		generate_dot_file(t_symbol_graph *tree);
void		close_dot_file(int fd);
char		*int_to_str(int symbol_num);
char		*allocate_symbol_name(int len);
char		*build_symbol_name(t_symbol_graph *sym);
char		*allocate_declaration(int len);

#endif		/*__DOT_H__*/
