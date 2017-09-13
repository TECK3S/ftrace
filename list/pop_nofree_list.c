/*
** pop_nofree_list.c for <Pop nofree list> in /home/barrau_a//c/zappy_delamort/server
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Tue Jun 21 21:00:00 2011 adrien barrau
** Last update Tue Jun 28 17:56:44 2011 adrien barrau
*/

#include <stdlib.h>
#include "list.h"

bool		list_pop_nofree_front(t_list * list)
{
  t_node *	to_pop = NULL;

  if (*list == NULL)
    return (false);
  to_pop = *list;
  *list = (*list)->next;
  free(to_pop);
  return (true);
}

bool		list_pop_nofree_back(t_list * list)
{
  t_node *	to_pop = *list;
  t_node *	prev = NULL;

  if (*list == NULL)
    return (false);
  while (to_pop->next != NULL)
    {
      prev = to_pop;
      to_pop = to_pop->next;
    }
  if (prev != NULL)
    prev->next = NULL;
  else
    *list = NULL;
  free(to_pop);
  return (true);
}

bool		list_pop_nofree_at(t_list * list, pos_t position)
{
  t_node *	to_pop = *list;
  t_node *	prev = NULL;
  pos_t		cur_pos = 1;

  if (*list == NULL)
    return (false);
  while (to_pop->next != NULL)
    {
      if (cur_pos == position)
	break;
      prev = to_pop;
      to_pop = to_pop->next;
      ++cur_pos;
    }
  if (prev != NULL)
    prev->next = to_pop->next;
  else
    *list = to_pop->next;
  free(to_pop);
  return (true);
}

bool		list_remove_nofree(t_list * list,
				   const content_t ref,
				   bool (*cmp_cont)(const content_t cont1,
						    const content_t cont2))
{
  t_node *	to_pop = *list;
  t_node *	prev = NULL;

  while (to_pop != NULL)
    {
      if (cmp_cont(ref, to_pop->cont))
	{
	  if (prev != NULL)
	    prev->next = to_pop->next;
	  else
	    *list = to_pop->next;
	  free(to_pop);
	  return (true);
	}
      prev = to_pop;
      to_pop = to_pop->next;
    }
  return (false);
}

bool		list_remove_nofree2(t_list * list,
				    const content_t ref,
				    param_t p,
				    bool (*cmp_cont)(const content_t cont1,
						     const content_t cont2,
						     param_t p))
{
  t_node *	to_pop = *list;
  t_node *	prev = NULL;

  while (to_pop != NULL)
    {
      if (cmp_cont(ref, to_pop->cont, p))
	{
	  if (prev != NULL)
	    prev->next = to_pop->next;
	  else
	    *list = to_pop->next;
	  free(to_pop);
	  return (true);
	}
      prev = to_pop;
      to_pop = to_pop->next;
    }
  return (false);
}
