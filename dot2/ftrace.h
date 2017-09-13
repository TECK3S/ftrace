/*
** ftrace.h for <FTrace> in /home/barrau_a//c_avancee/ftrace/includes
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:30:13 2011 adrien barrau
** Last update Sun Jul  3 12:25:03 2011 arnaud1 tessa
*/

#ifndef FTRACE_H_
# define FTRACE_H_

# include "list.h"

# define OPTION_P		("-p")

# define USAGE			("./ftrace [-p PID] | BIN\n")

# define BAD_ARGS_ERR_CODE	(-1)
# define FORK_ERR_CODE		(-2)
# define PTRACE_ERR_CODE	(-3)

# define FORK_ERR_MSG		("ftrace : Error : Cannot Fork Exiting..\n")
# define PTRACE_ERR_MSG		("ftrace : Error : Ptrace failed\n")

# define NUM_SYSCALLS		(337)

# define TOTAL_WIDTH		(38)

# define NB_SIGNALS		(30)
# define NO_SIGNAL		(0)

# define NB_ERRNO		(120)

# define STRSIZE		(32)

# define NB_OPEN_FLAG		(15)
# define NB_OPEN_MODE		(12)
# define NB_WAIT_OPT		(3)
# define NB_MKNOD_MODE		(5)
# define NB_WHENCE		(3)
# define NB_MOUNT_FLAG		(15)
# define NB_PTRACE_REQ		(21)
# define NB_ACCESS_MODE		(4)

# define VAR_SING		("[/* %i var */]")
# define VAR_PLU		("[/* %i vars */]")

enum mode
  {
    PARAM = 0,
    RETURN
  };

union		char_disturbed
{
  unsigned int	_char;
  unsigned char	_disturbed[4];
};

enum eSymbolType
  {
    UNKNOWN = 0,
    SYSCALLS,
    LOCAL_SYM,
    DYN_SYM,
    SIGNAL_SENT,
    SIGNAL_REC,
    KILLED
  };

typedef struct
{
  int			id;
  char *		symbol_name;
  int			symbol_addr;
  enum eSymbolType	symbol_type;
  char *		debug_info;
  t_list		sub_symbols;
}			t_symbol_graph;

typedef	struct	s_signals
{
  int		num;
  char *	name;
  char *	desc;
}		t_signals;

#endif /* !FTRACE_H_ */
