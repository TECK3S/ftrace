/*
** call_ff_mgr.c for <FTrace> in /home/barrau_a//c_avancee/ftrace_de_pneu
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sun Jul  3 20:56:20 2011 adrien barrau
** Last update Sun Jul  3 22:50:32 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/user.h>
#include "ftrace.h"

static void	slash2_10(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip __attribute__((unused)))
{
  int	addr;

  addr = ptrace(PTRACE_PEEKDATA, pid, regs->eax);
  insert_node(graph, symtab, addr, LOCAL_SYM, "");
}

static void	slash2_11(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip __attribute__((unused)))
{
  int	addr;

  addr = ptrace(PTRACE_PEEKDATA, pid, regs->ecx);
  insert_node(graph, symtab, addr, LOCAL_SYM, "");
}

static void	slash2_12(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip __attribute__((unused)))
{
  int	addr;

  addr = ptrace(PTRACE_PEEKDATA, pid, regs->edx);
  insert_node(graph, symtab, addr, LOCAL_SYM, "");
}

static void	slash2_13(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip __attribute__((unused)))
{
  int	addr;

  addr = ptrace(PTRACE_PEEKDATA, pid, regs->ebx);
  insert_node(graph, symtab, addr, LOCAL_SYM, "");
}

static void	slash2_14(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip)
{
  (void)regs;
  (void)pid;
  (void)graph;
  (void)symtab;
  (void)eip;
}

static void	slash2_15(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip)
{
  (void)regs;
  (void)pid;
  (void)graph;
  (void)symtab;
  (void)eip;
}

static void	slash2_16(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip __attribute__((unused)))
{
  int	addr;

  addr = ptrace(PTRACE_PEEKDATA, pid, regs->esi);
  insert_node(graph, symtab, addr, LOCAL_SYM, "");
}

static void	slash2_17(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip __attribute__((unused)))
{
  int	addr;

  addr = ptrace(PTRACE_PEEKDATA, pid, regs->edi);
  insert_node(graph, symtab, addr, LOCAL_SYM, "");
}

static void	slash2_50(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip)
{
  (void)regs;
  (void)pid;
  (void)graph;
  (void)symtab;
  (void)eip;
}

static void	slash2_51(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip)
{
  (void)regs;
  (void)pid;
  (void)graph;
  (void)symtab;
  (void)eip;
}

static void	slash2_52(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip)
{
  (void)regs;
  (void)pid;
  (void)graph;
  (void)symtab;
  (void)eip;
}

static void	slash2_53(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip)
{
  (void)regs;
  (void)pid;
  (void)graph;
  (void)symtab;
  (void)eip;
}

static void	slash2_54(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip)
{
  (void)regs;
  (void)pid;
  (void)graph;
  (void)symtab;
  (void)eip;
}

static void	slash2_55(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip)
{
  (void)regs;
  (void)pid;
  (void)graph;
  (void)symtab;
  (void)eip;
}

static void	slash2_56(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip)
{
  (void)regs;
  (void)pid;
  (void)graph;
  (void)symtab;
  (void)eip;
}

static void	slash2_57(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip)
{
  (void)regs;
  (void)pid;
  (void)graph;
  (void)symtab;
  (void)eip;
}

static void	slash2_90(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip)
{
  (void)regs;
  (void)pid;
  (void)graph;
  (void)symtab;
  (void)eip;
}

static void	slash2_91(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip)
{
  (void)regs;
  (void)pid;
  (void)graph;
  (void)symtab;
  (void)eip;
}

static void	slash2_92(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip)
{
  (void)regs;
  (void)pid;
  (void)graph;
  (void)symtab;
  (void)eip;
}

static void	slash2_93(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip)
{
  (void)regs;
  (void)pid;
  (void)graph;
  (void)symtab;
  (void)eip;
}

static void	slash2_94(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip)
{
  (void)regs;
  (void)pid;
  (void)graph;
  (void)symtab;
  (void)eip;
}

static void	slash2_95(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip)
{
  (void)regs;
  (void)pid;
  (void)graph;
  (void)symtab;
  (void)eip;
}

static void	slash2_96(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip)
{
  (void)regs;
  (void)pid;
  (void)graph;
  (void)symtab;
  (void)eip;
}

static void	slash2_97(struct user_regs_struct * regs,
			  pid_t pid,
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip)
{
  (void)regs;
  (void)pid;
  (void)graph;
  (void)symtab;
  (void)eip;
}

static void	slash2_d0(struct user_regs_struct * regs,
			  pid_t pid __attribute__((unused)),
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip __attribute__((unused)))
{
  insert_node(graph, symtab, regs->eax, LOCAL_SYM, "");
}

static void	slash2_d1(struct user_regs_struct * regs,
			  pid_t pid __attribute__((unused)),
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip __attribute__((unused)))
{
  insert_node(graph, symtab, regs->ecx, LOCAL_SYM, "");
}

static void	slash2_d2(struct user_regs_struct * regs,
			  pid_t pid __attribute__((unused)),
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip __attribute__((unused)))
{
  insert_node(graph, symtab, regs->edx, LOCAL_SYM, "");
}

static void	slash2_d3(struct user_regs_struct * regs,
			  pid_t pid __attribute__((unused)),
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip __attribute__((unused)))
{
  insert_node(graph, symtab, regs->ebx, LOCAL_SYM, "");
}

static void	slash2_d4(struct user_regs_struct * regs,
			  pid_t pid __attribute__((unused)),
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip __attribute__((unused)))
{
  insert_node(graph, symtab, regs->esp, LOCAL_SYM, "");
}

static void	slash2_d5(struct user_regs_struct * regs,
			  pid_t pid __attribute__((unused)),
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip __attribute__((unused)))
{
  insert_node(graph, symtab, regs->ebp, LOCAL_SYM, "");
}

static void	slash2_d6(struct user_regs_struct * regs,
			  pid_t pid __attribute__((unused)),
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip __attribute__((unused)))
{
  insert_node(graph, symtab, regs->esi, LOCAL_SYM, "");
}

static void	slash2_d7(struct user_regs_struct * regs,
			  pid_t pid __attribute__((unused)),
			  t_symbol_graph * graph,
			  t_symbol_table symtab,
			  union char_disturbed eip __attribute__((unused)))
{
  insert_node(graph, symtab, regs->edi, LOCAL_SYM, "");
}

static t_ff_call	slash2[]=
  {
    {0x10, &slash2_10},
    {0x11, &slash2_11},
    {0x12, &slash2_12},
    {0x13, &slash2_13},
    {0x14, &slash2_14},
    {0x15, &slash2_15},
    {0x16, &slash2_16},
    {0x17, &slash2_17},
    {0x50, &slash2_50},
    {0x51, &slash2_51},
    {0x52, &slash2_52},
    {0x53, &slash2_53},
    {0x54, &slash2_54},
    {0x55, &slash2_55},
    {0x56, &slash2_56},
    {0x57, &slash2_57},
    {0x90, &slash2_90},
    {0x91, &slash2_91},
    {0x92, &slash2_92},
    {0x93, &slash2_93},
    {0x94, &slash2_94},
    {0x95, &slash2_95},
    {0x96, &slash2_96},
    {0x97, &slash2_97},
    {0xd0, &slash2_d0},
    {0xd1, &slash2_d1},
    {0xd2, &slash2_d2},
    {0xd3, &slash2_d3},
    {0xd4, &slash2_d4},
    {0xd5, &slash2_d5},
    {0xd6, &slash2_d6},
    {0xd7, &slash2_d7}
  };

static int	call_ff_slash2(struct user_regs_struct * regs,
			       pid_t pid,
			       t_symbol_graph * graph,
			       t_symbol_table symtab,
			       union char_disturbed eip)
{
  int		i = 0;

  while (i < 32)
    {
      if (eip._disturbed[1] == slash2[i].opcode)
	{
	  slash2[i].fct(regs, pid, graph, symtab, eip);
	  return (1);
	}
      ++i;
    }
  return (0);
}

static void	call_ff_slash3()
{
  
}

void	choose_ff_mgr(struct user_regs_struct * regs,
		      pid_t pid,
		      t_symbol_graph * graph,
		      t_symbol_table symtab,
		      union char_disturbed eip)
{
  if (!call_ff_slash2(regs, pid, graph, symtab, eip))
    call_ff_slash3();
}
