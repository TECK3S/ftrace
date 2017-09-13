/*
** dot.h for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Wed Jun 29 19:21:24 2011 arnaud1 tessa
** Last update Sun Jul  3 12:45:34 2011 arnaud1 tessa
*/

#ifndef		__DOT_H__
#define		__DOT_H__

#include	"list.h"
#include	"ftrace.h"

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

#endif		/*__DOT_H__*/
