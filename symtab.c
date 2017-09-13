/*
** symtab.c for <FTrace> in /home/barrau_a//c_avancee/ftrace_de_pneu
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jul  1 12:24:43 2011 adrien barrau
** Last update Sun Jul  3 19:09:53 2011 adrien barrau
*/

#include <libelf.h>
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
#include <sys/stat.h>
#include <fcntl.h>
#include "ftrace.h"

void		get_all_sym(t_symbol_table * symtab,
			    Elf32_Shdr * shdr,
			    Elf_Scn * scn,
			    Elf * e)
{
  Elf32_Sym *	syms = NULL;
  Elf_Data *	data = NULL;
  int		nbEntry = shdr->sh_size / shdr->sh_entsize;
  int		i = 0;
  char *	name;
  t_symbol *	new_sym = NULL;

  (void)symtab;  
  if ((data = elf_getdata(scn, data)) == NULL)
    return;
  syms = (Elf32_Sym *) data->d_buf;
  while (i < nbEntry)
    {
      if ((name = elf_strptr(e, shdr->sh_link, syms[i].st_name)) == NULL)
	{ ++i; continue; }
      if (name[0] == 0)
	{ ++i; continue; }
      new_sym = malloc(sizeof(*new_sym));
      new_sym->addr = syms[i].st_value;
      new_sym->name = strdup(name);
      list_push_back(symtab, new_sym);
      ++i;
    }
}

void		fill_symtab(t_symbol_table * symtab, char * file)
{
  Elf *		e;
  int		fd;
  size_t	shstrndx;
  Elf_Scn *	scn = NULL;
  Elf32_Shdr *	shdr = NULL;

  if (elf_version(EV_CURRENT) == EV_NONE)
    { printf(SYMTAB_ERR_MSG); return; }
  if ((fd = open(file, O_RDONLY)) == -1)
    { printf(SYMTAB_ERR_MSG); return; }
  if ((e = elf_begin(fd, ELF_C_READ, NULL)) == NULL)
    { printf(SYMTAB_ERR_MSG); close(fd); return; }
  if (elf_getshdrstrndx(e, &shstrndx) != 0)
    { printf(SYMTAB_ERR_MSG); close(fd); return; }
  while ((scn = elf_nextscn(e, scn)) != NULL)
    {
      if ((shdr = elf32_getshdr(scn)) != NULL
	  && (shdr->sh_type == SHT_SYMTAB
	      || shdr->sh_type == SHT_DYNSYM))
	get_all_sym(symtab, shdr, scn, e);
    }
  printf("ftrace : Symbols table loaded sucessfully\n");
  elf_end(e);
  close(fd);
}

void	free_symtab(t_symbol_table symtab)
{
  (void)symtab;
}
