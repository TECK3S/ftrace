/*
** ftrace.h for <FTrace> in /home/barrau_a//c_avancee/ftrace/includes
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:30:13 2011 adrien barrau
** Last update Sun Jul  3 22:25:19 2011 adrien barrau
*/

#ifndef FTRACE_H_
# define FTRACE_H_

# include "list.h"

# define OPTION_P		("-p")

# define USAGE			("./ftrace [-p PID] | BIN\n")

# define BAD_ARGS_ERR_CODE	(-1)
# define FORK_ERR_CODE		(-2)
# define PTRACE_ERR_CODE	(-3)
# define SYMTAB_ERR_CODE	(-4)

# define FORK_ERR_MSG		("ftrace : Error : Cannot Fork Exiting..\n")
# define PTRACE_ERR_MSG		("ftrace : Error : Ptrace failed\n")
# define SYMTAB_ERR_MSG		("ftrace : Cannot lookup symbols table\n")

# define MAX_SYSCALLS_CHAR	(1024)

# define NUM_SYSCALLS		(337)

# define TOTAL_WIDTH		(38)

# define NB_SIGNALS		(30)
# define NO_SIGNAL		(0)

# define NB_ERRNO		(120)

# define STRSIZE		(32)

# define NB_OPEN_FLAG		(15)
# define NB_OPEN_MODE		(12)
# define NB_MPROT_PROT		(4)
# define NB_MMAP2_PROT		(4)
# define NB_MMAP2_MAP		(13)
# define NB_WAIT_OPT		(3)
# define NB_MKNOD_MODE		(5)
# define NB_WHENCE		(3)
# define NB_MOUNT_FLAG		(15)
# define NB_PTRACE_REQ		(21)
# define NB_ACCESS_MODE		(4)

# define VAR_SING		("[/* %i var */]")
# define VAR_PLU		("[/* %i vars */]")

typedef	t_list	t_symbol_table;

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

typedef struct
{
  unsigned char	opcode;
  void		(*fct)(struct user_regs_struct * regs,
		       pid_t pid,
		       t_symbol_graph * graph,
		       t_symbol_table symtab,
		       union char_disturbed eip);
}		t_ff_call;

typedef struct
{
  int		addr;
  char *	name;
}		t_symbol;

typedef	struct	s_signals
{
  int		num;
  char *	name;
  char *	desc;
}		t_signals;

typedef t_signals t_errno;
typedef t_signals t_open_flags;
typedef t_signals t_open_modes;
typedef t_signals t_mprot_prot;
typedef t_signals t_mmap2_prot;
typedef t_signals t_mmap2_map;
typedef t_signals t_waitpid_option;
typedef t_signals t_mknod_mode;
typedef t_signals t_whence;
typedef t_signals t_mount_flag;
typedef t_signals t_ptrace_req;
typedef t_signals t_access_mode;

/* tracing.c */
int	trace_prog(pid_t pid, t_symbol_graph * graph, t_symbol_table symtab);
int	trace_call(pid_t pid, t_symbol_graph * graph, t_symbol_table symtab);

/* sig_handler.c */
int	handle_sig(int status, t_symbol_graph * graph);
void	are_you_killing_me(int status, t_symbol_graph * graph);

/* syscalls_mgr.c */
int	syscalls_mgr(struct user_regs_struct * regs, pid_t pid, t_symbol_graph * graph);

/* call_mgr.c */
int	call_mgr(struct user_regs_struct * regs, pid_t pid, t_symbol_graph * graph, t_symbol_table symtab);
int	has_returned(struct user_regs_struct * regs, pid_t pid);

/* display_graph.c */
void	display_graph(t_symbol_graph * graph);

/* symtab.c */
void	fill_symtab(t_symbol_table * symtab, char * file);
void	free_symtab(t_symbol_table symtab);

/* get_sym.c */
char *	get_sym_with_addr(int addr, t_symbol_table symtab);

/* call_ff_mgr.c */
void	choose_ff_mgr(struct user_regs_struct * regs,
		      pid_t pid,
		      t_symbol_graph * graph,
		      t_symbol_table symtab,
		      union char_disturbed eip);

/* insert_node.c */
void	insert_node(t_symbol_graph * graph,
		    t_symbol_table symtab,
		    int addr,
		    enum eSymbolType type,
		    char * debug);

/* utilities*.c */
/* 1 */
char *	p_error(int reg, pid_t pid);
char *	p_string(int reg, pid_t pid);
char *	p_open_flag(int reg, pid_t pid);
char *	p_open_mode(int reg, pid_t pid);
char *	p_waitpid_option(int reg, pid_t pid);

/* 2 */
char *	p_argv(int reg, pid_t pid);
char *	p_env(int reg, pid_t pid);
char *	p_mknod_mode(int reg, pid_t pid);
char *	p_seek_whence(int reg, pid_t pid);
char *	p_mount_flags(int reg, pid_t pid);

/* 3 */
char *	p_ptrace_req(int reg, pid_t pid);
char *	p_struct_utime(int reg, pid_t pid);
char *	p_access_mode(int reg, pid_t pid);
char *	p_signal(int reg, pid_t pid);
char *	p_double_int_tab(int reg, pid_t pid);

/* 4 */
char *	p_sighandler(int reg, pid_t pid);
char *	p_umount2_flag(int reg, pid_t pid);
char *	p_ioctl_req(int reg, pid_t pid);
char *	p_fcntl_req(int reg, pid_t pid);
char *	p_mknod_dev(int reg, pid_t pid);

/* 5 */
char *	p_ustat_dev(int reg, pid_t pid);
char *	p_umask_mod(int reg, pid_t pid);
char *	p_struct_array_fd_set(int reg, pid_t pid);
char *	p_struct_array_timeval(int reg, pid_t pid);
char *	p_fchmod_mod(int reg, pid_t pid);

/* 6 */

char * p_struct_array_itimerval(int reg, pid_t pid);
char * p_bind_mode(int reg, pid_t pid);
char * p_bind_flag(int reg, pid_t pid);
char * p_set_mempolicy_flags(int reg, pid_t pid);
char * p_set_mempolicy_mode(int reg, pid_t pid);

/* 7 */

char * p_struct_array_timespec(int reg, pid_t pid);
char * p_struct_array_sigevent(int reg, pid_t pid);
char * p_struct_array_mq_attr(int reg, pid_t pid);
char * p_kexec_load_flag(int reg, pid_t pid);
char * p_mkdir_mode(int reg, pid_t pid);

/* 8 */

char * p_chown_flag(int reg, pid_t pid);
char * p_stat_flag(int reg, pid_t pid);
char * p_link_flag(int reg, pid_t pid);
char * p_chmod_mode(int reg, pid_t pid);
char * p_chmod_flag(int reg, pid_t pid);

/* 9 */

char * p_access_flag(int reg, pid_t pid);
char * p_struct_array_fdset(int reg, pid_t pid);
char * p_struct_array_sigset_t(int reg, pid_t pid);
char * p_struct_array_pollfd(int reg, pid_t pid);
char * p_unshare_flag(int reg, pid_t pid);

/* 10 */

char * p_struct_array_robust_list_head(int reg, pid_t pid);
char * p_splice_flag(int reg, pid_t pid);
char * p_sunc_file_range_flag(int reg, pid_t pid);
char * p_tee_flag(int reg, pid_t pid);
char * p_struct_array_iovec(int reg, pid_t pid);

/* 11 */

char * p_recvmsg_flag(int reg, pid_t pid);
char * p_vmsplice_flag(int reg, pid_t pid);
char * p_move_pages_flag(int reg, pid_t pid);
char * p_struct_array_epoll_event(int reg, pid_t pid);
char * p_utimensat_flag(int reg, pid_t pid);

/* 12 */

char * p_signalfd_flag(int reg, pid_t pid);
char * p_timerfd_create_flag(int reg, pid_t pid);
char * p_eventfd_flag(int reg, pid_t pid);
char * p_timerfd_settime_flag(int reg, pid_t pid);
char * p_struct_array_itimerspec(int reg, pid_t pid);

/* 13 */

char * p_epoll_create1_flag(int reg, pid_t pid);
char * p_dup3_flag(int reg, pid_t pid);
char * p_int_array(int reg, pid_t pid);
char * p_pipe1_flag(int reg, pid_t pid);
char * p_inotify_init1_flag(int reg, pid_t pid);

/* 14 */

char * p_vm86old_struct(int reg, pid_t pid);
char * p_clone_flag(int reg, pid_t pid);
char * p_mprotect_prot(int reg, pid_t pid);
char * p_procmask_how(int reg, pid_t pid);
char * p_quota_cmd(int reg, pid_t pid);

/* 15 */

char * p_nmap_flag(int reg, pid_t pid);
char * p_clock_flag(int reg, pid_t pid);
char * p_mmap2_prot(int reg, pid_t pid);
char * p_mmap2_map(int reg, pid_t pid);

/* --- !utilities*.c --- */

/* syscalls*.c */
/* 1 */
void	tr_restart_syscall(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void	tr_exit(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void	tr_fork(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void	tr_read(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void	tr_write(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 2 */
void  tr_open(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_close(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_waitpid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_creat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_link(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 3 */
void  tr_unlink(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_execve(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_chdir(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_time(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_mknod(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 4 */
void  tr_chmod(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_lchown(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_break(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_oldstat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_lseek(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 5 */
void  tr_getpid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_mount(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_umount(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setuid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getuid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 6 */
void  tr_stime(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_ptrace(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_alarm(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_oldfstat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_pause(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 7 */
void  tr_utime(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_stty(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_gtty(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_access(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_nice(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 8 */
void  tr_ftime(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sync(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_kill(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_rename(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_mkdir(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 9 */
void  tr_rmdir(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_dup(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_pipe(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_times(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_prof(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 10 */
void  tr_brk(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setgid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getgid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_signal(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_geteuid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 11 */
void  tr_getegid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_acct(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_umount2(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_lock(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_ioctl(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 12 */
void  tr_fcntl(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_mpx(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setpgid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_ulimit(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_oldolduname(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 13 */
void  tr_umask(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_chroot(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_ustat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_dup2(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getppid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 14 */
void  tr_getpgrp(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setsid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sigaction(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sgetmask(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_ssetmask(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 15 */
void  tr_setreuid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setregid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sigsuspend(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sigpending(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sethostname(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 16 */
void  tr_setrlimit(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getrlimit(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getrusage(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_gettimeofday(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_settimeofday(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 17 */
void  tr_getgroups(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setgroups(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_select(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_symlink(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_oldlstat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 18 */
void  tr_readlink(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_uselib(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_swapon(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_reboot(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_readdir(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 19 */
void  tr_mmap(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_munmap(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_truncate(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_ftruncate(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_fchmod(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 20 */
void  tr_fchown(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getpriority(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setpriority(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_profil(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_statfs(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 21 */
void  tr_fstatfs(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_ioperm(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_socketcall(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_syslog(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setitimer(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 22 */
void  tr_getitimer(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_stat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_lstat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_fstat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_olduname(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 23 */
void  tr_iopl(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_vhangup(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_idle(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_vm86old(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_wait4(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 24 */
void  tr_swapoff(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sysinfo(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_ipc(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_fsync(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sigreturn(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 25 */
void  tr_clone(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setdomainname(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_uname(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_modify_ldt(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_adjtimex(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 26 */
void  tr_mprotect(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sigprocmask(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_create_module(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_init_module(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_delete_module(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 27 */
void  tr_get_kernel_syms(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_quotactl(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getpgid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_fchdir(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_bdflush(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 28 */
void  tr_sysfs(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_personality(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_afs_syscall(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setfsuid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setfsgid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 29 */
void  tr__llseek(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getdents(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr__newselect(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_flock(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_msync(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 30 */
void  tr_readv(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_writev(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getsid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_fdatasync(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr__sysctl(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 31 */
void  tr_mlock(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_munlock(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_mlockall(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_munlockall(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sched_setparam(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 32 */
void  tr_sched_getparam(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sched_setscheduler(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sched_getscheduler(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sched_yield(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sched_get_priority_max(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 33 */
void  tr_sched_get_priority_min(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sched_rr_get_interval(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_nanosleep(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_mremap(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setresuid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 34 */
void  tr_getresuid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_vm86(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_query_module(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_poll(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_nfsservctl(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 35 */
void  tr_setresgid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getresgid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_prctl(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_rt_sigreturn(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_rt_sigaction(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 36 */
void  tr_rt_sigprocmask(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_rt_sigpending(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_rt_sigtimedwait(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_rt_sigqueueinfo(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_rt_sigsuspend(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 37 */
void  tr_pread64(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_pwrite64(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_chown(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getcwd(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_capget(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 38 */
void  tr_capset(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sigaltstack(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sendfile(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getpmsg(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_putpmsg(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 39 */
void  tr_vfork(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_ugetrlimit(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_mmap2(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_truncate64(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_ftruncate64(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 40 */
void  tr_stat64(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_lstat64(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_fstat64(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_lchown32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getuid32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 41 */
void  tr_getgid32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_geteuid32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getegid32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setreuid32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setregid32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 42 */
void  tr_getgroups32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setgroups32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_fchown32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setresuid32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getresuid32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 43 */
void  tr_setresgid32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getresgid32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_chown32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setuid32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setgid32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 44 */
void  tr_setfsuid32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setfsgid32(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_pivot_root(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_mincore(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_madvise(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 45 */
void  tr_madvise1(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getdents64(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_fcntl64(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_unknown(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_gettid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 46 */
void  tr_readahead(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_setxattr(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_lsetxattr(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_fsetxattr(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getxattr(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 47 */
void  tr_lgetxattr(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_fgetxattr(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_listxattr(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_llistxattr(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_flistxattr(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 48 */
void  tr_removexattr(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_lremovexattr(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_fremovexattr(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_tkill(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sendfile64(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 49 */
void  tr_futex(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sched_setaffinity(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sched_getaffinity(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_set_thread_area(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_get_thread_area(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 50 */
void  tr_io_setup(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_io_destroy(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_io_getevents(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_io_submit(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_io_cancel(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 51 */
void  tr_fadvise64(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_unknown(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_exit_group(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_lookup_dcookie(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_epoll_create(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 52 */
void  tr_epoll_ctl(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_epoll_wait(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_remap_file_pages(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_set_tid_address(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_timer_create(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 53 */
void  tr_timer_settime(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_timer_gettime(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_timer_getoverrun(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_timer_delete(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_clock_settime(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 54 */
void  tr_clock_gettime(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_clock_getres(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_clock_nanosleep(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_statfs64(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_fstatfs64(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 55 */
void  tr_tgkill(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_utimes(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_fadvise64_64(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_vserver(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_mbind(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 56 */
void  tr_get_mempolicy(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_set_mempolicy(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_mq_open(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_mq_unlink(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_mq_timedsend(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 57 */
void  tr_mq_timedreceive(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_mq_notify(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_mq_getsetattr(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_kexec_load(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_waitid(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 58 */
void  tr_unknown(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_add_key(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_request_key(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_keyctl(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_ioprio_set(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 59 */
void  tr_ioprio_get(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_inotify_init(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_inotify_add_watch(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_inotify_rm_watch(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_migrate_pages(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 60 */
void  tr_openat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_mkdirat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_mknodat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_fchownat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_futimesat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 61 */
void  tr_fstatat64(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_unlinkat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_renameat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_linkat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_symlinkat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 62 */
void  tr_readlinkat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_fchmodat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_faccessat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_pselect6(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_ppoll(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 63 */
void  tr_unshare(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_set_robust_list(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_get_robust_list(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_splice(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_sync_file_range(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 64 */
void  tr_tee(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_vmsplice(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_move_pages(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_getcpu(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_epoll_pwait(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 65 */
void  tr_utimensat(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_signalfd(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_timerfd_create(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_eventfd(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_fallocate(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 66 */
void  tr_timerfd_settime(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_timerfd_gettime(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_signalfd4(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_eventfd2(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_epoll_create1(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 67 */
void  tr_dup3(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_pipe2(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_inotify_init1(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_preadv(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_pwritev(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

/* 68 */
void  tr_rt_tgsigqueueinfo(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_perf_event_open(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);
void  tr_recvmsg(struct user_regs_struct * reg, enum mode the_mode, pid_t pid, t_symbol_graph * graph);

#endif /* !FTRACE_H_ */
