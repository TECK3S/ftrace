/*
** build_and_print_file.c for  in /home/tessa_b//proj/ftrace
** 
** Made by arnaud1 tessa
** Login   <tessa_b@epitech.net>
** 
** Started on  Wed Jun 29 20:22:42 2011 arnaud1 tessa
** Last update Sun Jul  3 21:17:49 2011 arnaud1 tessa
*/

#include	<unistd.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	"ftrace.h"
#include	"dot.h"

void		build_and_print_file(content_t * cont, 
				     param_t param1,
				     param_t param2)
{
  int			fd;
  t_symbol_graph	*head;
  t_symbol_graph	*sym;
  char			*code;

  fd = *((int*) param2);
  head = (t_symbol_graph *) param1;
  sym = *((t_symbol_graph **) cont);
  code = build_code(head, sym);
  if (code != NULL)
    {
      print_file(fd, code);
      free(code);
    }
}

/*
int			main()
{
  int			fd;
  t_symbol_graph	s;
  t_symbol_graph	s1;
  t_symbol_graph	*addr_s1;

  s.symbol_name = "start";
  s.symbol_addr = 0x80f;
  s.symbol_type = SYSCALLS;
  s.debug_info = NULL;
  s.sub_symbols = NULL;
  
  s1.symbol_name = "read";
  s1.symbol_addr = 0x80f;
  s1.symbol_type = SYSCALLS;
  s1.debug_info = NULL;
  s1.sub_symbols = NULL;

  addr_s1 = &s1;

  fd = open("graph.dot", O_CREAT | O_RDWR);
  build_and_print_file((void **)&addr_s1, &s, &fd);
  close(fd);

  return (EXIT_SUCCESS);
}
*/
