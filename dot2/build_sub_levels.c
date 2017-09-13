/*
** build_sub_levels.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Wed Jun 29 22:40:47 2011 arnaud1 tessa
** Last update Wed Jun 29 22:45:07 2011 arnaud1 tessa
*/

#include	"list.h"
#include	"dot.h"

void		build_sub_levels(t_list * list, param_t p)
{
  list_iter(list, p, build_dot);
}
